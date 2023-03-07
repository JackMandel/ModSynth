#pragma once
#include <JuceHeader.h>
#include "Modules.h"

#define LEVEL_DEFAULT  0.0f
#define PAN_DEFAULT    0.5f
#define MUTE_DEFAULT   0

#define LEVEL_NAME     "level"
#define PAN_NAME       "pan"
#define MUTE_NAME      "mute"

#define SMOOTHING_TIME 0.002 //seconds

class SmartPan : public Module, public AudioProcessorValueTreeState::Listener
{
public:
	SmartPan() 
	{

	};
	~SmartPan() {};


	 
	void prepareToPlay(double sampleRate)  
	{
		leftGain.reset(sampleRate, SMOOTHING_TIME);
		rightGain.reset(sampleRate, SMOOTHING_TIME);
		monoGain.reset(sampleRate, SMOOTHING_TIME);

		updateState();
	};

	void processBlock(AudioBuffer<float>& buffer, int inCh, int outCh)
	{

		auto numSamples = buffer.getNumSamples();
		//mono IN - stereo OUT 

		if (inCh < outCh) // 1 < 2
		{
			buffer.copyFrom(1, 0, buffer, 0, 0, numSamples);

		};

		//mono IN - mono OUT

		if (inCh + outCh == 2)
		{
			monoGain.applyGain(buffer, numSamples);

		}

		else					//stereo IN - stereo OUT || mono IN - stereo OUT (|| stereo IN - mono OUT)
		{
			//buffer.applyGain(0, 0, numSamples, leftGain);		NO SMOOTHING
			//buffer.applyGain(1, 0, numSamples, rightGain);

			leftGain.applyGain(buffer.getWritePointer(0), numSamples);
			rightGain.applyGain(buffer.getWritePointer(1), numSamples);

		}
		//stereo IN - mono OUT

		if (inCh > outCh)
			buffer.addFrom(0, 0, buffer, 1, 0, numSamples);

	};

	void parameterChanged(const String& paramID, float newValue) override
	{
		if (paramID == LEVEL_NAME )
			gain = Decibels::decibelsToGain(newValue);

		if (paramID == PAN_NAME)
			pan = newValue;

		if (paramID == MUTE_NAME)
			active = newValue < 0.5f; // se newvalue < 0.5f allora active = true

		updateState();
	};

private:

	void updateState()
	{
		auto l  = active * gain;
		monoGain.setTargetValue(l);

		leftGain.setTargetValue(l * sqrt(1.0f - pan));
		rightGain.setTargetValue(l * sqrt(pan));
	};

	bool active = 1.0f - MUTE_DEFAULT;
	float gain  = Decibels::decibelsToGain(LEVEL_DEFAULT);
	float pan   = PAN_DEFAULT;										//va da 0 a +1, 0.5 è in mezzo

	SmoothedValue<float, ValueSmoothingTypes::Linear> leftGain  = 0.0f;
	SmoothedValue<float, ValueSmoothingTypes::Linear> rightGain = 0.0f;
	SmoothedValue<float, ValueSmoothingTypes::Linear> monoGain  = 0.0f;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SmartPan)
};  
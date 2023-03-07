#pragma once
#include <JuceHeader.h> 
#include "Modules.h"


#define NAME_NLVL     "noiseL"
#define DEFAULT_NLVL  -10.0f

class VCO : public Module, public AudioProcessorValueTreeState::Listener
{
public:

    VCO();
    ~VCO();


    void prepareToPlay(double sr, int maxNumSamples) override;

    void processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages);
    void releaseResources() override;
    void parameterChanged(const String& paramID, float newValue);


private:

    Random noise;

    float noiseLevel = Decibels::decibelsToGain(DEFAULT_NLVL);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VCO)
};

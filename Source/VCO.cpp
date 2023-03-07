#include "VCO.h"

VCO::VCO()
{

};

VCO::~VCO()
{

};

void VCO::prepareToPlay(double sr, int maxNumSamples)
{
	sampleRate = sr;
	envelope.setSize(1, maxNumSamples);

}

void VCO::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	const auto numSamples = buffer.getNumSamples();
	const auto numChannels = buffer.getNumChannels();
	float* const* bufferData = buffer.getArrayOfWritePointers();
	const float* envData = envelope.getReadPointer(0);


	// ||||||||||||||||
	for (int ch = 0; ch < numChannels; ++ch)
		for (int smp = 0; smp < numSamples; ++smp)
		{
			bufferData[ch][smp] += ((noise.nextFloat() * 2.0f) - 1.0f) * noiseLevel; //riempie il buffer di campioni per ogni canale

		}
	envelope.clear();
}

void VCO::parameterChanged(const String& paramID, float newValue)
{
	if (paramID == NAME_NLVL)
		noiseLevel = Decibels::decibelsToGain(newValue);
};

void VCO::releaseResources()
{
	envelope.setSize(0, 0);
}

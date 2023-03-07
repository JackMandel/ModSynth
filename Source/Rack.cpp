#include "Rack.h"

Rack::Rack() {
}

Rack::~Rack() {
}

void Rack::prepareToPlay(double sr, int maxNumSamples)
{
	sampleRate = sr;

	vco.prepareToPlay(sampleRate, maxNumSamples);
	panner.prepareToPlay(sampleRate);

}

void Rack::processBlock(AudioBuffer<float>& inputBuffer, MidiBuffer& midiMessages, int inCh, int outCh)
{
	const int numSamples = inputBuffer.getNumSamples();
	const int numChannels = inputBuffer.getNumChannels();
	auto totalNumInputChannels = inCh;
	auto totalNumOutputChannels = outCh;

	vco.processBlock(inputBuffer, midiMessages);
	panner.processBlock(inputBuffer, totalNumInputChannels, totalNumOutputChannels);


}

void Rack::releaseResources() 
{
	vco.releaseResources();
}

void Rack::Connect(AudioBuffer<float>& outputToConnect, AudioBuffer<float>& inputToConnect) 
{
	const auto numSamples = outputToConnect.getNumSamples();
	const auto numChannels = outputToConnect.getNumChannels();

	for (int ch = 0; ch < numChannels; ++ch)
		for (int smp = 0; smp < numSamples; ++smp)
			inputToConnect.copyFrom(ch, smp, outputToConnect, ch, smp, numSamples);
}

void Rack::Sort() {		//implementare l'algoritmo di Khan, con alert nel caso di loop

}


void Rack::Swap() {

}

void Rack::GetModuleInputs(Module mdl, int j) {
//	return mdl[j];
}

void Rack::GetModuleOutputs(Module mdl, int j) {

}
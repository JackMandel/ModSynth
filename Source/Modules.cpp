#include "Modules.h"

Module::Module() {
	/*
		int numOutputBuffers = 1;		//componente statica dei moduli (ogni modulo definirà i suoi buffer di input ed output)
		buffers.resize(numOutputBuffers);

		for (int i = 0; i < numOutputBuffers; i++) {
			buffers[i].resize(1024);  //allocazione di bytes... non mi ispira
		}
	*/
}

Module::~Module() {

}

void Module::prepareToPlay(double sr, int maxNumSamples)
{
	sampleRate = sr;
	envelope.setSize(1, maxNumSamples);

}

void Module::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	const auto numSamples = buffer.getNumSamples();
	const auto numChannels = buffer.getNumChannels();
	float* const* bufferData = buffer.getArrayOfWritePointers();
	const float* envData = envelope.getReadPointer(0);


	envelope.clear();
}


void Module::releaseResources() 
{
	envelope.setSize(0, 0);
}
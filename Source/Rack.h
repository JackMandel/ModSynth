#pragma once
#include <JuceHeader.h> 
#include "VCO.h"
#include "SmartPan.h"

using std::vector;

class Rack{
public:

    Rack();
    ~Rack();

    void prepareToPlay(double sr, int maxNumSamples);
    void processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages, int inCh, int outCh);
    void releaseResources();

    VCO vco;
    SmartPan panner;

private:
    AudioBuffer<float> transmitter;

    float* const* sostegno;

    void Connect(AudioBuffer<float>& outputToConnect, AudioBuffer<float>& inputToConnect);
    void Sort();
    void Swap();
    void GetModuleInputs(Module mdl, int j);
    void GetModuleOutputs(Module mdl, int j);


    void addModule(Module* mdl) {
    }

    void process() {
    }

    vector<vector<Module>> INs;             //vector bidimensionale che contiene i moduli e ciascun loro input.
    vector<vector<Module>> OUTs;            //vector bidimensionale che contiene i moduli e ciascun loro output.

    double sampleRate = 1.0;

    int inputs = 0;
    int outputs = 0;
    int totInputs = 0;
    int totOutputs = 0;


};

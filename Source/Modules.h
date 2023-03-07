#pragma once
#include <JuceHeader.h> 


//#define NAME_NLVL     "noiseL"
//#define DEFAULT_NLVL  -10.0f

using std::vector;

class Module {


public:
    Module();
    ~Module();

    virtual void prepareToPlay(double sr, int maxNumSamples);
    void processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages);
    virtual void releaseResources(); 

    double sampleRate = 1.0;
    //   vector<AudioBuffer<float>> INbuffers;
    //   vector<AudioBuffer<float>> OUTbuffers;

    AudioBuffer<float> envelope;

    AudioBuffer<float> input;
    AudioBuffer<float> output;
private:


    //Random noise;
    //float noiseLevel = Decibels::decibelsToGain(DEFAULT_NLVL);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Module)

};
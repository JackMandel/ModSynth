#pragma once
#include <JuceHeader.h>
#include "Rack.h"
#include "SmartPan.h"
#include "VCO.h"

class ModSynthAudioProcessor  : public juce::AudioProcessor, public AudioProcessorValueTreeState::Listener 
{
public:
    //==============================================================================
    ModSynthAudioProcessor();
    ~ModSynthAudioProcessor() override {};

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    void parameterChanged(const String& paramID, float newValue) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; };

    //==============================================================================
    const juce::String getName() const override { return JucePlugin_Name; };

    bool acceptsMidi() const override { return true; };
    bool producesMidi() const override { return false; };
    bool isMidiEffect() const override { return false; };
    double getTailLengthSeconds() const override { return 0.0; };

    int getNumPrograms() override { return 1; };
    int getCurrentProgram() override { return 0; };
    void setCurrentProgram(int index) override {};
    const juce::String getProgramName(int index) override { return {}; };
    void changeProgramName(int index, const juce::String& newName) override {};

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;


private:

    AudioProcessorValueTreeState parameters;

    Rack rack;


    //VCO vco;
    //SmartPan panner;


    //float linearGainValue= 1.0;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModSynthAudioProcessor)
};
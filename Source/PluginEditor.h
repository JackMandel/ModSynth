#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment; //definizione per poter scrivere solo SliderAttachment

class ModSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ModSynthAudioProcessorEditor (ModSynthAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~ModSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    ModSynthAudioProcessor& audioProcessor;
    AudioProcessorValueTreeState& parameters;

//    Slider volumeSlider;
//    std::unique_ptr<SliderAttachment> volumeAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModSynthAudioProcessorEditor)
};

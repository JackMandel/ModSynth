/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PatchBay.h"


typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment; //definizione per poter scrivere solo SliderAttachment
typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment; //definizione per poter scrivere solo ButtonAttachment
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditorGUI  : public juce::AudioProcessorEditor
{
public:
    //==============================================================================
    PluginEditorGUI (ModSynthAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~PluginEditorGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ModSynthAudioProcessor& audioProcessor;
    AudioProcessorValueTreeState& parameters;

    std::unique_ptr<SliderAttachment> volumeAttachment;
    std::unique_ptr<SliderAttachment> volumeAttachment2;
    std::unique_ptr<SliderAttachment> panAttachment;
    std::unique_ptr<ButtonAttachment> muteAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> vcoGroupComponent;
    std::unique_ptr<juce::Slider> gainSlider;
    std::unique_ptr<juce::Slider> panSlider;
    std::unique_ptr<juce::ToggleButton> muteButton;
    std::unique_ptr<juce::GroupComponent> mixerGroupComponent;
    std::unique_ptr<PatchBay> patchbayComponent;
    std::unique_ptr<juce::Slider> gainSlider2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditorGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]


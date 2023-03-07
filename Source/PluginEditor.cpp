#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
ModSynthAudioProcessorEditor::ModSynthAudioProcessorEditor(ModSynthAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), audioProcessor(p), parameters(vts)
{

  //  volumeSlider.setSliderStyle(Slider::LinearVertical);
  //  volumeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);

  //  addAndMakeVisible(volumeSlider);

  //  volumeAttachment.reset(new SliderAttachment(parameters, "gain", volumeSlider));

    setSize (400, 300);
}

ModSynthAudioProcessorEditor::~ModSynthAudioProcessorEditor()
{
}

//==============================================================================
void ModSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void ModSynthAudioProcessorEditor::resized()
{
 //   volumeSlider.setBounds(40, 30, 50, getHeight() - 60);
}

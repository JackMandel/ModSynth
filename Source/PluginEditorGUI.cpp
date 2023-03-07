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

//[Headers] You can add your own extra header files here...
#include"PluginProcessor.h"
//[/Headers]

#include "PluginEditorGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditorGUI::PluginEditorGUI (ModSynthAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), audioProcessor(p), parameters(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    vcoGroupComponent.reset (new juce::GroupComponent ("VCOGroup",
                                                       TRANS("VCO")));
    addAndMakeVisible (vcoGroupComponent.get());

    vcoGroupComponent->setBounds (0, 8, 168, 320);

    gainSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (gainSlider.get());
    gainSlider->setRange (0, 10, 0);
    gainSlider->setSliderStyle (juce::Slider::LinearVertical);
    gainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    gainSlider->setBounds (8, 32, 150, 208);

    panSlider.reset (new juce::Slider ("Panpot"));
    addAndMakeVisible (panSlider.get());
    panSlider->setRange (0, 10, 0);
    panSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    panSlider->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 80, 20);

    panSlider->setBounds (8, 248, 150, 32);

    muteButton.reset (new juce::ToggleButton ("Mute"));
    addAndMakeVisible (muteButton.get());

    muteButton->setBounds (88, 40, 72, 24);

    mixerGroupComponent.reset (new juce::GroupComponent ("mixerGroup",
                                                         TRANS("Mixer")));
    addAndMakeVisible (mixerGroupComponent.get());

    mixerGroupComponent->setBounds (200, 8, 168, 320);

    patchbayComponent.reset (new PatchBay());
    addAndMakeVisible (patchbayComponent.get());
    patchbayComponent->setName ("PatchBay");

    patchbayComponent->setBounds (544, 24, 454, 304);

    gainSlider2.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (gainSlider2.get());
    gainSlider2->setRange (0, 10, 0);
    gainSlider2->setSliderStyle (juce::Slider::LinearVertical);
    gainSlider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    gainSlider2->setBounds (208, 32, 150, 208);


    //[UserPreSize]
    volumeAttachment.reset(new SliderAttachment(parameters, LEVEL_NAME, *gainSlider));      //abbiamo puntatori perchè vanno deferenziati,
    panAttachment.reset(new SliderAttachment(parameters, PAN_NAME, *panSlider));          //rispetto a prima cambia il modo in cui li dichiariamo
    muteAttachment.reset(new ButtonAttachment(parameters, MUTE_NAME, *muteButton));
    volumeAttachment2.reset(new SliderAttachment(parameters, NAME_NLVL , *gainSlider2));
    //[/UserPreSize]

    setSize (1000, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditorGUI::~PluginEditorGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    volumeAttachment = nullptr;
    volumeAttachment2 = nullptr;
    panAttachment = nullptr;
    muteAttachment = nullptr;

    //[/Destructor_pre]

    vcoGroupComponent = nullptr;
    gainSlider = nullptr;
    panSlider = nullptr;
    muteButton = nullptr;
    mixerGroupComponent = nullptr;
    patchbayComponent = nullptr;
    gainSlider2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditorGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditorGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditorGUI" componentName=""
                 parentClasses="public juce::AudioProcessorEditor" constructorParams="ModSynthAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor(&amp;p), audioProcessor(p), parameters(vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1000" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="VCOGroup" id="2352aa28ee09bf95" memberName="vcoGroupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 8 168 320" title="VCO"/>
  <SLIDER name="Gain" id="4b848ba0a2b3d6" memberName="gainSlider" virtualName=""
          explicitFocusOrder="0" pos="8 32 150 208" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
  <SLIDER name="Panpot" id="3c48c8f9a3ca745" memberName="panSlider" virtualName=""
          explicitFocusOrder="0" pos="8 248 150 32" min="0.0" max="10.0"
          int="0.0" style="LinearHorizontal" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <TOGGLEBUTTON name="Mute" id="aa9e2bfe8d73a0b2" memberName="muteButton" virtualName=""
                explicitFocusOrder="0" pos="88 40 72 24" buttonText="Mute" connectedEdges="0"
                needsCallback="0" radioGroupId="0" state="0"/>
  <GROUPCOMPONENT name="mixerGroup" id="c3e5e247d761b275" memberName="mixerGroupComponent"
                  virtualName="" explicitFocusOrder="0" pos="200 8 168 320" title="Mixer"/>
  <GENERICCOMPONENT name="PatchBay" id="ebc6933ca057b297" memberName="patchbayComponent"
                    virtualName="" explicitFocusOrder="0" pos="544 24 454 304" class="PatchBay"
                    params=""/>
  <SLIDER name="Gain" id="16c3c128aa9a3346" memberName="gainSlider2" virtualName=""
          explicitFocusOrder="0" pos="208 32 150 208" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]


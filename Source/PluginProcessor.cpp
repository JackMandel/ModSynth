#include "PluginProcessor.h"
//#include "PluginEditor.h"
#include "PluginEditorGUI.h"


//==============================================================================
ModSynthAudioProcessor::ModSynthAudioProcessor()
    : AudioProcessor(BusesProperties()

            .withInput("Input", juce::AudioChannelSet::stereo(), true)
            .withOutput("Output", juce::AudioChannelSet::stereo(), true)

        ),
      parameters(*this, nullptr, "MDSParameters", {
      //std::make_unique<AudioParameterFloat>("gain", "Gain", -48.0f, 3.0f, 0.0f),
      std::make_unique<AudioParameterFloat>(NAME_NLVL, "Gain", -48.0f, 3.0f,DEFAULT_NLVL),
      std::make_unique<AudioParameterFloat>(LEVEL_NAME, "Gain2", -48.0f, 3.0f,LEVEL_DEFAULT),
      std::make_unique<AudioParameterFloat>(PAN_NAME, "Pan", 0.0f, 1.0f, PAN_DEFAULT),
      std::make_unique<AudioParameterBool>(MUTE_NAME, "Mute", MUTE_DEFAULT)
        })
{
     // parameters.addParameterListener("gain", this);
      parameters.addParameterListener(NAME_NLVL, &rack.vco);
      parameters.addParameterListener(LEVEL_NAME, &rack.panner);
      parameters.addParameterListener(PAN_NAME, &rack.panner);
      parameters.addParameterListener(MUTE_NAME, &rack.panner);
}

void ModSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    rack.prepareToPlay(sampleRate, samplesPerBlock);
}

void ModSynthAudioProcessor::releaseResources()
{
    rack.releaseResources();
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ModSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{

    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    return true;

}
#endif

void ModSynthAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }


 //   vco.processBlock(buffer, midiMessages);
 //   buffer.applyGain(linearGainValue);
 //   panner.processBlock(buffer, totalNumInputChannels, totalNumOutputChannels);

    rack.processBlock(buffer, midiMessages, totalNumInputChannels, totalNumOutputChannels);


    
}

void ModSynthAudioProcessor::parameterChanged(const String& paramID, float newValue)
{
 //   if(paramID == "gain")
   // linearGainValue = Decibels::decibelsToGain(newValue);
};

//==============================================================================

juce::AudioProcessorEditor* ModSynthAudioProcessor::createEditor()
{
    //return new ModSynthAudioProcessorEditor (*this, parameters);
    return new PluginEditorGUI(*this, parameters);
}

//==============================================================================
void ModSynthAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void ModSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ModSynthAudioProcessor();
}

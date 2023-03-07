/*
La patchbay avrà dei "togglable" knob posizionati su ogni corrispondenza INs-OUTs, i quali indicano un eventuale gain da applicare in post-connection.
ogni corrispondenza dovrà avere già agganciato l'output di un modulo e l'input di un altro modulo che,
preso l'output, lo processa e lo manda a sua volta nel proprio output.

quando il knob è disabled, il segnale non viene passato dall'OUT all'IN, quando viene enabled invece sì.


*/
#pragma once

#include <JuceHeader.h>

class PatchBay : public Component
{
public:
	PatchBay() {};
	~PatchBay() {};

	void paint(Graphics& g) override 
	{
		auto W = getWidth();
		auto H = getHeight();
		g.fillAll(Colours::black);
		g.setColour(Colours::grey);
		g.drawRect(0, 0, W, H, 1); // 0, 0 è in alto a sx, il primo pixel
		
	};

	void mouseDown(const MouseEvent& event) override 
	{
//		juce::Component* connector = event.eventComponent;
//		if (connector == )
//			connectTo(connector, );
	};

	void resized() override
	{
	
	};

	void connectTo(juce::Component& targetInput, juce::AudioBuffer<float>& targetOutput)
	{
//		source = &targetInput;
//		targetOutput = targetInput;
	};


private:

	juce::AudioBuffer<float>* source = nullptr;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PatchBay)
};

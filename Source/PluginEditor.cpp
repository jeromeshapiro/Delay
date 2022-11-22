/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayAudioProcessorEditor::DelayAudioProcessorEditor (DelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), feedback(Slider::Vertical), mix(Slider::Vertical), gain(Slider::Rotary)
{
    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.state, "GAIN", gain);
    
    addAndMakeVisible(feedback);
//    addAndMakeVisible(mix);
    addAndMakeVisible(gain);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 500);
}

DelayAudioProcessorEditor::~DelayAudioProcessorEditor()
{
}

//==============================================================================
void DelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void DelayAudioProcessorEditor::resized()
{
    feedback.setBounds(0, 100, 150, 150);
    mix.setBounds(150, 100, 150, 150);
    
    gain.setSize(100, 100);
    
//    auto r = getLocalBounds();
//    gain.setBounds(r);
}

/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class Slider : public juce::Slider
{
public:
    enum SliderStyle
    {
        Vertical,
        Rotary
    };
    
    Slider(SliderStyle style)
    {
        switch (style) {
            case Vertical:
                this->setSliderStyle(juce::Slider::LinearVertical);
                break;
                
            case Rotary:
                this->setSliderStyle(juce::Slider::RotaryVerticalDrag);
                break;
        }

        this->setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 15);
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Slider)
};

//==============================================================================
/**
*/
class DelayAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DelayAudioProcessorEditor (DelayAudioProcessor&);
    ~DelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DelayAudioProcessor& audioProcessor;
    
    juce::Rectangle<int> header;
    
    Slider feedback;
    Slider mix;
    Slider gain;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayAudioProcessorEditor)
};

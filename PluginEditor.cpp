/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
cRudeBoiAudioProcessorEditor::cRudeBoiAudioProcessorEditor (cRudeBoiAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible(volSlider = new Slider("Volume"));
    volSlider->setSliderStyle(Slider::Rotary);
    volSlider->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    
    volAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volSlider);
    
    volSlider->setLookAndFeel(&paintVolume);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);
}

cRudeBoiAudioProcessorEditor::~cRudeBoiAudioProcessorEditor()
{
}

//==============================================================================
void cRudeBoiAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::rebeccapurple);
    g.setColour (Colours::orange);
    Font AmpFont("Hobo Std", "regular", 30.0f);
    g.setFont (AmpFont);
    g.drawFittedText ("BOOTLEG WOODSTOCK FUZZ", getLocalBounds(), Justification::centredTop, 1);
    g.drawText("Vol", (((getWidth() / 5) * 2.5) - (100 / 2)), (getHeight() / 2) + 5, 100, 100, Justification::centred);
}

void cRudeBoiAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    volSlider->setBounds((((getWidth() / 5) * 2.5) - (100 / 2)), (getHeight() / 2) - (100 / 2), 100, 100);
}

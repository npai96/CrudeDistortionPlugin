/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
 */
/* GUI Component */
class VolumeDesign : public LookAndFeel_V4
{
public:
    VolumeDesign()
    {
        setColour(Slider::rotarySliderOutlineColourId, Colours::silver);
        setColour(Slider::rotarySliderFillColourId, Colours::darkorange);
        setColour(Slider::thumbColourId, Colours::whitesmoke);
    }
};

/* AudioProcessor Component */
class cRudeBoiAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    cRudeBoiAudioProcessorEditor (cRudeBoiAudioProcessor&);
    ~cRudeBoiAudioProcessorEditor();
    
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
private:
    
    /* Pointers to Sliders represent each knob in GUI.
     * ScopedPointers are pointers that are deallocated once the pointer exits scope.
     * Memory management is extremely important in audio processing as sound files
     * create audio callbacks called every 41.4kHz, audio callbacks need to be produced
     * to provide audio buffers on time (otherwise you get annoying buzzes)
     */
    ScopedPointer<Slider> volSlider;
    
    /* ValueTreeStates store parameter values, can save, store, and manage presets,
     * allow these to be shared between classes
     */
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volAttachment;
    
    /* GUI Components */
    VolumeDesign paintVolume;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    cRudeBoiAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (cRudeBoiAudioProcessorEditor)
};

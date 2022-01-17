/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class _04_JucePluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    _04_JucePluginAudioProcessorEditor (_04_JucePluginAudioProcessor&);
    ~_04_JucePluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    _04_JucePluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_04_JucePluginAudioProcessorEditor)
};

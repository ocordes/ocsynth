/*
  ==============================================================================

    SynthSound.h
    Created: 13 Aug 2023 2:44:10pm
    Author:  Oliver Cordes

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber) override { return true; }
    bool appliesToChannel (int midiChannel) override { return true; }

};

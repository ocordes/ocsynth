/*
  ==============================================================================

    OscData.h
    Created: 13 Aug 2023 3:19:55pm
    Author:  Oliver Cordes

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

template <typename Type>
class OscData
{
public:
    OscData ();

    void setFrequency (float newValue, bool force = false);
    void setLevel (float newValue);
    void setType (const int oscSelection);
    
    void prepare (const juce::dsp::ProcessSpec& spec);
    
    template <typename ProcessContext>
    void process (const ProcessContext& context) noexcept
    {
        processorChain.process (context);
    }
    void reset() noexcept;
    
    enum
    {
        oscIndex,
        gainIndex 
    };

    juce::dsp::ProcessorChain<juce::dsp::Oscillator<float>, juce::dsp::Gain<float>> processorChain;
private:
};

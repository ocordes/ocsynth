/*
  ==============================================================================

    OscData.cpp
    Created: 13 Aug 2023 3:19:55pm
    Author:  Oliver Cordes

  ==============================================================================
*/

#include "OscData.h"


template <typename Type>
OscData<Type>::OscData ()
{
    setType (0);
}


template <typename Type>
void OscData<Type>::setFrequency (float newValue, bool force)
{
    auto& osc = processorChain.template get<oscIndex>();
    osc.setFrequency (newValue, force);
}


template <typename Type>
void OscData<Type>::setLevel (float newValue)
{
    auto& gain = processorChain.template get<gainIndex>();
    gain.setGainLinear (newValue);
}


template <typename Type>
void OscData<Type>::setType (const int oscSelection)
{
    auto& osc = processorChain.template get<oscIndex>();
    
    switch (oscSelection)
    {
        // Sine
        case 0:
            osc.initialise ([](float x) { return std::sin (x); });
            break;

        // Saw
        case 1:
            osc.initialise ([] (float x) { return x / juce::MathConstants<float>::pi; });
            break;

        // Square
        case 2:
            osc.initialise ([] (float x) { return x < 0.0f ? -1.0f : 1.0f; });
            break;

        // Triangle
        case 3:
            osc.initialise ([](float x) { return abs(x / juce::MathConstants<float>::pi); } );
            break;

        default:
            // You shouldn't be here!
            jassertfalse;
            break;
    }
}


template <typename Type>
void OscData<Type>::prepare (const juce::dsp::ProcessSpec& spec)
{
    
}


template <typename Type>
void OscData<Type>::reset() noexcept
{
    processorChain.reset();
}

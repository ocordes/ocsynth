/*
  ==============================================================================

    SynthVoice.cpp
    Created: 13 Aug 2023 2:43:54pm
    Author:  Oliver Cordes

  ==============================================================================
*/

#include "SynthVoice.h"


#include "SynthVoice.h"

bool SynthVoice::canPlaySound (juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}


void SynthVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition)
{
    
}


void SynthVoice::stopNote (float velocity, bool allowTailOff)
{
    
}


void SynthVoice::controllerMoved (int controllerNumber, int newControllerValue)
{
    
}


void SynthVoice::pitchWheelMoved (int newPitchWheelValue)
{
    
}


void SynthVoice::prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels)
{
    juce::String message;
    message << "INFO(SynthVoice):p reparing to play audio...\n";
    message << " samplesPerBlock = " << samplesPerBlock << "\n";
    message << " sampleRate      = " << sampleRate;
    juce::Logger::getCurrentLogger()->writeToLog (message);
    
    
}


void SynthVoice::renderNextBlock (juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples)
{
    
}

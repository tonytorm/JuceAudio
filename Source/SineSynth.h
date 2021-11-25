/*
  ==============================================================================

    SineSynth.h
    Created: 25 Nov 2021 1:15:35pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "audio/Audio.h"

class SineSynth
{
public:
    SineSynth();
    ~SineSynth();
    float nextSample();
    void setFrequency(float);
    void setGain(float);
private:
    
};


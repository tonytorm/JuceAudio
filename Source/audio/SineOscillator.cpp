//
//  SineOscillator.cpp
//  JuceAudio - App
//
//  Created by Giulio Iacomino on 25/11/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "SineOscillator.hpp"







float SineOscillator::nextSample()
{
    phasePosition += phaseIncrement.load();
          
    if (phasePosition > MathConstants<float>::twoPi)
        phasePosition -= MathConstants<float>::twoPi;
    
    float sineOut = std::sin(phasePosition);
    
    return sineOut;
}


void SineOscillator::handlePhaseIncrement(float noteinhertz)
{
    phaseIncrement = (MathConstants<float>::twoPi * noteinhertz) / sampleRate;
}


void SineOscillator::setGain(float gainControl)
{
     gainS = gainControl;
}

std::atomic<float> SineOscillator::getGain()
{
    return gainS.load();
}

void SineOscillator::getSampleRate(float samplerate)
{
    sampleRate = samplerate;
}


//
//  SineOscillator.hpp
//  JuceAudio - App
//
//  Created by Giulio Iacomino on 25/11/2021.
//  Copyright © 2021 UWE. All rights reserved.
//


#pragma once
#include <JuceHeader.h>


class SineOscillator
{
public:
   
    float nextSample();
    void setFrequency(float);
    void setGain(float);
    std::atomic<float> getGain();
    void handlePhaseIncrement(float);
    void getSampleRate(float);
    
private:
    std::atomic<float> gainS;
    std::atomic<float> sampleRate = 44100.f;
    std::atomic<float> phaseIncrement = 0.f;
    float phasePosition = 0.f;
    
    float noteInHertz;
};

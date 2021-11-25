/*
  ==============================================================================

    Audio.cpp
    Author:  Tom Mitchell

  ==============================================================================
*/

#include "Audio.h"


Audio::Audio()
{
    auto midiInputDevices = MidiInput::getAvailableDevices();
    
   
    if (midiInputDevices.size() > 0)
        audioDeviceManager.setMidiInputDeviceEnabled (midiInputDevices[2].identifier, true);
    audioDeviceManager.addMidiInputCallback ("", this);
    
    auto errorMessage = audioDeviceManager.initialiseWithDefaultDevices (1, 2);
    if ( ! errorMessage.isEmpty())
        DBG (errorMessage);
    audioDeviceManager.addAudioCallback (this);
    gainS = 0;
    noteInHertz = 0;
}

Audio::~Audio()
{
    audioDeviceManager.removeAudioCallback (this);
    audioDeviceManager.removeMidiInputCallback ("", this);
}


void Audio::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
    //All MIDI inputs arrive here
    
    noteInHertz = MidiMessage::getMidiNoteInHertz(message.getNoteNumber());

}

void Audio::audioDeviceIOCallback (const float** inputChannelData,
                                           int numInputChannels,
                                           float** outputChannelData,
                                           int numOutputChannels,
                                           int numSamples)
{
    //All audio processing is done here
    const float* inL = inputChannelData[0];
    
    phaseIncrement = (MathConstants<float>::twoPi * noteInHertz) / sampleRate;

    float *outL = outputChannelData[0];
    float *outR = outputChannelData[1];
    
    while(numSamples--)
    {
        
        phasePosition += phaseIncrement.load();
        
        if (phasePosition > MathConstants<float>::twoPi)
            phasePosition -= MathConstants<float>::twoPi;
        
        sineOut = std::sin(phasePosition);
        
        //auto output = *inL;
        *outL = sineOut * gainS;
        *outR = sineOut * gainS;
        
        inL++;
        outL++;
        outR++;
    }
    
}


void Audio::audioDeviceAboutToStart (AudioIODevice* device)
{
    sampleRate = device->getCurrentSampleRate();
    
}

void Audio::audioDeviceStopped()
{

}

void Audio::setGain(float gainControl)
{
     gainS = gainControl;
}

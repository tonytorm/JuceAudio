//
//  Counter.hpp
//  JuceAudio - App
//
//  Created by Giulio Iacomino on 25/11/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>



class Counter : public Thread
{
public:
    //nested class
    class Listener
    {
    public:
        virtual ~Listener() {};
        virtual void counterChanged(unsigned int counterValue) = 0;
    };
    
    
    
    Counter();
    void startCounter();
    void stopCounter( int milliseconds);
    void run() override;
    void setListener(Listener* newListener);
    
    
    
private:
    Listener* listener = nullptr;
};

//
//  Counter.cpp
//  JuceAudio - App
//
//  Created by Giulio Iacomino on 25/11/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#include "Counter.hpp"

Counter::Counter() : Thread("CThread")
{
    
}

void Counter::startCounter()
{
    startThread();
}

void Counter::stopCounter(int milliseconds)
{
    stopThread(milliseconds);
}

void Counter::run()
{
    int count = 0;
    
    while (! threadShouldExit())
    {
        if (listener != nullptr)
            listener->counterChanged(count);
        count++;
        wait(100);
    }
}

void Counter::setListener(Listener *newListener)
{
    listener = newListener;
}

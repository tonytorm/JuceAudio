/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../audio/Audio.h"
#include "Counter.hpp"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component,
                        public MenuBarModel,
                        public Slider::Listener,
                        public Button::Listener,
                        public Counter::Listener
                        
{
public:
    //==============================================================================
    /** Constructor */
    MainComponent (Audio& a);

    /** Destructor */
    ~MainComponent();

    //Comoponent====================================================================
    void resized() override;
    void paint (Graphics&) override;
    void sliderValueChanged(Slider* slider) override;
    void buttonClicked (Button* button) override;
    void counterChanged (unsigned int count) override;
    
    //MenuBarEnums/MenuBarModel=====================================================
    enum Menus
    {
        FileMenu = 0,
        NumMenus
    };
    
    enum FileMenuItems
    {
        AudioPrefs = 1,
        NumFileItems
    };
    
    enum ButtonState
    {
        sleeping,
        active
    };
    
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex (int topLevelMenuIndex, const String& menuName) override;
    void menuItemSelected (int menuItemID, int topLevelMenuIndex) override;
    
private:
    Audio& audio;
    Slider gainSlider;
    TextButton butthread;
    ButtonState state;
    Counter counterA;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

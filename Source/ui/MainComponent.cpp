/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent (Audio& a) : audio (a)
{
    setSize (600, 400);
    addAndMakeVisible(gainSlider);
    gainSlider.setBounds(120, 30, 110, 30);
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearBar);
    gainSlider.addListener(this);
    
    
    addAndMakeVisible(butthread);
    butthread.setBounds(250, 30, 110, 30);
    butthread.addListener(this);
    
    
    state = sleeping;
    counterA.setListener(this);
    
}

MainComponent::~MainComponent()
{
    
}

//==============================================================================
void MainComponent::resized()
{

}
void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

//MenuBarCallbacks==============================================================
StringArray MainComponent::getMenuBarNames()
{
    auto names = { "File" };
    return StringArray (names);
}

PopupMenu MainComponent::getMenuForIndex (int topLevelMenuIndex, const String& menuName)
{
    PopupMenu menu;
    if (topLevelMenuIndex == 0)
        menu.addItem(AudioPrefs, "Audio Prefrences", true, false);
    return menu;
}

void MainComponent::menuItemSelected (int menuItemID, int topLevelMenuIndex)
{
    if (topLevelMenuIndex == FileMenu)
    {
        if (menuItemID == AudioPrefs)
        {
            DialogWindow::LaunchOptions la;
            la.dialogTitle = "Audio Settings";
            OptionalScopedPointer<Component> osp (std::make_unique<AudioDeviceSelectorComponent>
                                                  (audio.getAudioDeviceManager(),
                                                   1, 2, 2, 2,
                                                   true, true, true, false));
            osp->setSize (450, 350);
            la.content = std::move (osp);
            la.componentToCentreAround = this;
            la.launchAsync();
        }
    }
}

void MainComponent::sliderValueChanged(Slider* slider)
{
    if (slider == &gainSlider)
        audio.sineOsc.setGain(gainSlider.getValue()/10);
        
}



void MainComponent::buttonClicked(Button *button)
{
    
    if (button == &butthread)
    {
        if (state == sleeping)
        {
            counterA.startCounter();
            state = active;
        }
        else
        {
            counterA.stopCounter(10);
            state = sleeping;
        }
        
    }
}

void MainComponent::counterChanged(unsigned int count)
{
    std::cout << count << std::endl;
}

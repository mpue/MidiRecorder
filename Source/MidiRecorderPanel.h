/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiRecorder.h"
#include "Logger.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidiRecorderPanel  : public Component,
                           public MidiTools::Logger,
                           public Button::Listener
{
public:
    //==============================================================================
    MidiRecorderPanel ();
    ~MidiRecorderPanel();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    MidiRecorder* getRecorder();
    TextEditor* getTextEditor();
    void log(String message) override;
    void setDeviceManager(AudioDeviceManager* manager);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MidiRecorder* recorder;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> recordButton;
    ScopedPointer<TextButton> playButton;
    ScopedPointer<TextEditor> textEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiRecorderPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

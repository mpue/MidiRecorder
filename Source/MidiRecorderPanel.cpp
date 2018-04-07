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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MidiRecorderPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidiRecorderPanel::MidiRecorderPanel ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (recordButton = new TextButton ("recordButton"));
    recordButton->setButtonText (TRANS("Record"));
    recordButton->addListener (this);

    recordButton->setBounds (16, 16, 150, 24);

    addAndMakeVisible (playButton = new TextButton ("playButton"));
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);

    playButton->setBounds (176, 16, 150, 24);

    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (true);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    setSize(getParentWidth(), getParentHeight() - 20);
    recorder = new MidiRecorder(this);
    //[/Constructor]
}

MidiRecorderPanel::~MidiRecorderPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    recordButton = nullptr;
    playButton = nullptr;
    textEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiRecorderPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiRecorderPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    setSize(getParentWidth(), getParentHeight());
    //[/UserPreResize]

    textEditor->setBounds (0, 16 + 40, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidiRecorderPanel::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == recordButton)
    {
        //[UserButtonCode_recordButton] -- add your button handler code here..
        
        if (recorder->isRecording()) {
            recorder->stopRecording();
            recordButton->setButtonText("Record");
            log("recording stopped.");
        }
        else {
            recorder->startRecording();
            recordButton->setButtonText("Stop");
             log("recording started.");
        }
        
        //[/UserButtonCode_recordButton]
    }
    else if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        if (recorder->isPlaying()) {
            recorder->stopPlaying();
            playButton->setButtonText("Play");
            log("playing stopped.");
        }
        else {
            recorder->startPlaying();
            playButton->setButtonText("Stop");
            log("playing started.");
        }
        //[/UserButtonCode_playButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

MidiRecorder* MidiRecorderPanel::getRecorder() {
    return recorder;
}

TextEditor* MidiRecorderPanel::getTextEditor() {
    return textEditor;
}

void MidiRecorderPanel::log(juce::String message) {
    
    const String m = message;
    
    std::function<void(void)> changeLambda =
    [=]() { textEditor->setText(m + "\n"+textEditor->getText()); };
    juce::MessageManager::callAsync(changeLambda);
    
}

void MidiRecorderPanel::setDeviceManager(juce::AudioDeviceManager *manager) {
    recorder->setDeviceManager(manager);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiRecorderPanel" componentName=""
                 parentClasses="public Component, public MidiTools::Logger" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="recordButton" id="dfb41700f49db3c7" memberName="recordButton"
              virtualName="" explicitFocusOrder="0" pos="16 16 150 24" buttonText="Record"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="playButton" id="be4f4cb62cbf9750" memberName="playButton"
              virtualName="" explicitFocusOrder="0" pos="176 16 150 24" buttonText="Play"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="82dc0dd72a27e090" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="0 40 100% 100%" posRelativeY="dfb41700f49db3c7"
              initialText="" multiline="1" retKeyStartsLine="1" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

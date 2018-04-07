/*
  ==============================================================================

    MidiRecorder.h
    Created: 7 Apr 2018 12:53:35pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Logger.h"
#include <vector>

class MidiRecorder : public MidiInputCallback, public Timer {
    
public:
    
    MidiRecorder(MidiTools::Logger* logger);
    ~MidiRecorder();
    
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    void timerCallback() override;
    
    bool isRecording();
    void startRecording();
    void stopRecording();
    
    bool isPlaying();
    void startPlaying();
    void stopPlaying();

    void setDeviceManager(AudioDeviceManager* manager);
    
private:
    MidiTools::Logger* logger;
    bool recording = false;
    bool playing = false;
    MidiBuffer* midiBuffer;
    AudioDeviceManager* deviceManager;
    double startTime = 0;
    int sampleRate = 44100;
    int previousSampleNumber = 0;
    std::vector<MidiMessage> fuckingMessages;
    int currentMessageIndex = 0;
    
};

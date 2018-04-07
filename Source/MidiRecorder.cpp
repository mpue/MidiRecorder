/*
  ==============================================================================

    MidiRecorder.cpp
    Created: 7 Apr 2018 12:53:35pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "MidiRecorder.h"
#include <vector>
MidiRecorder::MidiRecorder(MidiTools::Logger* logger) {
    this->logger = logger;

}

MidiRecorder::~MidiRecorder() {
    
}

void MidiRecorder::handleIncomingMidiMessage(juce::MidiInput *source, const juce::MidiMessage &message) {
    //Logger->log(message.getDescription());
    
    if (recording) {
        
        MidiMessage m = message.withTimeStamp(Time::getMillisecondCounterHiRes() * 0.001 - startTime);
        fuckingMessages.push_back(MidiMessage(m));
        
    }
    deviceManager->getDefaultMidiOutput()->sendMessageNow(message);
    
}

void MidiRecorder::timerCallback() {
    
    
    if (fuckingMessages.size() > 0 && fuckingMessages.at(currentMessageIndex).getTimeStamp() <= Time::getMillisecondCounterHiRes() * 0.001 - startTime) {
        deviceManager->getDefaultMidiOutput()->sendMessageNow(fuckingMessages.at(currentMessageIndex));
        
        if (currentMessageIndex < fuckingMessages.size() - 1) {
            currentMessageIndex++;
        }
        else {
            currentMessageIndex = 0;
            stopPlaying();
        }
    
    }

}

bool MidiRecorder::isRecording() {
    return recording;
}

void MidiRecorder::stopRecording() {
    recording = false;
}

void MidiRecorder::startRecording(){
    fuckingMessages.clear();
    recording = true;
    startTime = Time::getMillisecondCounterHiRes() * 0.001;
    
}


bool MidiRecorder::isPlaying(){
    return playing;
}

void MidiRecorder::stopPlaying(){
    deviceManager->getDefaultMidiOutput()->sendMessageNow(MidiMessage::allNotesOff(1));
    stopTimer();
    playing = false;
}

void MidiRecorder::startPlaying(){
    playing = true;
    startTime = Time::getMillisecondCounterHiRes() * 0.001;
    startTimer(120/(60*64));
    currentMessageIndex = 0;
}

void MidiRecorder::setDeviceManager(juce::AudioDeviceManager *manager) {
    this->deviceManager = manager;
}

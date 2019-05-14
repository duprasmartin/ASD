/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#define MAX_DELAY_TIME 2

//==============================================================================
/**
*/
class MdbasicDelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MdbasicDelayAudioProcessor();
    ~MdbasicDelayAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    
    float mDryWet;         // MD
//    float mFeedbackAmount; // MD -- no longer used
    
    float mFeedbackLeft;  // MD to put the fedback values in
    float mFeedbackRight; //
    
    float * mCircularBufferLeft; // MD pointer to array that contains left circ buf
    float * mCircularBufferRight; // MD ... and right
    
    int mDelayWriteHead; // that's the "amount" of delay in samples
    int mCircularBufferLength; // MD
    
    float mDelayTimeInSamples;
    float mDelayPlayHead;
    
    AudioParameterFloat * mDryWetParameter;
    AudioParameterFloat * mFeedbackParameter;
    AudioParameterFloat * mDelayTimeParameter;
    AudioParameterFloat * mDelayOutputLevel;
    //=============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MdbasicDelayAudioProcessor)
};

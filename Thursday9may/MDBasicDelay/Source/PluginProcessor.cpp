/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MdbasicDelayAudioProcessor::MdbasicDelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    // MD this is the meat of the CONSTRUKTOR. Hmmmmm... meat.....
    mCircularBufferLeft = nullptr;
    mCircularBufferRight = nullptr;
    
    mDelayWriteHead = 0; // MD default delay time to 0 samples
    mCircularBufferLength = 0; // MD until further notice
    
    mDelayTimeInSamples = 0;
    mDelayPlayHead = 0;
}

MdbasicDelayAudioProcessor::~MdbasicDelayAudioProcessor()
{
    // MD I AM ZEE DESTRUCKTOR
    if (mCircularBufferLeft != nullptr)
    {
        delete [] mCircularBufferLeft;
    }
    
    if (mCircularBufferRight != nullptr)
    {
        delete [] mCircularBufferRight;
    }
}

//==============================================================================
const String MdbasicDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MdbasicDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MdbasicDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MdbasicDelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MdbasicDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MdbasicDelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MdbasicDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MdbasicDelayAudioProcessor::setCurrentProgram (int index)
{
}

const String MdbasicDelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void MdbasicDelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MdbasicDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // MD create the object and its memory space
    if (mCircularBufferLeft == nullptr)
    {
    mCircularBufferLeft = new float [(int)(sampleRate*MAX_DELAY_TIME)];
    }
    
    if (mCircularBufferRight == nullptr)
    {
    mCircularBufferRight = new float [(int)(sampleRate*MAX_DELAY_TIME)];
    }
    
    //mDelayWriteHead = 0; MD just in case things get fucked.
    mCircularBufferLength = sampleRate*MAX_DELAY_TIME;
    mDelayTimeInSamples = 0.150 * sampleRate;
}

void MdbasicDelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MdbasicDelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MdbasicDelayAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.

    float * leftChannel = buffer.getWritePointer(0);
    float * rightChannel = buffer.getWritePointer(1);
    
    for (int i = 0; i < buffer.getNumSamples(); i++)
    {
        mCircularBufferLeft[mDelayWriteHead] = leftChannel[i];
        mCircularBufferRight[mDelayWriteHead] = rightChannel[i];
        
        mDelayPlayHead = mDelayWriteHead - mDelayTimeInSamples;
        
        if (mDelayPlayHead < 0)
        {
            mDelayPlayHead += mCircularBufferLength;
        }
    
        buffer.setSample(0,i, mCircularBufferLeft[(int)(mDelayPlayHead)]);
        buffer.setSample(1,i, mCircularBufferRight[(int)(mDelayPlayHead)]);

        mDelayWriteHead++;
        
        if (mDelayWriteHead > mCircularBufferLength)
        {
            mDelayWriteHead = 0; // MD wrap around
        }
    }
}

//==============================================================================
bool MdbasicDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MdbasicDelayAudioProcessor::createEditor()
{
    return new MdbasicDelayAudioProcessorEditor (*this);
}

//==============================================================================
void MdbasicDelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MdbasicDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MdbasicDelayAudioProcessor();
}

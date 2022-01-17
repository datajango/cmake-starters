cmake_minimum_required(VERSION 3.22)

include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
)
FetchContent_MakeAvailable(JUCE)

juce_add_plugin(04_JucePlugin
    PRODUCT_NAME "04_JucePlugin"
    COMPANY_NAME "Starter."
    BUNDLE_ID "com.starter.04_juceplugin"
    PLUGIN_MANUFACTURER_CODE MANU
    PLUGIN_CODE 04JP

    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    IS_MIDI_EFFECT TRUE

    FORMATS AU VST3 Standalone
)

juce_generate_juce_header(04_JucePlugin)

target_sources(04_JucePlugin PRIVATE
    Source/PluginEditor.cpp
    Source/PluginProcessor.cpp)

target_compile_definitions(04_JucePlugin PRIVATE
    JUCE_ALLOW_STATIC_NULL_VARIABLES=0
    JUCE_STRICT_REFCOUNTEDPOINTER=1

    JUCE_VST3_CAN_REPLACE_VST2=0

    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_REPORT_APP_USAGE=0

    JUCE_ALSA=1
    JUCE_JACK=1
    JUCE_DIRECTSOUND=1
    JUCE_PLUGINHOST_LADSPA=0
    JUCE_PLUGINHOST_VST=0
    JUCE_PLUGINHOST_VST3=1
    JUCE_USE_CAMERA=0
    JUCE_USE_CDBURNER=0
    JUCE_USE_CDREADER=0
    JUCE_USE_CURL=0
    JUCE_USE_FLAC=0
    JUCE_USE_OGGVORBIS=0
    JUCE_WASAPI=0
    JUCE_WEB_BROWSER=0
)

target_link_libraries(04_JucePlugin PRIVATE
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_plugin_client
    juce::juce_audio_processors
    juce::juce_audio_utils
    juce::juce_core
    juce::juce_data_structures
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
)

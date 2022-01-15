cmake_minimum_required(VERSION 3.22)

include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
)
FetchContent_MakeAvailable(JUCE)

juce_add_gui_app(JuceHello
    BUNDLE_ID   com.juce.pluginhost
)

juce_generate_juce_header(JuceHello)

target_sources(JuceHello PRIVATE
    Source/Main.cpp
    Source/MainComponent.cpp)

target_compile_definitions(JuceHello PRIVATE
    JUCE_ALSA=0
    JUCE_DIRECTSOUND=0
    JUCE_PLUGINHOST_LADSPA=0
    JUCE_PLUGINHOST_VST=0
    JUCE_PLUGINHOST_VST3=0
    JUCE_USE_CAMERA=0
    JUCE_USE_CDBURNER=0
    JUCE_USE_CDREADER=0
    JUCE_USE_CURL=0
    JUCE_USE_FLAC=0
    JUCE_USE_OGGVORBIS=0
    JUCE_WASAPI=0
    JUCE_WEB_BROWSER=0)

target_link_libraries(JuceHello PRIVATE
    juce::juce_core
    juce::juce_data_structures
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics)

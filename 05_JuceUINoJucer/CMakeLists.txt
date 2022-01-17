cmake_minimum_required(VERSION 3.22)

project(05_JuceUINoJucer VERSION 0.0.1)

include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
)
FetchContent_MakeAvailable(JUCE)

juce_add_gui_app(05_JuceUINoJucer
    PRODUCT_NAME "05_JuceUINoJucer"
)

juce_generate_juce_header(05_JuceUINoJucer)

target_sources(05_JuceUINoJucer PRIVATE
    src/Main.cpp
    src/MainComponent.cpp)

target_compile_definitions(05_JuceUINoJucer
    PRIVATE
    JUCE_USE_CURL=0
    JUCE_WEB_BROWSER=0
    JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:05_JuceUINoJucer,JUCE_PRODUCT_NAME>"
    JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:05_JuceUINoJucer,JUCE_VERSION>"
    )

target_link_libraries(05_JuceUINoJucer
    PRIVATE
        juce::juce_gui_extra
    )


cmake_minimum_required(VERSION 3.14)

project(tuner VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        CNoteDefs.h
        note/CNoteI.h
        note/CNote.h
        note/CNote.cpp
        octave/COctaveI.h
        octave/COctave.h
        octave/COctave.cpp
        notation/CNotationI.h
        notation/CNotation.h
        notation/CNotation.cpp
        factory/CFactory.h
        factory/CFactory.cpp
        factory/CFactoryJSON.h
        factory/CFactoryJSON.cpp
        factory/CFactoryDefaults.h
        factory/CFactoryDefaults.cpp
        sample_processor/CSampleProcessor.h
        sample_processor/CSampleProcessorKFFT.h
        sample_processor/CSampleProcessorKFFT.cpp
        data_holder/CDataHolder.h
        data_holder/CDataHolder.cpp
        audio_processor/QAudioProcessor.h
        audio_processor/QAudioProcessor.cpp
   )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION ${PROJECT_SOURCES})
else()
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
                                                    3dparty/json/include/
                                                    3dparty/kissfft/
                          )
target_link_directories(${PROJECT_NAME} PRIVATE 3dparty/kissfft/build)
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Multimedia)
target_link_libraries(${PROJECT_NAME} PRIVATE
                                                Qt${QT_VERSION_MAJOR}::Core
                                                Qt${QT_VERSION_MAJOR}::Quick
                                                Qt${QT_VERSION_MAJOR}::Multimedia
                                                kissfft-float)

set_target_properties(${PROJECT_NAME} PROPERTIES
                      MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
                      MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
                      MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
                      MACOSX_BUNDLE TRUE
                      WIN32_EXECUTABLE TRUE
                     )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(${PROJECT_NAME})
    qt_finalize_executable(${PROJECT_NAME})
endif()

cmake_minimum_required(VERSION 3.27)
project(ws_emulator)

set(CMAKE_CXX_STANDARD 23)

# Find GTKMM
find_package(PkgConfig)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

# Set the include directories for GTKMM
include_directories(${GTKMM_INCLUDE_DIRS})

# Set the compiler and linker flags for GTKMM
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(ws_emulator main.cpp
        view/codeEditorView.cpp
        view/codeEditorView.h
        view/hexEditorView.cpp
        view/hexEditorView.h
        view/outputView.cpp
        view/outputView.h
        controller/code_editor.cpp
        controller/code_editor.h
        controller/console.cpp
        controller/console.h
        controller/hex_editor.cpp
        controller/hex_editor.h
        model/text.cpp
        model/text.h
        model/memory.cpp
        model/memory.h
)

# Verknüpfen Sie Ihr Programm mit GTKMM
target_link_libraries(ws_emulator ${GTKMM_LIBRARIES})

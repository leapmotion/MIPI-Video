cmake_minimum_required(VERSION 3.4)
include(version.cmake)
project(mipivideo VERSION ${mipivideo_VERSION})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")

include(AddPCH)
include(CTest)
include(CheckTypeSize)
include(ConditionalSources)

# All of our binaries go to one place:  The binaries output directory.  We only want to tinker
# with this if we're building by ourselves, otherwise we just do whatever the enclosing project
# wants us to do.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Libraries not only all wind up in the libraries directory, but we also keep them all together
# here by putting them in the same place, regardless of whether they are debug or release.  This
# makes globbing them together much easier.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(contrib)
add_subdirectory(src)

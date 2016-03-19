cmake_minimum_required(VERSION 3.4)
include(version.cmake)
project(mipivideo VERSION ${mipivideo_VERSION})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules")

include(AddPCH)
include(CTest)
include(CheckTypeSize)
include(ConditionalSources)

add_subdirectory(contrib)
add_subdirectory(src)

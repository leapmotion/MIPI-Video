cmake_minimum_required(VERSION 3.4)
include(version.cmake)
project(mipivideo VERSION ${mipivideo_VERSION})

include(CTest)
include(CheckTypeSize)

add_subdirectory(contrib)

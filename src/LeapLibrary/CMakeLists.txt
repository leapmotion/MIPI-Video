set(LeapLibrary_SRCS
  LeapLibrary.h
  LeapLibrary.cpp
)

add_pch(LeapLibrary_SRCS stdafx.h stdafx.cpp)
add_library(LeapLibrary ${LeapLibrary_SRCS})

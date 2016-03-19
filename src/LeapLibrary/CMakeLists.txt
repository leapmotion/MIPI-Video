set(LeapLibrary_SRCS
  LeapLibrary.h
  LeapLibrary.cpp
)
add_windows_sources(LeapLibrary_SRCS
  LeapLibraryWin.h
  LeapLibraryWin.cpp
)
add_unix_sources(LeapLibrary_SRCS
  LeapLibraryUnix.h
  LeapLibraryUnix.cpp
)

add_pch(LeapLibrary_SRCS stdafx.h stdafx.cpp)
add_library(LeapLibrary ${LeapLibrary_SRCS})

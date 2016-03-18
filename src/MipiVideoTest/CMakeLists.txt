set(MipiVideoTest_SRCS
  ExtLibrary.h
  ExtLibrary.cpp
  MipiVideoTest.cpp
  FormatTest.cpp
)

add_pch(MipiVideoTest_SRCS stdafx.h stdafx.cpp)
add_executable(MipiVideoTest ${MipiVideoTest_SRCS})
target_link_libraries(MipiVideoTest gtest)

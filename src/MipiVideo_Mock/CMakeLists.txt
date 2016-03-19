set(MipiVideo_Mock_SRCS
  MipiVideo_Mock.def
  MipiVideo_Mock.h
  MipiVideo_Mock.cpp
)

add_pch(MipiVideo_Mock_SRCS stdafx.h stdafx.cpp)
add_library(MipiVideo_Mock SHARED ${MipiVideo_Mock_SRCS})

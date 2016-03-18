set(gtest_SRCS
  fused-src/gtest/gtest-all.cc
)
add_library(gtest ${gtest_SRCS})
target_include_directories(gtest PUBLIC fused-src)
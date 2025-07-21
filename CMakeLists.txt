cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(strochi)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 52eb8108c5bdec04579160ae17225d66034bd723
)

set(BUILD_SHARED_LIBS ON)
FetchContent_MakeAvailable(googletest)
add_library(strochi SHARED String.cxx)
include_directories(${googletest_SOURCE_DIR}/googletest/include)
add_executable(test Test.cxx)
target_link_libraries(test PRIVATE strochi gtest)
add_executable(sort Sort.cxx)
target_link_libraries(sort PRIVATE strochi)

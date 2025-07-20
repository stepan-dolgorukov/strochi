project(strochi)
add_library(strochi SHARED String.cxx)
add_executable(test Test.cxx)
target_link_libraries(test strochi)

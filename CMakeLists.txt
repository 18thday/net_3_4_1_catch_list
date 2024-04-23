cmake_minimum_required(VERSION 3.26)
project(net_3_4_1_catch_list)

set(CMAKE_CXX_STANDARD 20)

#find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
#add_executable(tests test.cpp list.h list.cpp)
#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# These tests need their own main
add_subdirectory(Catch2 Catch2-build)
add_executable(tests test.cpp list.h)
target_link_libraries(tests PRIVATE Catch2::Catch2)
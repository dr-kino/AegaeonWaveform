cmake_minimum_required(VERSION 2.6)

include_directories(/usr/include)
link_directories(/usr/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(sources
		src/Main.cpp
		src/UUT_raw_file_format.cpp
		)

add_executable(UUT_RawFileFormat ${sources})

target_link_libraries(UUT_RawFileFormat gtest)
target_link_libraries(UUT_RawFileFormat gmock)
target_link_libraries(UUT_RawFileFormat pthread)
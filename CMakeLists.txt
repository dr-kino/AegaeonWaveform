#    Filename : CmakeLists.txt
# Description : Definition of all source and header files of one package.
#               To add this package to a project, include this file in the corresponding CMakeLists.txt file.
#      Author :
#     Release :
#   Copyright : 
#    Revision : 
# ------------------------------------------------------------------------------------------------
#     History : 
# ================================================================================================
cmake_minimum_required (VERSION 3.7)

project(Aegaeon)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIR})

add_executable(Aegaeon src/aegaeon.cpp)

# link Boost libraries to the new target
target_link_libraries(Aegaeon ${Boost_LIBRARIES})

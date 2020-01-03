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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(LibXml2 REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIR} ${LIBXML2_INCLUDE_DIR})

add_executable(Aegaeon 
                src/aegaeon.cpp
                src/generator.cpp
                src/output_file_factory.cpp
                src/csv_file_format.cpp
                src/raw_file_format.cpp
                src/txt_file_format.cpp
)

include_directories(
                src/
)

# link Boost libraries to the new target
target_link_libraries(Aegaeon ${Boost_LIBRARIES} ${LIBXML2_LIBRARIES})

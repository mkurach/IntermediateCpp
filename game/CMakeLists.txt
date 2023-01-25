cmake_minimum_required(VERSION 3.10)

add_compile_options(
	-Wall -pedantic -std=c++17 
)

# set the project name
project(game)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

# mark all files from source and include
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

# add the executable
add_executable(${CMAKE_PROJECT_NAME} ${all_SRCS})


# libraries
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
	target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX
					sfml-graphics
					sfml-system
					sfml-window)
endif()

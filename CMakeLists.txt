cmake_minimum_required(VERSION 3.0)
project(SCT)

set(CMAKE_CXX_STANDARD 11)

#find_package(CUDA REQUIRED)

#include_directories(${CUDA_INCLUDE_DIRS})

add_executable(sct src/main.cpp src/cli_parser.cpp src/file_io.cpp src/text_proc.cpp src/vectorizer.cpp src/cpu_sim.cpp)

#target_link_libraries(sct ${CUDA_LIBRARIES})

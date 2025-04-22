cmake_minimum_required(VERSION 3.0)
project(SCT)

find_package(CUDA REQUIRED)

include_directories(${CUDA_INCLUDE_DIRS})

add_executable(sct src/main.cpp src/cli_parser.cpp src/file_io.cpp src/text_proc.cpp src/vectorizer.cpp src/cuda_sim.cu)

target_link_libraries(sct ${CUDA_LIBRARIES})

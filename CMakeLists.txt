cmake_minimum_required(VERSION 3.6)
project(Reconstruction-3D)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Calibration.cpp Camera.cpp Plan.cpp)
add_executable(Reconstruction-3D ${SOURCE_FILES})

# include opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(Reconstruction-3D ${OpenCV_LIBS})
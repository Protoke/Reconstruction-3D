cmake_minimum_required(VERSION 3.6)
project(Calibration)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Calibration.cpp Camera.cpp)
add_executable(Calibration ${SOURCE_FILES})

# include opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(Calibration ${OpenCV_LIBS})
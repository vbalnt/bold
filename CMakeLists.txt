cmake_minimum_required(VERSION 2.8)
project(bold)
find_package(OpenCV REQUIRED)
link_directories(${MYPROJECT_DIR})
set (CMAKE_CXX_FLAGS "-O2 -march=native")
add_executable(bold main.cpp utils.cpp bold.cpp)
target_link_libraries( bold ${OpenCV_LIBS})



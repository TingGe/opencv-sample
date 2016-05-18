cmake_minimum_required (VERSION 2.8)

project(feature)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cv_feature feature.cpp)

target_link_libraries(cv_feature ${OpenCV_LIBS})

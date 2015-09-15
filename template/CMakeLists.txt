cmake_minimum_required(VERSION 3.3)
project(project)

# 配置glfw库
add_subdirectory(../glfw-3.1.1 ./out)

include_directories(../glfw-3.1.1/include)
include_directories(../glm)
include_directories(../common)

#包含glew库的头文件
include_directories(/opt/glew/usr/include/GL)

#链接glew库
link_libraries(/opt/glew/usr/lib/libGLEW.a)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(project ${SOURCE_FILES})
target_link_libraries(project glfw ${GLFW_LIBRARIES})

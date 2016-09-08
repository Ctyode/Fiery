cmake_minimum_required(VERSION 3.6)
project(Fiery)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(Fiery ${SOURCE_FILES})

add_subdirectory(glfw)
include_directories(/glfw/include)
target_link_libraries(Fiery glfw ${GLFW_LIBRARIES})
target_link_libraries(Fiery glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})
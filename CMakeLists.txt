cmake_minimum_required(VERSION 3.6)
project(Fiery)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp glad/src/glad.c)
add_executable(Fiery ${SOURCE_FILES})

include_directories(glad/include)
target_link_libraries(Fiery ${CMAKE_SOURCE_DIR}/libglfw3.a dl X11 Xrandr pthread Xcursor Xxf86vm Xinerama ${OPENGL_LIBRARIES})
cmake_minimum_required(VERSION 3.6)
project(liteCPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Command.h ReturnType.h Add.cpp Add.h Command.cpp Sub.cpp Sub.h Div.cpp Div.h Mul.cpp Mul.h)
add_executable(liteCPP ${SOURCE_FILES})
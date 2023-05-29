cmake_minimum_required(VERSION 3.17)
project(pianoTracker)

set(CMAKE_CXX_STANDARD 14)

add_executable(pianoTracker main.cpp MusicPiece.h MusicPiece.cpp)
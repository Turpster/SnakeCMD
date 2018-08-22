cmake_minimum_required(VERSION 3.12)
project(SnakeCPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(SnakeCPP Entity.cpp Food.cpp Game.cpp Input.cpp Main.cpp Player.cpp)
cmake_minimum_required(VERSION 3.22)
project(mastermind)

set(CMAKE_CXX_STANDARD 23)

add_executable(mastermind main.cpp input_secret_code.cpp input_secret_code.h gamesettings.cpp gamesettings.h guess_secret_code.cpp guess_secret_code.h)

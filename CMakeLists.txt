cmake_minimum_required(VERSION 3.20)
project(solitario)

set(CMAKE_CXX_STANDARD 23)

add_executable(solitario main.cpp card.cpp card.h deck.cpp deck.h board.cpp board.h)

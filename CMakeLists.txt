cmake_minimum_required(VERSION 3.15)
project(KommandCaland C)

set(CMAKE_C_STANDARD 99)

add_executable(KommandCaland main.c chapter.h chapter.c movement.c movement.h debug.c debug.h item.c item.h game.c game.h)
CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
PROJECT(COROUTINE)

set(CMAKE_CXX_STANDARD 20)
add_executable(generator src/main.cpp)
add_executable(scheduler src/Scheduler.cpp)

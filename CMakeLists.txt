cmake_minimum_required(VERSION 3.28)
project(HW4_2425A)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW4_2425A
        OurMain.cpp
        Players/PlayerStatsManager.cpp
        Players/PlayerStatsManager.h
        Players/Player.h
        Players/Job.cpp
        Players/Job.h
        Players/Character.cpp
        Players/Character.h
)

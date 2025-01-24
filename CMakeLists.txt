cmake_minimum_required(VERSION 3.28)
project(HW4_2425A)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW4_2425A
        Players/PlayerStatsManager.cpp
        Players/PlayerStatsManager.h
        Players/Player.h
        Players/Job.cpp
        Players/Job.h
        Players/Character.cpp
        Players/Character.h
        Events/Event.h
        Events/Monster.cpp
        Events/Monster.h
        Events/SpecialEvent.cpp
        Events/SpecialEvent.h
        Players/Player.cpp
        Events/ItemFactory.cpp
        Events/ItemFactory.h
        Events/MonsterStatsManager.cpp
        Events/MonsterStatsManager.h
        Events/Event.cpp
        Events/Encounter.cpp
        Events/Encounter.h
        MatamStory.h
        MatamStory.cpp
)


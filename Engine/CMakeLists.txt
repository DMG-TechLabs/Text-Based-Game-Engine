cmake_minimum_required(VERSION 3.16)
	
project(TextBasedGameEngine)

set(CMAKE_CXX_STANDARD 11)

set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

message(LIB_DIR)

# Add source files
set(SOURCES
    ${LIB_DIR}/achievements/achievement.cpp
    ${LIB_DIR}/achievements/achievement.h

    ${LIB_DIR}/command/command.h
    
    ${LIB_DIR}/item/item.cpp
    ${LIB_DIR}/item/item.h
    
    ${LIB_DIR}/player/inventory.cpp
    ${LIB_DIR}/player/inventory.h
    ${LIB_DIR}/player/player.cpp
    ${LIB_DIR}/player/player.h
    
    ${LIB_DIR}/map/node.cpp
    ${LIB_DIR}/map/node.h
    ${LIB_DIR}/map/map.cpp
    ${LIB_DIR}/map/map.h
    
    ${LIB_DIR}/progress/progress.h
    ${LIB_DIR}/progress/progress.cpp
    
    ${LIB_DIR}/utils/prompt.cpp
    ${LIB_DIR}/utils/prompt.h
    ${LIB_DIR}/utils/game_utils.h
    ${LIB_DIR}/utils/game_utils.cpp

    ${LIB_DIR}/main.cpp
)



add_library(TextBasedGameEngine ${SOURCES})



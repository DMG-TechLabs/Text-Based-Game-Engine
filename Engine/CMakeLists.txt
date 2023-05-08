cmake_minimum_required(VERSION 3.16)
	
project(TextBasedGameEngine)
set(CMAKE_CXX_STANDARD 11)

set(MY_LIBRARY_PATH "..")

set(LIB_DIR "Engine/src")

include_directories(${MY_LIBRARY_PATH}/Engine/boost)
link_directories(${MY_LIBRARY_PATH}/Engine/boost/stage/lib)

message("Library path: ${MY_LIBRARY_PATH}/${LIB_DIR}")

# Add source files
set(SOURCES
    ${MY_LIBRARY_PATH}/${LIB_DIR}/achievements/achievement.cpp
    ${MY_LIBRARY_PATH}/${LIB_DIR}/achievements/achievement.h

    ${MY_LIBRARY_PATH}/${LIB_DIR}/command/command.h
    
    ${MY_LIBRARY_PATH}/${LIB_DIR}/item/item.cpp
    ${MY_LIBRARY_PATH}/${LIB_DIR}/item/item.h
    
    ${MY_LIBRARY_PATH}/${LIB_DIR}/player/inventory.cpp
    ${MY_LIBRARY_PATH}/${LIB_DIR}/player/inventory.h
    ${MY_LIBRARY_PATH}/${LIB_DIR}/player/player.cpp
    ${MY_LIBRARY_PATH}/${LIB_DIR}/player/player.h
    
    ${MY_LIBRARY_PATH}/${LIB_DIR}/node/node.cpp
    ${MY_LIBRARY_PATH}/${LIB_DIR}/node/node.h
    
    ${MY_LIBRARY_PATH}/${LIB_DIR}/progress/progress.h
    ${MY_LIBRARY_PATH}/${LIB_DIR}/progress/progress.cpp
    
    ${MY_LIBRARY_PATH}/${LIB_DIR}/utils/prompt.cpp
    ${MY_LIBRARY_PATH}/${LIB_DIR}/utils/prompt.h
    ${MY_LIBRARY_PATH}/${LIB_DIR}/utils/game_utils.h
    ${MY_LIBRARY_PATH}/${LIB_DIR}/utils/game_utils.cpp

    ${MY_LIBRARY_PATH}/${LIB_DIR}/main.cpp
)

add_executable(TextBasedGameEngine ${SOURCES})
#add_library(TextBasedGameEngine ${SOURCES})
target_link_libraries(TextBasedGameEngine ${boost_serialization}) 



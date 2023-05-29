cmake_minimum_required(VERSION 3.16)
	
project(TextBasedGameEngine)
set(CMAKE_CXX_STANDARD 14)

set(MY_LIBRARY_PATH "./Text-Based-Game-Engine")

set(LIB_DIR "Engine/src")

message("Library path: ${MY_LIBRARY_PATH}/${LIB_DIR}")

set(Boost_USE_STATIC_LIBS OFF) 
# set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

# find_package(Boost 1.74.0 )
find_package(Boost 1.74.0 COMPONENTS serialization REQUIRED)
if(Boost_FOUND)
    message("BOOST FOUND !!!!!")
    message("${Boost_LIBRARIES}")
    message("${Boost_INCLUDE_DIRS}")
    message("${boost_serialization_DIR}")
    include_directories(${Boost_INCLUDE_DIRS}) 
endif()
    
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
    # ${MY_LIBRARY_PATH}/${LIB_DIR}/utils/threads.h
    # ${MY_LIBRARY_PATH}/${LIB_DIR}/utils/threads.cpp

    ${MY_LIBRARY_PATH}/${LIB_DIR}/text/text.h
    ${MY_LIBRARY_PATH}/${LIB_DIR}/text/text.cpp

    ${MY_LIBRARY_PATH}/${LIB_DIR}/map/map.cpp
    ${MY_LIBRARY_PATH}/${LIB_DIR}/map/map.h
    
    ${MY_LIBRARY_PATH}/${LIB_DIR}/menu/menu.h
    ${MY_LIBRARY_PATH}/${LIB_DIR}/menu/menu.cpp
    ${MY_LIBRARY_PATH}/${LIB_DIR}/menu/menu_utils.h
    ${MY_LIBRARY_PATH}/${LIB_DIR}/menu/menu_utils.cpp
)

# add_executable(TextBasedGameEngine ${SOURCES})
add_library(TextBasedGameEngine ${SOURCES})
target_link_libraries(TextBasedGameEngine Boost::serialization)



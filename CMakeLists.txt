cmake_minimum_required(VERSION 3.16)
	
project(TextBasedGameEngine)
set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF) 
# set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

# find_package(Boost 1.74.0 )
# find_package(Boost COMPONENTS serialization REQUIRED)

if(WIN32)
    find_package(Boost)
else()
    find_package(Boost COMPONENTS serialization REQUIRED)
endif()

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    if(WIN32)
        include_directories(${Boost_INCLUDE_DIRS}/boost/serialization) 
    endif()
endif()

include_directories(include)

# Add source files
set(SOURCES
    src/achievements/achievement.cpp

    
    src/item/item.cpp
    
    src/player/inventory.cpp
    src/player/player.cpp
    
    src/node/node.cpp
    
    src/progress/progress.cpp
    
    src/utils/prompt.cpp
    src/utils/game_utils.cpp
    # src/utils/threads.cpp

    src/text/text.cpp

    src/map/map.cpp
    
    src/mission/mission.cpp
    src/mission/objective.cpp
    
    src/menu/menu.cpp
    src/menu/menu_utils.cpp
)

set(INCLUDE
    engine.h

    include/achievement.h
    include/boost_serialization_includes.h
    include/command.h
    include/item.h
    include/inventory.h
    include/player.h
    include/node.h
    include/progress.h
    include/prompt.h
    include/game_utils.h
    # include/threads.h
    include/text.h
    include/map.h
    include/mission.h
    include/objective.h
    include/menu.h
    include/menu_utils.h
    
)

# add_executable(TextBasedGameEngine ${SOURCES})
add_library(${PROJECT_NAME} ${SOURCES} ${INCLUDE})
if(WIN32)
    target_link_libraries(${PROJECT_NAME} serialization)
else()
    target_link_libraries(${PROJECT_NAME} Boost::serialization)
endif()




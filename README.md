# Text-Based-Game-Engine

## Usage

1. Clone the repository

    ```bash
    git clone https://github.com/DMG-TechLabs/Text-Based-Game-Engine --recursive
    ```

2. In your `CMakeList.txt` file, link the Engine

    ```cmake
    add_subdirectory(Text-Based-Game-Engine)
    include_directories(Text-Based-Game-Engine)

    target_link_libraries(${PROJECT_NAME} TextBasedGameEngine)
    ```
3. To use the engine include the `engine.h` file

## Documentation

[Check it here](https://github.com/DMG-TechLabs/Text-Based-Game-Engine/blob/main/Documentation.md)

## Tree

```
.
├── achievements
    │   ├── achievement.cpp
    │   └── achievement.h
    ├── boost_serialization_includes.h
    ├── command
    │   └── command.h
    ├── engine.h
    ├── item
    │   ├── item.cpp
    │   └── item.h
    ├── map
    │   ├── map.cpp
    │   └── map.h
    ├── menu
    │   ├── menu.cpp
    │   ├── menu.h
    │   ├── menu_utils.cpp
    │   └── menu_utils.h
    ├── mission
    │   ├── mission.cpp
    │   ├── mission.h
    │   ├── objective.cpp
    │   └── objective.h
    ├── node
    │   ├── node.cpp
    │   └── node.h
    ├── player
    │   ├── inventory.cpp
    │   ├── inventory.h
    │   ├── player.cpp
    │   └── player.h
    ├── progress
    │   ├── progress.cpp
    │   └── progress.h
    ├── text
    │   ├── text.cpp
    │   └── text.h
    └── utils
        ├── game_utils.cpp
        ├── game_utils.h
        ├── prompt.cpp
        └── prompt.h


```

## Authors

* Konstantinos Despoindis ([KDesp73](https://github.com/KDesp73))
* Konstantinos Mokas ([creatorkostas](https://github.com/creatorkostas))
* Athanasios Georgalis ([ThanasisGeorg](https://github.com/ThanasisGeorg))
* Konstantinos Giantselidis ([congiants](https://github.com/congiants))

## License

[MIT](https://github.com/DMG-TechLabs/Text-Based-Game-Engine/blob/main/LICENSE)

# Text-Based-Game-Engine

## Documentation

[Check it here]()


## Usage

### Prompt - Response

```cpp
Prompt p;
p.prompt_char = '>'
p.accepted_commands = {"help", "read", "collect"};
p.message = "Message to prompt the player";
```

```cpp
Response r = prompt(p);
```

## Tree

```
.
├── achievements/
│   ├── achievement.cpp
│   └── achievement.h
├── command/
│   └── command.h
├── engine.h
├── item/
│   ├── item.cpp
│   └── item.h
├── map/
│   ├── map.cpp
│   └── map.h
├── node/
│   ├── node.cpp
│   └── node.h
├── player/
│   ├── inventory.cpp
│   ├── inventory.h
│   ├── player.cpp
│   └── player.h
├── progress/
│   ├── progress.cpp
│   └── progress.h
├── text/
│   ├── text.cpp
│   └── text.h
└── utils/
    ├── game_utils.cpp
    ├── game_utils.h
    ├── prompt.cpp
    └── prompt.h

```

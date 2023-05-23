# Documentation

> All of the below classes, methods and structs are under the `Engine` namespace

## Achievement Class

Represents an achievement with a name, description, and unlock status.

### Public Members

- `Achievement()`: Default constructor.
- `Achievement(string name, string description)`: Constructor that initializes the achievement with a name and description.
- `~Achievement()`: Destructor.
- `void setName(string name)`: Sets the name of the achievement.
- `string getName()`: Retrieves the name of the achievement.
- `void setDescription(string description)`: Sets the description of the achievement.
- `string getDescription()`: Retrieves the description of the achievement.
- `void setUnlocked(bool unlocked)`: Sets the unlock status of the achievement.
- `bool isUnlocked()`: Checks if the achievement is unlocked.
- `void unlock()`: Unlocks the achievement.

### Private Members

- `bool unlocked`: Indicates whether the achievement is unlocked or not.
- `string name`: The name of the achievement.
- `string description`: The description of the achievement.

### Public Member Functions

#### `Achievement()`

Default constructor.

#### `Achievement(string name, string description)`

Constructor that initializes the achievement with a name and description.

- `name`: The name of the achievement.
- `description`: The description of the achievement.

#### `~Achievement()`

Destructor.

#### `void setName(string name)`

Sets the name of the achievement.

- `name`: The name of the achievement.

#### `string getName()`

Retrieves the name of the achievement.

#### `void setDescription(string description)`

Sets the description of the achievement.

- `description`: The description of the achievement.

#### `string getDescription()`

Retrieves the description of the achievement.

#### `void setUnlocked(bool unlocked)`

Sets the unlock status of the achievement.

- `unlocked`: The unlock status of the achievement.

#### `bool isUnlocked()`

Checks if the achievement is unlocked.

#### `void unlock()`

Unlocks the achievement by setting its unlock status to true.

### Private Member Variables

- `bool unlocked`: Indicates whether the achievement is unlocked or not.
- `string name`: The name of the achievement.
- `string description`: The description of the achievement.

---

## Command Class

### Public Members

#### static void run(Response response, Prompt p, Player *player)

Executes a command by running the specified response, prompt, and player.

- `response`: The response object containing the command logic.
- `p`: The prompt object representing the current prompt state.
- `player`: A pointer to the player object on which the command will be executed.

---

## Item Class

### Private Members

- `string name`: The name of the item.
- `string item_id`: The ID of the item.
- `string description`: The description of the item.

### Public Members

#### Constructors

- `virtual ~Item()`: Destructor.
- `Item()`: Default constructor.
- `Item(string name)`: Constructor that initializes the item with a given name.
- `Item(string name, string description)`: Constructor that initializes the item with a given name and description.
- `Item(string item_id, string name, string description)`: Constructor that initializes the item with a given ID, name, and description.

#### Setters and Getters

- `void setName(string name)`: Sets the name of the item.
- `string getName()`: Retrieves the name of the item.
- `void setItemId(string item_id)`: Sets the ID of the item.
- `string getItemId()`: Retrieves the ID of the item.
- `void setDescription(string description)`: Sets the description of the item.
- `string getDescription()`: Retrieves the description of the item.

---

## Map Class

### Public Members

- `vector<Node*> nodes`: A vector that holds pointers to the nodes in the map.

#### Constructors

- `Map(Node *default_node)`: Constructs a map with a default node and initializes the map.
- `Map(int day, Node *default_node)`: Constructs a map with a default node and initializes the map with a specific day.

#### Destructor

- `~Map()`: Destructor.

#### Methods

- `void initMap(int day)`: Initializes the map with a specific day.
- `void initMap()`: Initializes the map.
- `Node* getNode(int id)`: Retrieves a node with the specified ID.
- `void addNode(Node *node, vector<int> connectedTo = {})`: Adds a new node to the map with optional connections to other nodes.

---

## Menu method

The `menu` method displays a menu with specified background color, options, and a function pointer to handle the selected option.

```cpp
void menu(int bgColor, vector<string> options, void (*handleOptionsFunc)(int selectedOption));

```

### Parameters

- `int bgColor`: The background color of the selected item in the menu.
- `vector<string> options`: A vector containing the menu options.
- `void (*handleOptionsFunc)(int selectedOption)`: A function pointer to the function that handles the selected option. The function should take an integer parameter representing the selected option.

### Example Usage

```cpp
void handleMenuOption(int selectedOption) {
    // Handle the selected menu option
    // ...
}

vector<string> menuOptions = {"Option 1", "Option 2", "Option 3"};
menu(1, menuOptions, handleMenuOption);
```

---

## Node Class

The `Node` class represents a room or a place in general. It contains information about the node's ID, description, items, accessible nodes, and accessibility.

### Private Members

- `bool accessible`: A flag indicating whether the node is accessible or not.

### Public Members

- `int id`: The ID of the node.
- `string description`: The description of the node.
- `vector<Item*> items`: A vector that holds pointers to the items inside the node.
- `vector<Node*> accessible_nodes`: A vector that holds pointers to the nodes the player can move to from the current node.

#### Constructors

- `~Node()`: Destructor.
- `Node()`: Default constructor.
- `Node(int id, string description, vector<Item*> items, vector<Node*> accessible_nodes, bool accessible)`: Constructs a node with the specified ID, description, items, accessible nodes, and accessibility.
- `Node(int id, string description, vector<Item*> items)`: Constructs a node with the specified ID, description, and items.
- `Node(string description)`: Constructs a node with the specified description, representing an inaccessible room.
- `Node(int id, string description)`: Constructs a node with the specified ID and description, representing an inaccessible room.
- `Node(int id, string description, bool accessible)`: Constructs a node with the specified ID, description, and accessibility.

#### Methods

- `void setId(int id)`: Sets the ID of the node.
- `void setDescription(string description)`: Sets the description of the node.
- `void addItem(Item *item)`: Adds an item to the node.
- `void addRoute(Node *n)`: Adds a node as an accessible route from the current node.
- `void lock()`: Locks the node, making it inaccessible.
- `void unlock()`: Unlocks the node, making it accessible.
- `bool isAccessible()`: Checks if the node is accessible.

---

## Inventory Class

The `Inventory` class represents a collection of items that a player can possess.

### Private Members

- `vector<Item *> items`: A vector that holds pointers to the items in the inventory.

### Public Members

#### Constructors

- `Inventory()`: Default constructor.
- `~Inventory()`: Destructor.
- `Inventory(vector<Item *> items)`: Constructs an inventory with the specified items.

#### Getters

- `vector<Item *> getItems()`: Retrieves the items in the inventory.

#### Methods

- `void addItem(Item *item)`: Adds an item to the inventory.
- `Item getItem(string id)`: Retrieves an item from the inventory based on its ID.
- `int getQuantity(Item *item)`: Retrieves the quantity of a specific item in the inventory.
- `int getQuantity(string id)`: Retrieves the quantity of an item in the inventory based on its ID.
- `string exportContents()`: Exports the contents of the inventory as a string representation.
- `void importContents()`: Imports the contents of the inventory from a string representation.
- `void printInventory()`: Prints the inventory.


---

## Player Class

The `Player` class represents a player in the game. It contains information about the player's inventory, name, stats, and current node.

### Private Members

- `Inventory inventory`: The player's inventory.
- `string name`: The name of the player.
- `vector<int> stats`: The player's stats.

### Public Members

- `Node *currentNode`: A pointer to the current node where the player is located.

#### Constructors

- `Player()`: Default constructor.
- `~Player()`: Destructor.
- `Player(Inventory inventory, string name, vector<int> stats)`: Constructs a player with the specified inventory, name, and stats.
- `Player(Inventory inventory, string name, vector<int> stats, Node *currentNode)`: Constructs a player with the specified inventory, name, stats, and current node.

#### Setters and Getters

- `void setInventory(Inventory inventory)`: Sets the player's inventory.
- `Inventory getInventory()`: Retrieves the player's inventory.
- `void setName(string name)`: Sets the player's name.
- `string getName()`: Retrieves the player's name.
- `vector<int> getStats()`: Retrieves the player's stats.

#### Methods

- `void setCurrentNode(Node *newNode)`: Sets the player's current node to the specified node.
- `void moveToNode(Node *newNode)`: Moves the player to a new node if it is accessible.
- `void collectItem(Item *item)`: Collects an item and adds it to the player's inventory.

---

## Progress class

*To be made*

---

## Text Class

The `Text` class provides static members and methods for text formatting and manipulation.

### Static Constants

- `static const string normal`: Normal text formatting.
- `static const string bold`: Bold text formatting.
- `static const string underline`: Underline text formatting.
- `static const string italic`: Italic text formatting.
- `static const string clear`: Clear formatting.
- `static const string erase_line`: Erase current line.
- `static const string black`: Black color.
- `static const string red`: Red color.
- `static const string green`: Green color.
- `static const string yellow`: Yellow color.
- `static const string blue`: Blue color.
- `static const string purple`: Purple color.
- `static const string cyan`: Cyan color.
- `static const string lgrey`: Light gray color.
- `static const string dgrey`: Dark gray color.
- `static const string u_black`: Black color with underline.
- `static const string u_red`: Red color with underline.
- `static const string u_green`: Green color with underline.
- `static const string u_yellow`: Yellow color with underline.
- `static const string u_blue`: Blue color with underline.
- `static const string u_purple`: Purple color with underline.
- `static const string u_cyan`: Cyan color with underline.
- `static const string u_lgrey`: Light gray color with underline.
- `static const string u_dgrey`: Dark gray color with underline.
- `static const string b_black`: Black color with bold.
- `static const string b_red`: Red color with bold.
- `static const string b_green`: Green color with bold.
- `static const string b_yellow`: Yellow color with bold.
- `static const string b_blue`: Blue color with bold.
- `static const string b_purple`: Purple color with bold.
- `static const string b_cyan`: Cyan color with bold.
- `static const string b_lgrey`: Light gray color with bold.
- `static const string b_dgrey`: Dark gray color with bold.

### Static Methods

- `static string color(string where, int color)`: Applies the specified color to the given text.
- `static void delayedTyping(string text)`: Prints the text with a delayed typing effect.
- `static void clearScreen()`: Clears the screen.

---

## Response Struct

The `Response` struct represents a response object that contains a command and its arguments.

### Members

- `string command`: The command string.
- `vector<string> args`: A vector of strings representing the arguments for the command.

---

## Prompt Struct

The `Prompt` struct represents a prompt object that contains information about a prompt message, accepted commands, and a prompt character.

### Members

- `char prompt_char`: The prompt character to be displayed.
- `string message`: The message displayed as the prompt.
- `vector<string> accepted_commands`: A vector of strings representing the accepted commands for the prompt.

---

## prompt Method

The `prompt` method is used to display a prompt message and accept user input.

### Method Signature

- `Response prompt(char prompt_char, string message, vector<string> accepted_commands, vector<string> game_commands = {});`
- `Response prompt(Prompt p, vector<string> game_commands = {}, bool displayPromptMsg = true);`

### Parameters

1. For the first method signature:
   - `prompt_char`: The prompt character to be displayed.
   - `message`: The message displayed as the prompt.
   - `accepted_commands`: A vector of strings representing the accepted commands for the prompt.
   - `game_commands` (optional): A vector of strings representing additional game-specific commands.

2. For the second method signature:
   - `p`: A `Prompt` object containing the prompt character, message, and accepted commands.
   - `game_commands` (optional): A vector of strings representing additional game-specific commands.
   - `displayPromptMsg` (optional): A boolean value indicating whether to display the prompt message (default is `true`).

### Return Value

A `Response` object representing the user's input command and arguments.

---

## print Method

The `print` method is used to print a message to the console without appending a newline character.

### Method Signature

- `void print(string message);`

### Parameters

- `message`: The message to be printed.

### Return Value

None.

---

## println Method

The `println` method is used to print a message to the console and append a newline character.

### Method Signature

- `void println(string message, int delay = 2);`

### Parameters

- `message`: The message to be printed.
- `delay` (optional): The delay in seconds before printing the newline character (default is `2`).

### Return Value

None.

---

## saveToFile Method

The `saveToFile` method is used to save text data to a file.

### Method Signature

- `void saveToFile(string file_name, string text_data);`

### Parameters

- `file_name`: The name of the file to save the text data to.
- `text_data`: The text data to be saved to the file.

### Return Value

None.

---

## loadFromFile Method

The `loadFromFile` method is used to load text data from a file.

### Method Signature

- `string loadFromFile(string file_name);`

### Parameters

- `file_name`: The name of the file to load the text data from.

### Return Value

A string containing the loaded text data from the file.

---

## saveObject Method

The `saveObject` method is used to save an object of type `T` to a file.

### Method Signature

- `template <typename T> void saveObject(string filename, T object_to_save);`

### Parameters

- `filename`: The name of the file to save the object to.
- `object_to_save`: The object of type `T` to be saved to the file.

### Return Value

None.

---

## loadObject Method

The `loadObject` method is used to load an object of type `T` from a file.

### Method Signature

- `template <typename T> T loadObject(string filename, T object_to_load);`

### Parameters

- `filename`: The name of the file to load the object from.
- `object_to_load`: An empty object of type `T` to be populated with the loaded data.

### Return Value

An object of type `T` containing the loaded data from the file.

---

## engine.h

The `engine.h` file serves as a single point of inclusion for all the necessary header files required for the game engine. By including this file in your source code, you gain access to all the classes and utilities needed to build and run a game.

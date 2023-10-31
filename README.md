<img src="/images/babaHeader.png" align="right" height="60" />

# Baba is You : DEV4 - Project

## Table of contents
* [Authors](#Authors)
* [General info](#general-info)
* [Technologies](#technologies)
* [Illustrations](#illustrations)
* [Deviations](#deviations)
* [UML modeling](#UML-modeling)

## Authors

* [FAUCON Jean-Pierre - 58990](https://git.esi-bru.be/58990)
* [WYSK Sara - 59276](https://git.esi-bru.be/59276)

## General info

The game *Baba is you* created using C++.

## Technologies

* C++20
* QtCreator 

## Illustrations

<img src="/images/babaGUI.PNG"/>

## Deviations

* Some memory leaks remain despite addressint them through the use of smart pointers or a destructor because it causes the program to crash.
* 'METAL' is not supported.
* Qt libraries have been used for reading files.

## Known bugs

* The program doesn't execute properly on some devices, probably due to differing Qt versions (investigation running...).

## UML modeling 

### Graph

<img src="https://zupimages.net/up/23/07/6sl8.jpg"/>

### Documentation

#### Controller

* delegates the differents tasks to the adequate classes
* acts like a bridge between the model and the view, as required by the MVC pattern

##### Attributes

* `view_` : the view of the game (ConsoleView or GraphicalView)
* `model_` : the model of the game

##### Methods

* `play()` : launches the game
* `moveYou(char)` : moves the player

#### View

* displays the board of the game in console mode

##### Attributes

* `controller_` : the controller of the game

##### Methods

* `askPlayerMove()` : asks for a move to the player

#### Observer

* represents the interface for the objects that need to be notified of any change happening to a subject
* all the observers are going to be notified of any change happening to the subject they observe

##### Methods

* `update()` : updates the observer

#### Subject

* represents the interface for the objects that are observed by observers
* any change happening to the subject is going to be notified to all of its observers
* as it happens, the view is watching the model in order to update its content according to the model it observes

##### Methods

* `notifyObservers()` : notifies all the observers
* `addObserver(Observer)` : add an observer
* `removeObserver(Observer)` : remove an observer

#### Game

* inherites Subject
* acts like a facade for the model
* represents all important aspects for the game to work (including the state of the game,...)
* contains all the required methods to complete complex tasks asked by the controller

##### Attributes

* `board_` : the board of the game
* `rules_` : the list of rules to be applied on the game
* `hasWon_` : true if the player has won, false otherwise
* `observers` : a list of all the observers

##### Methods

* `Game(int)` : constructor of Game
* `moveYou(Direction)` : moves the player
* `checkRules()` : checks the board and updates `rules_`
* `updateComponentProperties()` : updates the properties of the components using `rules_`
* `win()` : check in `board_` if the win is reached
* `reset()` : reset the game

#### Rule

* represents a rule of the game
* formed in two parts (attributes) : the material and the property
	* the material is the component on which a property is applied
	* the property is the characteristic or action a material can have
		* note that the property is constituted using two objects of type Text (always the "IS" first, then another Text object giving the property per se)

##### Attributes

* `materialType_` : the type of the material
* `property_` : the property to be applied on the material

##### Methods

* `Rule(MaterialType, Property)` : contructor of Rule

#### Property

* enumerates the finite number of possible rule properties
* formed using two objects of Text type : "IS" and another Text object
	* for example, `TEXT_IS` and `TEXT_STOP` form the `IS_STOP` property
	* `TEXT_IS` and `TEXT_YOU` form the `IS_YOU` property

#### Board

* represents the board of the game
* composed of tiles

##### Attributes

* `tiles_` : the 2D board of the game, composed of tiles
* `nbRows_` : the number of rows of the board
* `nbCol_` : the number of columns of the board
* `initialComponentsCoordinates_` : the initial coordinates of the components
* `winReached_` : true if the player has reached the win, false otherwise

##### Methods

* `Board(unsigned, unsigned)` : constructor of Board
* `moveYou(Direction)` : moves the player
* `isInBoard(Position) : bool` : check if a position is in the board
* `isWinReached() : bool` : check if the player is on a tile having the win property

#### LevelReader

* reads the .txt file containing all the data for a specific level
* converts that file into data that is manageable by the Board class

#### Tile

* contains zero to several components
* can be apprehended as an empty square, able to stack components

##### Attributes

* `components_` : the list of components on the tile
* `observers_` : a list of all the observers

##### Methods 

* `Tile()` : constructor for the Tile
* `Tile(string)` : constructor for the Tile with the specified string
* `addComponent(Component)` : adds the specified component on the tile (technically, adds it to the list of components for the current tile)
* `removeComponent(Component)` : removes the specified component from the tile (technically, removes it from the list of components for the current tile)

#### Component

* abstract class used to represent a material or a text object
* allows a tile to contain material and text objects in the same list

##### Attributes

* `position_` : the current position of the component object

##### Methods

* `Component()` : constructor of Component
* `Component(string)` : constructor of Component
* `convert(string)` : converts the specified string into a component object
* `isPushable()` : returns true if the current Component object can be pushed, false otherwise
* `isSteppable()` : returns true if the current Component object can be stepped on, false otherwise
* `canKill()` : returns true if the current Component object kills the player when they step on it, false otherwise

#### Material

* inherits the Component class
* represents a material (e.g. `ROCK`, `WALL`)
* each of those objects can have their corresponding Text type (e.g. ROCK component corresponds with `TEXT_ROCK`) 
	* except for the "is" text (`TEXT_IS`)

##### Attributes

* `type_` : the type of the material
* `property_` : the list of properties to be applied to the material

#### Text

* inherits the Component class
* represents a text element (e.g. `TEXT_IS`, `TEXT_YOU`, `TEXT_STOP`...)
* objects of type Text are moved on the board to create the dynamic rules of the game

##### Attributes

* `type_` : the type of the text

#### MaterialType

* enumerates the finite number of possible Material type objects

#### TextType

* enumerates the finite number of possible Text type objects

### Main deviations from initial UML modeling

* Attribute rules_ has been moved from Game class to Board class
* Attribute direction_ has been added to Component class
* In Material class, attribute property_ has been changed to properties_ (vector of Property)
* In Material class, new attributes have been added : isSteppable_, isPushable_, canKill_, isYou_, isWin_
* A new class has been added : savedLevelReader
* In Game class, the public methods playLevel(), playSavedLevel(), nextLevel(), reset() and savedLevel() have been added
* checkRules() and updateComponentProperties() has been added to the Board class
* In Controller class, the public methods isGameOver() and applyOptions() have been added

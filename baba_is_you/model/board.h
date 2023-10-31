/*********************************************************************
 * @file  model/board.h
 *********************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <list>

#include "model/rule.h"
#include "model/tile.h"

enum class Direction;
class Position;
class Component;
enum class TextType;

/*!
 * \brief The Board class represents the board of the game.
 */
class Board
{
    /*!
     * \brief tiles_ 2D vector of Tile objects that represents the game board.
     */
    std::vector<std::vector<Tile>> tiles_;

    /*!
     * \brief rules_ List of Rule objects that defines the game rules. Each Rule object contains
     * information about what properties apply to components.
     */
    std::list<Rule> rules_;

    /*!
     * \brief nbRows_ The number of rows in the board.
     */
    unsigned nbRows_;

    /*!
     * \brief nbCols_ The number of columns in the board.
     */
    unsigned nbCols_;

    /*!
     * \brief nrLevel_  The number of the current level.
     */
    unsigned nrLevel_;

    /*!
     * \brief winReached_ Indicates whether minimum one "you" component has stepped on a
     * component having "win" as property.
     */
    bool winReached_ { false };

    /*!
     * \brief initialComponentsCoordinates_ This is a vector of pairs where each pair contains a string
     * representing the name of a component and a vector of integers representing the starting coordinates
     * of that component on the game board. This is used to initialize the game board with components in specific locations.
     */
    std::vector<std::pair<std::string, std::vector<int>>> initialComponentsCoordinates_;

public:
    /*!
     * \brief Board constructor with the level number as parameter
     *
     * \param levelNumber The number of the level
     */
    Board(unsigned levelNumber);

    /*!
     * \brief Board constructor of saved level
     *
     * \param unused, just to identify the constructor
     */
    Board(std::string);

    /*!
     * \brief Board default constructor
     */
    Board();

    /*!
     * \brief Gets the tile at given position.
     *
     * \param row The row of the tile
     * \param col The column of the tile
     *
     * \return The tile at given position.
     */
    const Tile& getTileAt(unsigned row, unsigned col) const;

    /*!
     * \brief Gets the number of rows
     *
     * \return The number of rows
     */
    unsigned getNbRows() const;

    /*!
     * \brief Gets the number of columns
     *
     * \return The number of columns
     */
    unsigned getNbCols() const;

    /*!
     * \brief Gets the current level number
     *
     * \return The current level number
     */
    unsigned getNrLevel();

    /*!
     * \brief Checks if the winning condition has been reached.
     * It means that any "you" component has stepped on any component having "win" as property.
     *
     * \return true if the winning condition has been reached, false otherwise
     */
    bool isWinReached();

    /*!
     * \brief Checks if the "you" component has been killed.
     * It means that any "you" component has stepped on any component having "kill" as property.
     *
     * \return true if any "you" component has been killed, false otherwise
     */
    bool isYouKilled();

    /*!
     * \brief Moves the "you" component(s) in a specific direction
     *
     * \param direction The direction in which to move the "you" component(s)
     */
    void moveYou(Direction direction);

    /*!
     * \brief Saves the current level to a file
     *
     * \param levelNumber The number of the level to save
     */
    void saveLevel(unsigned int levelNumber);

    /*!
     * \brief Checks the rules of the level and update the board accordingly
     */
    void checkRules();

    /*!
     * \brief Updates the properties of all the components on the board
     */
    void updateComponentProperties();

    /*!
     * \brief Checks if any "you" component is on any tile containing a component having "kill" as property
     */
    void checkYouInKill();

    /*!
     * \brief Converts the board to a string representation
     *
     * \return The board as a string
     */
    std::string getBoardAsString();

    /*!
     * \brief Converts the board to a string, with just components
     *
     * \return The board as a string
     */
    std::string toString();

    /*!
     * \brief Board::getRules Gets the rules appliable to the current board.
     * This method exists only for testing purposes.
     * \return the list of the rules.
     */
    std::list<Rule> getRules();

private:
    void populateBoard();

    bool isValidPosition(const Position &) const;

    unsigned int getNumberOfYou();
    std::vector<Component *> getAllYouComponents();

    void moveComponent(Component&, Position&, Direction);
    bool pushComponentsRec(Position&, Direction);
    bool pushComponents(Position&, Direction);

    TextType checkRulesDir(Position, Direction);
    void updateComponents();

    bool isStringTextType(std::string &);
};

#endif // BOARD_H

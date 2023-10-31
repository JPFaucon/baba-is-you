/*********************************************************************
 * @file  model/game.h
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "model/board.h"
#include "observer/subject.h"

/*!
 * \brief The Game class represents the game, the facade.
 */
class Game : public Subject
{
    /*!
     * \brief board_ The board of the game.
     */
    Board board_;

    /*!
     * \brief hasWon_ Indicated whether the player has won.
     */
    bool hasWon_;

    /*!
     * \brief currentLevel_ The number of the current level.
     */
    unsigned int currentLevel_;

public:
    /*!
     * \brief Constructor of the game.
     */
    Game();

    /*!
     * \brief Returns true if the player has won, false otherwise.
     * \return A boolean indicating whether the player has won.
     */
    bool getIsWinReached();

    /*!
     * \brief Checks if any "you" component has been killed.
     * \return A boolean indicating whether any "you" component has been killed.
     */
    bool isYouKilled();

    /*!
     * \brief Returns a string representation of the current board.
     * \return A string representing the current board.
     */
    std::string getBoardAsString();

    /*!
     * \brief Returns a string representation of the current board, with just components.
     * \return A string representing the current board.
     */
    std::string getBoardToString();

    /*!
     * \brief Returns the board.
     * \return the board.
     */
    const Board& getBoard() const;

    /*!
     * \brief Plays the specified level.
     * \param level The level to load.
     */
    void playLevel(unsigned int level);

    /*!
     * \brief Plays the last saved level.
     */
    void playSavedLevel();

    /*!
     * \brief Advances to the next level.
     */
    void nextLevel();

    /*!
     * \brief Resets the current level to its initial state.
     */
    void reset();

    /*!
     * \brief Moves the "you" component(s) in the specified direction.
     * \param dir The direction in which to move the "you" component.
     */
    void moveYou(Direction dir);

    /*!
     * \brief Saves the current level.
     */
    void saveLevel();

private:
    void checkRules();
    void updateComponentProperties();

    void win();
};

#endif // GAME_H

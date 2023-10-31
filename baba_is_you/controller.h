/*********************************************************************
 * @file  controller.h
 *********************************************************************/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/game.h"

/*!
 * !brief The Controller class handles interactions between the user interface and the game model.
 */
class Controller
{
    /*!
     * \brief model_ The model.
     */
    Game model_;

public:
    /*!
     * \brief Constructor for the Controller class.
     * \param view An Observer reference to be passed to the game model.
     */
    Controller(Observer& view);

    /*!
     * \brief Returns a string representation of the game board.
     * \return A string containing the game board.
     */
    std::string getBoardAsString();

    /*!
     * \brief Returns a string representation of the current board, with just components.
     * \return A string representing the current board.
     */
    std::string getBoardToString();

    /*!
     * \brief Determines whether the game is over.
     * \return true if the game is over, false otherwise.
     */
    bool isGameOver();

    /*!
     * \brief Determines whether the player character has been killed.
     * \return true if the player character has been killed, false otherwise.
     */
    bool isYouKilled();

    /*!
     * \brief Plays the specified level.
     * \param nrLevel The number of the level to play.
     */
    void playLevel(unsigned int nrLevel);

    /*!
     * \brief Plays the most recently saved level.
     */
    void playSavedLevel();

    /*!
     * \brief Advances to the next level.
     */
    void nextLevel();

    /*!
     * \brief Resets the current level.
     */
    void resetLevel();

    /*!
     * \brief Moves the player character in the specified direction.
     * \param directionChar A character representing the direction to move the player character.
     * Acceptable values are 'z' (up), 'q' (left), 's' (down), and 'd' (right).
     * \throw invalid_argument exception when other values than 'z', 'q', 's' and 'd' are given.
     */
    void moveYou(char directionChar);

    /*!
     * \brief Applies the specified option.
     * \param option A character representing the option to apply.
     * Acceptable values are 'r' (reset level) and 'x' (exit game).
     * \throw invalid_argument exception when other values than 'r'
     * and 'x' are given.
     */
    void applyOption(char option);
};

#endif // CONTROLLER_H

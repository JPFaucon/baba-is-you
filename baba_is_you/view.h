/*********************************************************************
 * @file  view.h
 *********************************************************************/

#ifndef VIEW_H
#define VIEW_H

#include "controller.h"
#include "observer/observer.h"

/*!
 * \brief The View class represents the view in the Model-View-Controller pattern.
 * The View class is responsible for displaying the game to the user and getting user input.
 * It inherits from the Observer class and implements the update() method to react to changes in the model.
 */
class View : public Observer
{
    /*!
     * \brief controller_ The controller.
     */
    Controller controller_;

public:
    /*!
     * \brief Default constructor for the View class.
     */
    View();

    /*!
     * \brief Method called by the model when it is updated.
     * This method updates the display based on changes to the model.
     * \param subject The subject that was updated (in this case, the controller).
     */
    void update(const Subject * subject) override;

private:
    void play();

    void askPlayerMove();
    void askPlayerCommand();

    void showRules();
    void showOptions();
    void showStartOptions();

    void displayBoard();
    void displayGameOver();
    void displayYouLose();
};

#endif // VIEW_H

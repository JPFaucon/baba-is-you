#include "view.h"

#include <iostream>
#include <string>

View::View(): controller_ {Controller(*this)}
{
    //@pbt call play in main function
    play();
}

void View::update(const Subject *subject)
{
    displayBoard();
    if (controller_.isYouKilled())
    {
        displayYouLose();
        askPlayerCommand();
    }
    else if (!controller_.isGameOver())
    {
        askPlayerMove();
    }
    else
    {
        try
        {
            controller_.nextLevel();
        }  catch (std::runtime_error &)
        {
            displayGameOver();
        }
    }
}

/* ************************************ private methods ************************************ */

void View::play()
{
    bool validatedCommand;
    std::string startOptionString;
    char startOption;
    do
    {
        try
        {
            validatedCommand = true;
            do
            {
                showStartOptions();
                do
                {
                    std::getline(std::cin, startOptionString);
                }
                while (startOptionString.size() == 0);
                startOption = startOptionString.at(0);
            } while (startOption != 's' && startOption != 'n');

            switch (startOption)
            {
            case 's' :
                controller_.playSavedLevel();
                break;
            case 'n' :
                controller_.playLevel(0);
            }
        }  catch (std::invalid_argument & e)
        {
            std::cout << "There is no saved level" << std::endl;
            validatedCommand = false;
        } catch (std::runtime_error &)
        {
            std::cout << "Can't launch the level, file problem";
        }
    } while (!validatedCommand);
}

void View::askPlayerMove()
{
    bool validatedCommand;
    std::string directionString;
    char direction;
    do
    {
        try
        {
            validatedCommand = true;
            showRules();
            showOptions();
            do
            {
                std::getline(std::cin, directionString);
            }
            while (directionString.size() == 0);
            direction = directionString.at(0);
            controller_.moveYou(direction);
        }  catch (std::invalid_argument& e)
        {
            std::cout << e.what() << std::endl;
            validatedCommand = false;
        }
    } while (!validatedCommand);
}

void View::askPlayerCommand()
{
    bool validatedCommand;
    char command;
    std::string commandString;
    do
    {
        try
        {
            validatedCommand = true;
            showOptions();
            do
            {
                std::getline(std::cin, commandString);
            }
            while(commandString.size() == 0);
            command = commandString.at(0);
            controller_.applyOption(command);
        }  catch (std::invalid_argument& e)
        {
            std::cout << e.what() << std::endl;
            validatedCommand = false;
        }
    } while (!validatedCommand);
}

// @pbt there are rules in game and game'rules. prefer other name
void View::showRules()
{
    std::cout <<
                 "z : up \n" <<
                 "q : left \n" <<
                 "s : down \n" <<
                 "d : right \n" <<
                 "w : save \n";
}

void View::showOptions()
{
    std::cout <<
                 "r : restart \n" <<
                 "x : quit \n";
}

void View::showStartOptions()
{
    std::cout <<
                 "s : saved level \n" <<
                 "n : new game \n";
}

void View::displayBoard()
{
    std::cout << controller_.getBoardAsString() << std::endl;
}

void View::displayGameOver()
{
    std::cout << "The game is over !" << std::endl;
}

void View::displayYouLose()
{
    std::cout << "You lose !" << std::endl;

}

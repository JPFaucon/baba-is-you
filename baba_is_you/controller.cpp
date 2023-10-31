#include "controller.h"
#include "model/direction.h"

Controller::Controller(Observer& view) : model_ {Game()}
{
    model_.addObserver(&view);
}

std::string Controller::getBoardAsString()
{
    return model_.getBoardAsString();
}

std::string Controller::getBoardToString()
{
    return model_.getBoardToString();
}

bool Controller::isGameOver()
{
    return model_.getIsWinReached();
}

bool Controller::isYouKilled()
{
    return model_.isYouKilled();
}

void Controller::playLevel(unsigned int nrLevel)
{
    model_.playLevel(nrLevel);
}

void Controller::playSavedLevel()
{
    model_.playSavedLevel();
}

void Controller::nextLevel()
{
    model_.nextLevel();
}

void Controller::resetLevel()
{
    model_.reset();
}

void Controller::moveYou(char directionChar)
{
    Direction direction;
    switch(directionChar)
    {
    case 'r':
    {
        resetLevel();
        return;
    }
    case 'x':
        return;
    case 'w':
    {
        model_.saveLevel();
        return;
    }
    case 'z':
        direction = Direction::UP;
        break;
    case 'q':
        direction = Direction::LEFT;
        break;
    case 's':
        direction = Direction::DOWN;
        break;
    case 'd':
        direction = Direction::RIGHT;
        break;
    default:
        throw std::invalid_argument("Unknown character");
    }
    model_.moveYou(direction);
}

void Controller::applyOption(char option)
{
    switch (option)
    {
    case 'r':
    {
        resetLevel();
        return;
    }
    case 'x':
        return;
    default:
        throw std::invalid_argument("Unknown option");
    }
}

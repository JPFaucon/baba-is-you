#include "model/game.h"

Game::Game()
{}

bool Game::getIsWinReached()
{
    win();
    return hasWon_;
}

std::string Game::getBoardAsString()
{
    return board_.getBoardAsString();
}

std::string Game::getBoardToString()
{
    return board_.toString();
}

const Board& Game::getBoard() const
{
    return board_;
}

bool Game::isYouKilled()
{
    return board_.isYouKilled();
}

void Game::playLevel(unsigned int nrLevel)
{
    // @pbt avoid copy
    board_ = std::move(Board(nrLevel));
    hasWon_ = false;
    currentLevel_ = nrLevel;
    checkRules();
    updateComponentProperties();
    notifyObservers();
}

void Game::playSavedLevel()
{
    board_ = Board("");
    hasWon_ = false;
    currentLevel_ = board_.getNrLevel();
    checkRules();
    updateComponentProperties();
    notifyObservers();
}

void Game::nextLevel()
{
    board_ = Board(currentLevel_+1);
    currentLevel_++;
    hasWon_ = false;
    checkRules();
    updateComponentProperties();
    notifyObservers();
}

void Game::reset()
{
    board_ = Board(currentLevel_);
    hasWon_ = false;
    checkRules();
    updateComponentProperties();
    notifyObservers();
}

void Game::moveYou(Direction dir)
{
    board_.moveYou(dir);
    checkRules();
    updateComponentProperties();
    board_.checkYouInKill();
    notifyObservers();
}

void Game::saveLevel()
{
    board_.saveLevel(currentLevel_);
    notifyObservers();
}

/* ************************************ private methods ************************************ */

void Game::checkRules()
{
    board_.checkRules();
}

void Game::updateComponentProperties()
{
    board_.updateComponentProperties();
}

void Game::win()
{
    if(board_.isWinReached())
        hasWon_ = true;
}

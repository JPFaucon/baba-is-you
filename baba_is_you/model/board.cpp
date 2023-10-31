#include "model/board.h"
#include "utils/levelreader.h"
#include "model/text.h"
#include "model/material.h"
#include "model/position.h"
#include "utils/enumsutility.h"
#include "utils/directionutility.h"
#include "model/tile.h"
#include "model/direction.h"
#include "model/rule.h"
#include "utils/savedlevelreader.h"
#include "model/direction.h"
#include "model/component.h"
#include "model/enums.h"

Board::Board(unsigned int nrLevel) : nrLevel_ {nrLevel}
{
    LevelReader currentLevel { nrLevel };
    this->initialComponentsCoordinates_ =
                    currentLevel.getComponentsCoordinates();
    this->nbRows_ = currentLevel.getNbRows();
    this->nbCols_ = currentLevel.getNbCol();
    this->tiles_.resize(nbRows_, std::vector<Tile>(nbCols_));
    populateBoard();
}

Board::Board(std::string)
{
    SavedLevelReader currentLevel {};
    this->initialComponentsCoordinates_ =
                    currentLevel.getComponentsCoordinates();
    this->nbRows_ = currentLevel.getNbRows();
    this->nbCols_ = currentLevel.getNbCol();
    this->nrLevel_ = currentLevel.getNrLevel();
    this->tiles_.resize(nbRows_, std::vector<Tile>(nbCols_));
    populateBoard();
}

Board::Board() {}

unsigned Board::getNrLevel()
{
    return nrLevel_;
}

const Tile& Board::getTileAt(unsigned row, unsigned col) const
{
    return tiles_.at(row).at(col);
}


unsigned Board::getNbRows() const
{
    return nbRows_;
}

unsigned Board::getNbCols() const
{
    return nbCols_;
}

bool Board::isWinReached()
{
    for (unsigned y = 0; y < nbRows_; ++y) {
        for (unsigned x = 0; x < nbCols_; ++x) {
            if (tiles_.at(y).at(x).containsYou()
                && tiles_.at(y).at(x).containsWin()) {
                return true;
            }
        }
    }
    return false;
}

bool Board::isYouKilled()
{
    return getNumberOfYou() == 0;
}

void Board::moveYou(Direction dir)
{
    std::vector<Component *> yousOnBoard = this->getAllYouComponents();
    for (const auto & you : yousOnBoard) {
        // @pbt prefer braces initializer
        auto position { you->getPosition() };
        auto newPosition { Position(position, dir) };
        if (isValidPosition(newPosition)) {
            // @pbt prefer use ref over pointer
            Tile & newTile = tiles_
                    .at(newPosition.getY()).at(newPosition.getX());
            if ((newTile).isSteppable()) {
                moveComponent(*you, position, dir);
            } else if ((newTile).isPushable()) {
                if (pushComponentsRec(newPosition, dir)) {
                    moveComponent(*you, position, dir);
                }
            }
        }
    }
}

void Board::saveLevel(unsigned int currentLevel)
{
    std::stringstream levelStream;
    levelStream << currentLevel << "\n";
    levelStream << nbRows_ << " " << nbCols_ << " ";
    for (unsigned int y = 0; y < nbRows_; y++) {
        for (unsigned int x = 0; x < nbCols_; x++) {
            auto & components = tiles_.at(y).at(x).getComponents();
            for (const auto & component : components) {
                levelStream << "\n";
                levelStream << component->getTextAsString() << " ";
                levelStream << x << " " << y << " ";
                levelStream << DirectionUtility::directionToInt(
                                            component->getDirection());
            }
        }
    }
    std::string level = levelStream.str();
    SavedLevelReader::saveLevel(level);
}

void Board::checkRules()
{
    rules_.clear();
    for (unsigned y = 0; y < nbRows_; y++) {
        for (unsigned x = 0; x < nbCols_; x++) {
            const Tile & currentTile = tiles_.at(y).at(x);
            if (currentTile.getTopComponent() != nullptr) {
                const TextType currentText = currentTile.getTopComponent()->getText(); // crash ici
                if (currentText != TextType::TEXT_NULL) {
                    if (currentText == TextType::TEXT_BABA
                        || currentText == TextType::TEXT_FLAG
                        || currentText == TextType::TEXT_ROCK
                        || currentText == TextType::TEXT_WALL
                        || currentText == TextType::TEXT_GRASS
                        || currentText == TextType::TEXT_WATER
                        || currentText == TextType::TEXT_LAVA) {
                        const Position currentPos { (int) x, (int) y };
                        // [&] -> to use dir
                        auto addRule = [&](Direction dir) {
                            TextType textProperty = checkRulesDir(currentPos, dir);
                            if (textProperty != TextType::TEXT_NULL) {
                                MaterialType material = EnumsUtility::textTypeToMaterialType(currentText);
                                Property property = EnumsUtility::textTypeToProperty(textProperty);
                                rules_.push_back(Rule(material, property));
                            }
                        };
                        addRule(Direction::DOWN);
                        addRule(Direction::RIGHT);
                    }
                }
            }
        }
    }
}

void Board::updateComponentProperties()
{
    updateComponents();
    for (unsigned int y = 0; y < nbRows_; ++y) {
        for (unsigned int x = 0; x < nbCols_; ++x) {
            tiles_.at(y).at(x).updateComponentProperties(rules_);
        }
    }
}

void Board::checkYouInKill()
{
    for (unsigned y = 0; y < nbRows_; ++y) {
        for (unsigned x = 0; x < nbCols_; ++x) {
            tiles_.at(y).at(x).youInKill();
        }
    }
}

std::string Board::getBoardAsString()
{
    std::stringstream boardDisplay;
    boardDisplay << std::string((nbCols_ + 2) * 3, '-') << "\n";
    for (unsigned int y = 0; y < nbRows_; ++y) {
        boardDisplay << "///";
        for (unsigned int x = 0; x < nbCols_; ++x) {
            auto visibleComponent = this->tiles_.at(y).at(x).getTopComponent();
            if (visibleComponent) {
                boardDisplay << visibleComponent->strDisplay();
            } else {
                boardDisplay << "   ";
            }
        }
        boardDisplay << "///" << "\n";
    }
    boardDisplay << std::string((nbCols_ + 2) * 3, '-') << "\n";
    return boardDisplay.str();
}

std::string Board::toString()
{
    std::stringstream boardDisplay;
    for (unsigned int y = 0; y < nbRows_; ++y) {
        for (unsigned int x = 0; x < nbCols_; ++x) {
            auto visibleComponent = this->tiles_.at(y).at(x).getTopComponent();
            if (visibleComponent) {
                boardDisplay << visibleComponent->strDisplay();
            } else {
                boardDisplay << "   ";
            }
        }
        boardDisplay << "\n";
    }
    return boardDisplay.str();
}

std::list<Rule> Board::getRules()
{
    return this->rules_;
}

/* ************************************ private methods ************************************ */

void Board::populateBoard()
{
    for (const auto & componentData : this->initialComponentsCoordinates_) {
        auto currentCompCol = componentData.second.at(0);
        auto currentCompRow = componentData.second.at(1);
        Position currentCompPos { currentCompCol, currentCompRow };
        auto currentCompString = componentData.first;
        bool isText = isStringTextType(currentCompString);
        Direction direction = DirectionUtility::intToDirection
                              (componentData.second.size() == 3 ? componentData.second[2] : 0);


        // Smart pointers consciously left in comments because makes the program crash.
        // Same goes for the Desctructor.

        // std::unique_ptr<Component> currentComp;
        Component * currentComp { nullptr };
        if (isText)
        {
            //currentComp = std::make_unique<Text>(currentCompString, currentCompPos, direction);
            currentComp = new Text(currentCompString, currentCompPos, direction);
        }
        else
        {
            //currentComp = std::make_unique<Material>(currentCompString, currentCompPos, direction);
            currentComp = new Material(currentCompString, currentCompPos, direction);
        }

        this->tiles_.at(currentCompRow)
        .at(currentCompCol)
        .addComponent(*currentComp);
    }
}

/*
 valgrind issue
 288 bytes in 12 blocks are definitely lost in loss record 13 of 17
  dans Board::populateBoard() in /home/pit/vcs-notsync/corrections/20222023-dev4/s-wysk-j-faucon/baba_is_you/model/board.cpp:197


3,440 (2,320 direct, 1,120 indirect) bytes in 29 blocks are definitely lost in loss record 16 of 17
  dans Board::populateBoard() in /home/pit/vcs-notsync/corrections/20222023-dev4/s-wysk-j-faucon/baba_is_you/model/board.cpp:199

 */

bool Board::isValidPosition(const Position & pos) const
{
    const unsigned x = pos.getX();
    const unsigned y = pos.getY();
    return (x >= 0 && x < (this->nbCols_) &&
            y >= 0 && y < (this->nbRows_));
}

unsigned int Board::getNumberOfYou()
{
    unsigned int i = 0;
    for (unsigned y = 0; y < nbRows_; ++y) {
        for (unsigned x = 0; x < nbCols_; ++x) {
            if (tiles_.at(y).at(x).containsYou()) {
                i++;
            }
        }
    }
    return i;
}

std::vector<Component *> Board::getAllYouComponents()
{
    std::vector<Component *> yousOnBoard { };
    for (unsigned int y = 0; y < nbRows_; ++y) {
        for (unsigned int x = 0; x < nbCols_; ++x) {
            std::vector<Component *> yousOnTile = tiles_.at(y).at(
                    x).getYouComponents();
            yousOnBoard.insert(yousOnBoard.end(), yousOnTile.begin(),
                               yousOnTile.end());
        }
    }
    return yousOnBoard;
}

void Board::moveComponent(Component & component, Position & pos,
                          Direction dir)
{
    component.move(dir);
    Position newPos = Position(pos, dir);
    tiles_.at(newPos.getY()).at(newPos.getX()).addComponent(component);
    tiles_.at(pos.getY()).at(pos.getX()).removeComponent(component);
}


bool Board::pushComponentsRec(Position & pos, Direction dir)
{
    auto newPos = Position(pos, dir);
    if (isValidPosition(newPos)) {
        auto newTile = tiles_.at(newPos.getY()).at(newPos.getX());
        if (newTile.isSteppable()) {
            return pushComponents(pos, dir);
        } else if (newTile.isPushable()) {
            if (pushComponentsRec(newPos, dir)) {
                return pushComponents(pos, dir);
            }
        }
    }
    return false;
}

bool Board::pushComponents(Position & pos, Direction dir)
{
    auto components = tiles_.at(pos.getY()).at(pos.getX()).getComponents();
    auto newPos = Position(pos, dir);
    Tile * newTile = &tiles_.at(newPos.getY()).at(newPos.getX());
    for (auto component : components) {
        if (component->isPushable()) {
            moveComponent(*component, pos, dir);
            (*newTile).rockInWater();
        }
    }
    return true;
}

TextType Board::checkRulesDir(Position position, Direction direction)
{
    auto isPos = Position(position, direction);
    if (!isValidPosition(isPos)) {
        return TextType::TEXT_NULL;
    }
    Tile isTile = tiles_.at(isPos.getY()).at(isPos.getX());
    for (auto component : isTile.getComponents()) {
        if (component->getText() == TextType::TEXT_IS) {
            auto textPos = Position(isPos, direction);
            if (!isValidPosition(textPos)) {
                return TextType::TEXT_NULL;
            }
            Tile propertyTile = tiles_
                    .at(textPos.getY()).at(textPos.getX());
            for (auto component2 : propertyTile.getComponents()) {
                if (component2->getText() != TextType::TEXT_NULL
                    && component2->getText() != TextType::TEXT_IS)
                    return component2->getText();
            }
        }
    }
    return TextType::TEXT_NULL;
}

void Board::updateComponents()
{
    for (auto rule : rules_) {
        MaterialType newMaterialType = EnumsUtility::propertyToMaterialType(
                rule.getProperty());
        if (newMaterialType != MaterialType::MTNULL) {
            for (unsigned int y = 0; y < nbRows_; ++y) {
                for (unsigned int x = 0; x < nbCols_; ++x) {
                    tiles_.at(y).at(x).updateComponents(rule.getMaterialType(),
                                                        newMaterialType);
                }
            }
        }
    }
}

// @pbt ?
bool Board::isStringTextType(std::string & s)
{
    return s.find("text") != std::string::npos
           || s == "is"
           || s == "kill"
           || s == "push"
           || s == "sink"
           || s == "stop"
           || s == "win"
           || s == "you";
}

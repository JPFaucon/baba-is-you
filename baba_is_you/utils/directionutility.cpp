#include "directionutility.h"
#include "model/direction.h"

DirectionUtility::DirectionUtility()
{}

std::unordered_map<unsigned int, Direction> DirectionUtility::intToDirectionMap_ = {
    {0, Direction::RIGHT},
    {1, Direction::UP},
    {2, Direction::LEFT},
    {3, Direction::DOWN}
};

std::unordered_map<Direction, unsigned int> DirectionUtility::directionToIntMap_ = {
    {Direction::RIGHT, 0},
    {Direction::UP, 1},
    {Direction::LEFT, 2},
    {Direction::DOWN, 3}
};


std::unordered_map<Direction, std::pair<int, int>> DirectionUtility::directionToDxDyMap_ = {
    {Direction::UP, {0, -1}},
    {Direction::DOWN, {0, 1}},
    {Direction::LEFT, {-1, 0}},
    {Direction::RIGHT, {1, 0}}
};

Direction DirectionUtility::intToDirection(unsigned int dir)
{
    auto it = intToDirectionMap_.find(dir);
    if (it != intToDirectionMap_.end())
    {
        return it->second;
    }
    else
    {
        throw std::invalid_argument("Unknown direction");
    }
}

unsigned int DirectionUtility::directionToInt(Direction direction)
{
    auto it = directionToIntMap_.find(direction);
    if (it != directionToIntMap_.end())
    {
        return it->second;
    }
    else
    {
        throw std::invalid_argument("Unknown direction");
    }
}

std::pair<int, int> DirectionUtility::directionToDxDy(Direction direction)
{
    auto it = directionToDxDyMap_.find(direction);
    if (it != directionToDxDyMap_.end())
    {
        return it->second;
    }
    else
    {
        throw std::invalid_argument("Unknown direction");
    }
}

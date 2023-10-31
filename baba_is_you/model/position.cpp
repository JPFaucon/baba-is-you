#include "model/position.h"
#include "model/direction.h"
#include "utils/directionutility.h"

Position::Position(int x, int y) :
    x_ { x }, y_ { y }
{ }

Position::Position(const Position& pos, Direction dir) :
    x_ { pos.x_ + DirectionUtility::directionToDxDy(dir).first},
    y_ { pos.y_ + DirectionUtility::directionToDxDy(dir).second}
{}

int Position::getX() const
{
    return x_;
}

void Position::setX(int x)
{
    x_ = x;
}

int Position::getY() const
{
    return y_;
}

void Position::setY(int y)
{
    y_ = y;
}

void Position::move(Direction d)
{
    std::pair dxDy = DirectionUtility::directionToDxDy(d);
    x_ += dxDy.first;
    y_ += dxDy.second;
}

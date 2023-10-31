#include "model/component.h"
#include "model/enums.h"

Component::Component(Position & position, Direction direction)
    : position_ { position }
    , direction_ { direction }
{}

Position Component::getPosition() const
{
    return position_;
}

Direction Component::getDirection() const
{
    return direction_;
}

TextType Component::getText() const
{
    return TextType::TEXT_NULL;
}

MaterialType Component::getMaterial() const
{
    return MaterialType::MTNULL;
}

void Component::move(Direction dir)
{
    position_.move(dir);
}

void Component::setPosition(Position & position)
{
    position_ = position;
}

#include <stdexcept>
#include "model/text.h"
#include "model/enums.h"
#include "utils/enumsutility.h"

Text::Text(std::string & s, Position & position, Direction direction)
    : Component { position, direction }
    , type_ { EnumsUtility::stringToTextType(s) }
{}

TextType Text::getType() const
{
    return this->type_;
}

TextType Text::getText() const
{
    return this->type_;
}

std::string Text::strDisplay() const
{
    return EnumsUtility::textTypeToString(this->type_);
}

std::string Text::getTextAsString() const
{
    return EnumsUtility::textTypeAsString(this->type_);
}

bool Text::isSteppable()
{
    return false;
}

bool Text::isPushable()
{
    return true;
}

bool Text::canKill()
{
    return false;
}

bool Text::isYou()
{
    return false;
}

bool Text::isWin()
{
    return false;
}

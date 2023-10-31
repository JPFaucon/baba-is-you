#include <stdexcept>
#include <set>
#include "model/material.h"
#include "model/enums.h"
#include "utils/enumsutility.h"

Material::Material(std::string & s, Position & position, Direction direction)
    : Component { position, direction }
    , type_ { EnumsUtility::stringToMaterialType(s) }
{}

Material::Material(MaterialType mt, Position & position, Direction direction)
    : Component {position, direction}
    , type_ {mt}
{}

Material::~Material()
{}

MaterialType Material::getType() const
{
    return this->type_;
}

std::set<Property> Material::getProperties() const
{
    return this->properties_;
}

MaterialType Material::getMaterial() const
{
    return this->type_;
}

std::string Material::strDisplay() const
{
    return EnumsUtility::materialTypeToString(this->type_);
}

std::string Material::getTextAsString() const
{
    return EnumsUtility::materialTypeAsString(this->type_);
}

bool Material::isSteppable()
{
    return this->isSteppable_;
}

void Material::setSteppable(bool isSteppable)
{
    this->isSteppable_ = isSteppable;
}

bool Material::isPushable()
{
    return this->isPushable_;
}

void Material::setPushable(bool isPushable)
{
    this->isPushable_ = isPushable;
}

bool Material::canKill()
{
    return this->canKill_;
}

void Material::setCanKill(bool canKill)
{
    this->canKill_ = canKill;
}

bool Material::isYou()
{
    return this->isYou_;
}

void Material::setIsYou(bool isYou)
{
    this->isYou_ = isYou;
}

bool Material::isWin()
{
    return this->isWin_;
}

void Material::updateAttributes()
{
    if (properties_.count(Property::IS_PUSH))
    {
        this->isSteppable_ = false;
        this->isPushable_ = true;
    }
    if (properties_.count(Property::IS_SINK))
    {
        this->canKill_ = true;
    }
    if (properties_.count(Property::IS_STOP))
    {
        this->isSteppable_ = false;
    }
    if (properties_.count(Property::IS_WIN))
    {
        this->isWin_ = false;
    }
    if (properties_.count(Property::IS_YOU))
    {
        this->isPushable_ = true;
        this->isYou_ = true;
    }
    if (properties_.count(Property::IS_KILL))
    {
        this->canKill_ = true;
    }
    if (properties_.count(Property::IS_PUSH) && properties_.count(Property::IS_YOU))
    {
        this->isSteppable_ = true;
    }
}

void Material::setDefaultProperties()
{
    this->isSteppable_ = true;
    this->isPushable_ = false;
    this->canKill_ = false;
    this->isYou_ = false;
    this->isWin_ = false;
}

void Material::addProperty(const Property & property)
{
    this->properties_.insert(property);
    this->updateAttributes();
}

void Material::clearProperties()
{
    this->properties_.clear();
    setDefaultProperties();
}

#include <stdarg.h>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include "model/tile.h"
#include "model/material.h"
#include "model/text.h"
#include "model/enums.h"
#include "model/rule.h"

Tile::Tile(unsigned int count, ...)
{
    va_list args;
    va_start(args, count);

    for (unsigned int i = 0; i < count; ++i)
    {
        Component * component = va_arg(args, Component *);
        this->components_.push_back(component);
    }
    va_end(args);
}

const std::vector<Component *> & Tile::getComponents() const
{
    return components_;
}

const Component * Tile::getTopComponent() const
{
    //std::cout << "enter Tile::getTopComponent" << std::endl; // entered 365x
    return components_.empty()
            ? nullptr
            : this->components_.back();
}

std::vector<Component *> Tile::getYouComponents()
{
    std::vector<Component *> youComponents { };

    for (auto * component : this->components_)
    {
        Material * materialComp = dynamic_cast<Material *>(component);

        if (materialComp != nullptr && materialComp->isYou())
        {
            youComponents.push_back(component);
        }
    }
    return youComponents;
}

bool Tile::isSteppable()
{
    for (Component * component : components_)
    {
        if (!component->isSteppable())
        {
            return false;
        }
    }
    return true;
}

bool Tile::isPushable()
{
    for (auto component : components_)
    {
        if (!component->isPushable() && !component->isSteppable())
        {
            return false;
        }
    }
    return true;
}

bool Tile::containsYou()
{
    for (auto & component : components_)
    {
        if (auto material = dynamic_cast<Material *>(component))
        {
            if (material->isYou())
                return true;
        }
    }
    return false;
}

bool Tile::containsWin()
{
    for (auto & component : components_)
    {
        if (auto material = dynamic_cast<Material *>(component))
        {
            if (material->getProperties().count(Property::IS_WIN) > 0)
                return true;
        }
    }
    return false;
}

bool Tile::containsKill()
{
    for (auto & component : components_)
    {
        if (auto material = dynamic_cast<Material *>(component))
        {
            if (material->canKill())
                return true;
        }
    }
    return false;
}

void Tile::addComponent(Component & comp)
{
    components_.push_back(&comp);
}

void Tile::removeComponent(Component & comp)
{
    auto it = std::find(components_.begin(), components_.end(), &comp);

    if (it != components_.end())
        components_.erase(it);
    else
        throw std::invalid_argument("Component not found");
}

void Tile::rockInWater()
{
    for (auto component : components_)
    {
        if (auto material = dynamic_cast<Material *>(component))
        {
            if (material->getMaterial() == MaterialType::WATER)
            {
                for (unsigned i = 0; i < components_.size(); i++)
                {
                    if (auto material2 = dynamic_cast<Material *>(components_[i]))
                    {
                        if (material2->getMaterial() == MaterialType::ROCK)
                        {
                            removeComponent(*components_[i]);
                            removeComponent(*component);
                        }
                    }
                }
            }
        }
    }
}

void Tile::youInKill()
{
    if (containsKill())
    {
        for (unsigned i = 0; i < components_.size(); i++)
        {
            if (auto material2 = dynamic_cast<Material *>(components_[i]))
            {
                if (material2->getProperties().contains(Property::IS_YOU))
                {
                    removeComponent(*components_[i]);
                }
            }
        }
    }
}

void Tile::updateComponentProperties(const std::list<Rule> & rules)
{
    for (auto & component : components_)
    {
        if (auto material = dynamic_cast<Material *>(component))
        {
            material->clearProperties();

            for (const auto & rule : rules)
            {
                if (rule.getMaterialType() == material->getType())
                {
                    material->addProperty(rule.getProperty());
                }
            }
        }
    }
}

void Tile::updateComponents(MaterialType materialType, MaterialType newMaterialType)
{
    for (auto component : components_)
    {
        if (auto material = dynamic_cast<Material *>(component))
        {
            if (material->getMaterial() == materialType)
            {
                Position newPosition = Position {component->getPosition()};
                Direction newDirection = component->getDirection();

                std::unique_ptr<Component> newComponent
                    = std::make_unique<Material>(newMaterialType, newPosition, newDirection);

                removeComponent(*component);
                addComponent(*newComponent);
            }
        }
    }
}

//Tile::~Tile()
//{
//    std::for_each(components_.begin(),components_.end(),
//                  [](auto c){delete(c);}
//    );

//}

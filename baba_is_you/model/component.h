/*********************************************************************
 * @file  model/component.h
 *********************************************************************/

#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

#include "model/position.h"

enum class TextType;
enum class MaterialType;

/*!
 * \brief The Component class represents the components of the game.
 * A component can be of type Text or Material (but not both). Those
 * components are positionned on a tile. Several components can be
 * on the same tile.
 * Example of Text component : ROCK_TEXT
 * Example of Material component : ROCK
 */
class Component
{
private:
    /*!
     * \brief position_ The position of the current component.
     */
    Position position_;

    /*!
     * \brief direction_ The direction of the current component.
     */
    Direction direction_;

public:

    /*!
     * \brief Constructor for a component object.
     * \param position The position of the component.
     * \param direction The direction of the component.
     */
    Component(Position & position, Direction direction);

    /*!
     * \brief Destructor for a component object.
     */
    virtual ~Component() = default; // destructeur obligatoire car méthode virtual

    /*!
     * \brief Returns the position of the component.
     * \return The position of the component.
     */
    Position getPosition() const;

    /*!
     * \brief Returns the direction of the component.
     * \return The direction of the component.
     */
    Direction getDirection() const;

    /*!
     * \brief Returns the text type of the component.
     * \return The text type of the component.
     */
    virtual TextType getText() const;

    /*!
     * \brief Returns the material type of the component.
     * \return The material type of the component.
     */
    virtual MaterialType getMaterial() const;

    /*!
     * \brief Returns the text representation of the component as a string.
     * \return The text representation of the component as a string.
     */
    virtual std::string getTextAsString() const = 0;

    /*!
     * \brief Returns the string representation of the component for display purposes.
     * \return The string representation of the component for display purposes.
     */
    virtual std::string strDisplay() const = 0;

    /*!
     * \brief Moves the component in the given direction.
     * \param dir The direction to move the component.
     */
    void move(Direction dir);

    /*!
     * \brief Sets the position of the component to the given position.
     * \param position The position to set the component to.
     */
    void setPosition(Position & position);

    /*!
     * \brief Returns whether the component is steppable, meaning that
     * another component can step on the tile containing this component.
     * \return True if the component is steppable, false otherwise.
     */
    virtual bool isSteppable() = 0;

    /*!
     * \brief Returns whether the component is pushable.
     * \return True if the component is pushable, false otherwise.
     */
    virtual bool isPushable() = 0;

    /*!
     * \brief Returns whether the component can kill.
     * \return True if the component can kill, false otherwise.
     */
    virtual bool canKill() = 0;

    /*!
     * \brief Returns whether the component has "you" as a property.
     * \return True if the component has "you" as a property, false otherwise.
     */
    virtual bool isYou() = 0;

    /*!
     * \brief Returns whether the component is designated as "win".
     * \return True if the component is designated as "win", false otherwise.
     */
    virtual bool isWin() = 0;
};

#endif // COMPONENT_H

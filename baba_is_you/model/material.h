/*********************************************************************
 * @file  model/material.h
 *********************************************************************/

#ifndef MATERIAL_H
#define MATERIAL_H

#include <set>

#include "model/component.h"

enum class Property;

/*!
 * \brief The Material class represents a material component.
 */
class Material : public Component
{
    /*!
     * \brief type_ The type of material.
     */
    MaterialType type_;

    /*!
     * \brief properties_ A set of properties of the material.
     */
    std::set<Property> properties_ { };

    /*!
     * \brief isSteppable_ Indicates whether the material is steppable.
     */
    bool isSteppable_ { true };

    /*!
     * \brief isPushable_ Indicates whether the material is pushable.
     */
    bool isPushable_ { false };

    /*!
     * \brief canKill_ Indicates whether the material can kill.
     */
    bool canKill_ { false };

    /*!
     * \brief isYou_ Indicates whether the material has "you" as property.
     */
    bool isYou_ { false };

    /*!
     * \brief isWin_ Indicates whether the material has "win" as property.
     */
    bool isWin_ { false };

public:
    /*!
     * \brief Constructor for the material.
     * \param type The type of material.
     * \param position The position of the material on the board.
     * \param direction The direction in which the material is facing.
     */
    Material(MaterialType type, Position & position, Direction direction);

    /*!
     * \brief Material Constructor with a text representation, position and direction.
     * \param textRepresentation The text representation of the material.
     * \param position The position of the material on the board.
     * \param direction The direction in which the material is facing.
     */
    Material(std::string & textRepresentation, Position & position, Direction direction);

    /*!
     * \brief Destructor.
     */
    ~Material() override;

    /*!
     * \brief Returns the type of material.
     * \return The type of material.
     */
    MaterialType getType() const;

    /*!
     * \brief Returns the properties associated with the material.
     * \return The properties associated with the material.
     */
    std::set<Property> getProperties() const;

    /*!
     * \brief Returns the type of component as a MaterialType.
     * \return The type of component as a MaterialType.
     */
    MaterialType getMaterial() const override;

    /*!
     * \brief Returns a string representation of the material.
     * \return A string representation of the material.
     */
    std::string strDisplay() const override;

    /*!
     * \brief Returns a string representing the current material.
     * \return A string representing the current material.
     */
    std::string getTextAsString() const override;

    /*!
     * \brief Returns whether the material is steppable or not.
     * \return True if the material is steppable, false otherwise.
     */
    bool isSteppable() override;

    /*!
     * \brief Sets whether the material is steppable or not.
     * \param isSteppable True if the material must be set to steppable, false otherwise.
     */
    void setSteppable(bool isSteppable);

    /*!
     * \brief Returns whether the material is pushable.
     * \return True if the material is pushable, false otherwise.
     */
    bool isPushable() override;

    /*!
     * \brief Sets whether the material is pushable or not.
     * \param pushable Indicates whether the material must be set to pushable or not.
     */
    void setPushable(bool pushable);

    /*!
     * @brief Returns true if the current material has "kill" is its properties.
     * @return True if the material has "kill" in its properties.
     */
    bool canKill() override;

    /*!
     * \brief Sets whether the material can kill or not.
     * \param canKill Has the value true if the material can now kill, false otherwise.
     */
    void setCanKill(bool canKill);

    /**
     * @brief Returns true if the material has "you" as property.
     * @return True if the material has "you" as property.
     */
    bool isYou() override;

    /*!
     * \brief Sets whether the material is the player or not.
     * \param isYou The value to set.
     */
    void setIsYou(bool);

    /*!
     * \brief Indicates whether this material has "win" as property or not.
     * A material having "win" as property is one that, when it comes into contact
     * with the "you" material, it causes the player to win the level.
     * \return Whether this material has "win" as property.
     */
    bool isWin() override;

    /*!
     * \brief Updates the attributes of the material based on its properties.
     */
    void updateAttributes();

    /*!
     * \brief Sets the default properties of the material.
     */
    void setDefaultProperties();

    /*!
     * \brief Adds a property to the current material's properties.
     * \param property The property to add.
     */
    void addProperty(const Property &);

    /*!
     * \brief Removes all the current material's properties.
     */
    void clearProperties();
};

#endif // MATERIAL_H

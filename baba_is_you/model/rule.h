/*********************************************************************
 * @file  model/rule.h
 *********************************************************************/

#ifndef RULE_H
#define RULE_H

enum class MaterialType;
enum class Property;

/*!
 * \brief The Rule class represents a rule of the game. Examples of
 * rules are : "Baba is you", "Rock is stop", "Flag is win",... Given
 * that the "IS_TEXT" text component is in every rule, it was dropped
 * and only the materialType (left/subject of the rule) and the
 * property (right/object of the rule) are the attributes of this class.
 */
class Rule
{
    /*!
     * \brief materialType_ The type of the material that this rule applies to.
     */
    MaterialType materialType_;

    /*!
     * \brief property_ The property that this rule applies to.
     */
    Property property_;

public:
    /*!
     * \brief Constructs a Rule object with the given material type and property.
     * \param materialType The material type to set for this rule.
     * \param property The property to set for this rule.
     */
    Rule(MaterialType materialType, Property property);

    /*!
     * \brief Returns the material type associated with this rule.
     * \return The material type associated with this rule.
     */
    const MaterialType & getMaterialType() const;

    /*!
     * \brief Returns the property associated with this rule.
     * \return The property associated with this rule.
     */
    const Property & getProperty() const;

    bool operator==(const Rule& other) const;
};

#endif // RULE_H

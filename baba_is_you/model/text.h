/*********************************************************************
 * @file  model/text.h
 *********************************************************************/

#ifndef TEXT_H
#define TEXT_H

#include "model/component.h"

/*!
 * \brief The Text class represents a text component.
 */
class Text : public Component
{
    /*!
     * \brief type_ The type of the text.
     */
    TextType type_;

public:
    /*!
     * \brief Constructor of the Text object.
     * \param s The string to represent the text type.
     * \param position The position of the text.
     * \param direction The direction the text is facing.
     */
    Text(std::string & s, Position & position, Direction direction);

    /*!
     * \brief Destructor.
     */
    ~Text() override = default;

    /*!
     * \brief Gets the type of the text.
     * \return The type of the text.
     */
    TextType getType() const;

    /*!
     * \brief Gets type the text.
     * \return The type of the text.
     */
    TextType getText() const override;

    /*!
     * \brief Gets a string representation of the text type.
     * \return A string representation of the text type.
     */
    std::string strDisplay() const override;

    /*!
     * \brief Gets the text type as a string.
     * \return The text type as a string.
     */
    std::string getTextAsString() const override;

    /*!
     * \brief Indicates whether the the text is steppable or not.
     * \return Always false, as text is not steppable.
     */
    bool isSteppable() override;

    /*!
     * \brief Determines if the text is pushable.
     * \return Always true, as text is pushable.
     */
    bool isPushable() override;

    /*!
     * \brief Determines if the text can kill the player.
     * \return Always false, as text cannot kill the player.
     */
    bool canKill() override;

    /*!
     * \brief Determines if the text represents the player.
     * \return Always false, as text cannot represent the player.
     */
    bool isYou() override;

    /*!
     * \brief Determines if the text represents the win condition.
     * \return Always false, as text cannot represent the win condition.
     */
    bool isWin() override;
};

#endif // TEXT_H

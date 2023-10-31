/*********************************************************************
 * @file  model/position.h
 *********************************************************************/

#ifndef POSITION_H
#define POSITION_H

#include <iostream>

enum class Direction;

/*!
 * \brief The Position class represents a position in a two-dimensional space.
 */
class Position
{
    /*!
     * \brief x_ The x-coordinate (horizontal) of the position.
     */
    int x_ { 0 };

    /*!
     * \brief y_ The y-coordinate (vertical) of the position.
     */
    int y_ { 0 };

public:
    /*!
     * \brief Constructor for a position using x and y coordinates.
     * \param x The x-coordinate of the position.
     * \param y The y-coordinate of the position.
     */
    Position(int x, int y);

    /*!
     * \brief Constructor for a position using a position and the direction to apply.
     * \param start The starting position.
     * \param direction The direction to move from the starting position.
     */
    Position(const Position &, Direction);

    /*!
     * \brief Returns the x-coordinate of the position.
     * \return The x-coordinate of the position.
     */
    int getX() const;

    /*!
     * \brief Sets the x-coordinate of the position.
     * \param x The new x-coordinate of the position.
     */
    void setX(int x);

    /*!
     * \brief Returns the y-coordinate of the position.
     * \return The y-coordinate of the position.
     */
    int getY() const;

    /*!
     * \brief Sets the y-coordinate of the position.
     * \param y The new y-coordinate of the position.
     */
    void setY(int y);

    /*!
     * \brief Moves the position in the given direction.
     * \param direction The direction in which to move the position.
     */
    void move(Direction);
};

#endif // POSITION_H

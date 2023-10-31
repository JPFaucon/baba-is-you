/*********************************************************************
 * @file  utils/directionutility.h
 *********************************************************************/

#ifndef DIRECTIONUTILITY_H
#define DIRECTIONUTILITY_H

#include <unordered_map>
#include <iostream>

enum class Direction;

/*!
 * \brief The DirectionUtility class provides utility functions
 * for working with directions in the game.
 */
class DirectionUtility
{
private:
    /*!
     * \brief intToDirectionMap_ Map from an unsigned integer value
     * to a Direction enumeration value. It is used to convert an
     * integer value to the corresponding Direction value.
     */
    static std::unordered_map<unsigned int, Direction> intToDirectionMap_;

    /*!
     * \brief directionToIntMap_ Map from a Direction enumeration value
     * to an unsigned integer value. It is used to convert a Direction
     * value to the corresponding integer value.
     */
    static std::unordered_map<Direction, unsigned int> directionToIntMap_;

    /*!
     * \brief directionToDxDyMap_ Map from a Direction enumeration value
     * to a pair of integers that represent the change in the x and y
     * coordinates for the given direction. It is used to calculate the
     * new position in a grid or on a map given a direction of movement.
     */
    static std::unordered_map<Direction, std::pair<int, int>> directionToDxDyMap_;

public:
    /*!
     * \brief Constructs a new DirectionUtility object.
     */
    DirectionUtility();

    /*!
     * \brief Converts an unsigned int value to a Direction object.
     * \param dir The unsigned int value to convert.
     * \return The corresponding Direction object.
     * \throw std::invalid_argument If the given value is not a valid direction.
     */
    static Direction intToDirection(unsigned int dir);

    /*!
     * \brief Converts a Direction object to an unsigned int value.
     * \param direction The Direction object to convert.
     * \return The corresponding unsigned int value.
     * \throw std::invalid_argument If the given direction is not a valid direction.
     */
    static unsigned int directionToInt(Direction direction);

    /*!
     * \brief Returns the (dx, dy) pair corresponding to the given Direction object.
     * \param direction The Direction object to get the (dx, dy) pair for.
     * \return The (dx, dy) pair corresponding to the given Direction object.
     * \throw std::invalid_argument If the given direction is not a valid direction.
     */
    static std::pair<int, int> directionToDxDy(Direction direction);
};

#endif // DIRECTIONUTILITY_H

/*********************************************************************
 * @file  model/enums.h
 *********************************************************************/

#ifndef ENUMS_H
#define ENUMS_H

/*!
 * \brief The MaterialType enum enumerates all the possible Material types.
 */
enum class MaterialType
{
    MTNULL=0,
    BABA,
    FLAG,
    GRASS,
    LAVA,
    ROCK,
    WALL,
    WATER,
};

/*!
 * \brief The TextType enum enumerates all the possible Text types.
 */
enum class TextType
{
    TEXT_NULL=0,
    TEXT_BABA,
    TEXT_FLAG,
    TEXT_GRASS,
    TEXT_IS,
    TEXT_KILL,
    TEXT_LAVA,
    TEXT_PUSH,
    TEXT_ROCK,
    TEXT_SINK,
    TEXT_STOP,
    TEXT_WALL,
    TEXT_WATER,
    TEXT_WIN,
    TEXT_YOU,
};

/*!
 * \brief The Property enum enumerates all the possible properties appliable on a material.
 */
enum class Property
{
    IS_BABA,
    IS_FLAG,
    IS_GRASS,
    IS_KILL,
    IS_LAVA,
    IS_PUSH,
    IS_ROCK,
    IS_SINK,
    IS_STOP,
    IS_WALL,
    IS_WATER,
    IS_WIN,
    IS_YOU,
};

#endif // ENUMS_H

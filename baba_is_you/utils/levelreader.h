/*********************************************************************
 * @file  utils/levelreader.h
 *********************************************************************/

#ifndef LEVELREADER_H
#define LEVELREADER_H

#include <string>
#include <vector>
#include <QFile>
#include <QString>
#include <sstream>

/*!
<<<<<<< HEAD
 * \brief The LevelReader class represents a level reader that
 * reads a file describing a game level and provides methods
 * to extract information from the data in the file.
 *
=======
 * \brief The LevelReader class is responsible for reading data
 * describing a level from a file and returning it as a string.
>>>>>>> tests
 */
class LevelReader
{
private:

    /*!
     * \brief level_ data describing the level
     */
    std::string level_;

public:

    /*!
     * \brief Constructor of the LevelReader class
     *
     * \throw std::runtime_error if could not open the file
     *
     * \param nrLevel the level number
     */
    LevelReader(unsigned int nrLevel);

    /*!
     * \brief reads the file and return the data describing the level as a string
     *
     * \param nrLevel the level number
     *
     * \throw std::runtime_error if could not open the file
     *
     * \return the data describing the level as a string
     */
    std::string readFile(unsigned int nrLevel);

    /*!
     * \brief gets the number of columns
     *
     * \throw std::invalid_argument if the data describing the level doesn't contains the number of columns
     *
     * \return the number of columns
     */
    int getNbCol();

    /*!
     * \brief gets the number of rows
     *
     * \throw std::invalid_argument if the data describing the level doesn't contains the number of rows
     *
     * \return the number of rows
     */
    int getNbRows();

    /*!
     * \brief get the coordinates of the components of the level
     *
     * \return a vector containing pairs of components name and vector of integer
     * (containing the component coordinates and the direction of the component
     * (the direction is optional))
     */
    std::vector<std::pair<std::string, std::vector<int>>> getComponentsCoordinates();
};

#endif // LEVELREADER_H

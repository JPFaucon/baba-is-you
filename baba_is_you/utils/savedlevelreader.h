/*********************************************************************
 * @file  utils/savedlevelreader.h
 *********************************************************************/

#ifndef SAVEDLEVELREADER_H
#define SAVEDLEVELREADER_H


#include <string>
#include <vector>
#include <QFile>
#include <QString>
#include <sstream>

/*!
 * \brief The SavedLevelReader class is responsible for reading data
<<<<<<< HEAD
 * from a saved level file.
=======
 * describing a saved level from a file and returning it as a string.
>>>>>>> tests
 *
 */
class SavedLevelReader
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
     */
    SavedLevelReader();

    /*!
     * \brief reads the file and return the data describing the level as a string
     *
     * \throw std::runtime_error if could not open the file
     *
     * \return the data describing the level as a string
     */
    std::string readFile();

    /*!
     * \brief gets the number of the level
     *
     * \throw std::invalid_argument if the data describing the level doesn't contains the number of the level
     *
     * \return the number of the level
     */
    int getNrLevel();

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

    /*!
     * @brief Saves the level data to a file named "saved_level.txt".
     *
     * @param level The string containing the level data to be saved.
     *
     * @throw std::runtime_error if the file could not be opened or written to.
     */
    static void saveLevel(std::string& level);

    /*!
     * \brief Takes a string as input, and returns a vector containing
     * each line of the input string as a separate string element.
     *
     * \param level The input string to be split into lines
     *
     * \return A vector of strings, where each element is a separate line from the input string
     */
    std::vector<std::string> getLines(const std::string& level);

    /*!
     * \brief Takes a string and an integer as input, and returns the i-th whitespace-separated
     * number from the string. The numbers are assumed to be located on the first line of the
     * input string.
     *
     * \param i The index of the desired number (0-indexed)
     * \param str The input string containing whitespace-separated numbers on the first line
     *
     * \throw std::invalid_argument if i is out of bounds for the input string
     *
     * \return The i-th whitespace-separated number from the input string
     */
    int getIthNumber(int i, std::string& str);
};

#endif // SAVEDLEVELREADER_H

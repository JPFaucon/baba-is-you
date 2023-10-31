#include "savedlevelreader.h"

std::string SavedLevelReader::readFile()
{
    std::string filePath = "saved_level.txt";
    QFile file(filePath.c_str());
    if (!file.exists()) {
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                file.close();
            } else {
                throw std::runtime_error("Could not create file");
            }
        }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error("Could not open file");
    }

    QString content = file.readAll();

    file.close();

    return content.toStdString();
}

SavedLevelReader::SavedLevelReader() : level_ {readFile()}
{
    if (level_.size() == 0)
        throw std::invalid_argument("Le fichier est vide");
}

std::vector<std::string> SavedLevelReader::getLines(const std::string& level)
{
    std::vector<std::string> lines;
    std::istringstream iss(level);
    std::string line;
    while(std::getline(iss, line))
    {
        lines.push_back(line);
    }
    return lines;
}

// Gets the i-th number of the first line of level_
int SavedLevelReader::getIthNumber(int i, std::string& str)
{
    std::istringstream iss(str);
    std::vector<std::string> elements(
                std::istream_iterator<std::string>{iss},
                std::istream_iterator<std::string>{});
    if(i < 0 || i >= elements.size())
    {
        throw std::invalid_argument("Wrong index !");
    }
    return std::stoi(elements[i]);
}

int SavedLevelReader::getNrLevel()
{
    return getIthNumber(0, getLines(level_)[0]);
}

int SavedLevelReader::getNbCol()
{
    return getIthNumber(1, getLines(level_)[1]);
}

int SavedLevelReader::getNbRows()
{
    return getIthNumber(0, getLines(level_)[1]);
}

std::vector<std::pair<std::string, std::vector<int>>> SavedLevelReader::getComponentsCoordinates()
{
    std::vector<std::pair<std::string, std::vector<int>>> compCoord;
    std::vector<std::string> lines = getLines(level_);
    for(unsigned i = 2; i < lines.size(); ++i)
    {
        std::istringstream iss(lines[i]);
        std::vector<std::string> elements(
                    std::istream_iterator<std::string>{iss},
                    std::istream_iterator<std::string>{});
        std::vector<int> datas;
        for(unsigned j = 1; j < elements.size(); ++j)
        {
            datas.push_back(std::stoi(elements[j]));
        }
        compCoord.push_back(std::make_pair(elements[0], datas));
    }
    return compCoord;
}

void SavedLevelReader::saveLevel(std::string& level)
{
    QString filePath = "saved_level.txt";

    QFile file(filePath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        throw std::runtime_error("Could not open file");
    }

    QByteArray dataLevel = level.c_str();
    int ret = file.write(dataLevel);
    if (ret == -1)
    {
        throw std::runtime_error("Could not write in file");
    }

    file.close();
}

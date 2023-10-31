#include "levelreader.h"

std::string LevelReader::readFile(unsigned int nrLevel)
{
    std::string filePath = ":/levels/level_" + std::to_string(nrLevel) + ".txt";
    QFile file(filePath.c_str());
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error("Could not open file");
    }

    QString content = file.readAll();

    file.close();

    return content.toStdString();
}

LevelReader::LevelReader(unsigned int nrLevel) : level_ {readFile(nrLevel)}
{}

std::vector<std::string> getLines(const std::string& level)
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
int getIthNumber(int i, std::string& str)
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

int LevelReader::getNbCol()
{
    return getIthNumber(1, getLines(level_)[0]);
}

int LevelReader::getNbRows()
{
    return getIthNumber(0, getLines(level_)[0]);
}

std::vector<std::pair<std::string, std::vector<int>>> LevelReader::getComponentsCoordinates()
{
    std::vector<std::pair<std::string, std::vector<int>>> compCoord;
    std::vector<std::string> lines = getLines(level_);
    for(unsigned i = 1; i < lines.size(); ++i)
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

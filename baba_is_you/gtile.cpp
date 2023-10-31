#include "gtile.h"
#include "model/enums.h"
#include "model/material.h"
#include "model/text.h"

GTile::GTile(const Tile &tile, QLabel * parent):
    QLabel (parent),
    tile_{tile}
{}

void GTile::updateSprite()
{
    this->clear();
    QString imagePath;
    const Component* component = tile_.getTopComponent();

    if (auto material = dynamic_cast<const Material *>(component))
    {
        std::map<MaterialType, std::string> stringMap = {
            {MaterialType::BABA, ":/sprites/baba.png"},
            {MaterialType::FLAG, ":/sprites/flag.png"},
            {MaterialType::GRASS, ":/sprites/grass.png"},
            {MaterialType::LAVA, ":/sprites/lava.png"},
            {MaterialType::ROCK, ":/sprites/rock.png"},
            {MaterialType::WALL, ":/sprites/wall.png"},
            {MaterialType::WATER, ":/sprites/water.png"}
        };
        auto it = stringMap.find(material->getMaterial());
        if (it != stringMap.end())
        {
            const std::string path = it->second;
            imagePath = QString::fromStdString(path);
        }
    }
    else if (auto text = dynamic_cast<const Text *>(component))
    {
        std::map<TextType, std::string> stringMap = {
            {TextType::TEXT_IS, ":/sprites/text_is.png"},
            {TextType::TEXT_BABA, ":/sprites/text_baba.png"},
            {TextType::TEXT_FLAG, ":/sprites/text_flag.png"},
            {TextType::TEXT_GRASS, ":/sprites/text_grass.png"},
            {TextType::TEXT_KILL, ":/sprites/text_kill.png"},
            {TextType::TEXT_LAVA, ":/sprites/text_lava.png"},
            {TextType::TEXT_PUSH, ":/sprites/text_push.png"},
            {TextType::TEXT_ROCK, ":/sprites/text_rock.png"},
            {TextType::TEXT_SINK, ":/sprites/text_sink.png"},
            {TextType::TEXT_STOP, ":/sprites/text_stop.png"},
            {TextType::TEXT_WALL, ":/sprites/text_wall.png"},
            {TextType::TEXT_WATER, ":/sprites/text_water.png"},
            {TextType::TEXT_WIN, ":/sprites/text_win.png"},
            {TextType::TEXT_YOU, ":/sprites/text_you.png"}
        };
        auto it = stringMap.find(text->getText());
        if (it != stringMap.end())
        {
            const std::string path = it->second;
            imagePath = QString::fromStdString(path);
        }
    }
    QPixmap image(imagePath);

    if (image.isNull()) {
        this->setStyleSheet("background-color: black");
    } else {
        this->setPixmap(image.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        this->setScaledContents(true);
    }
}

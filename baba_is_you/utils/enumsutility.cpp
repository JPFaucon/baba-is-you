#include "enumsutility.h"
#include "model/enums.h"

EnumsUtility::EnumsUtility()
{}

std::unordered_map<std::string, TextType> EnumsUtility::stringTextTypeMap_ = {
    {"is", TextType::TEXT_IS},
    {"text_baba", TextType::TEXT_BABA},
    {"text_flag", TextType::TEXT_FLAG},
    {"text_grass", TextType::TEXT_GRASS},
    {"kill", TextType::TEXT_KILL},
    {"text_lava", TextType::TEXT_LAVA},
    {"push", TextType::TEXT_PUSH},
    {"text_rock", TextType::TEXT_ROCK},
    {"sink", TextType::TEXT_SINK},
    {"stop", TextType::TEXT_STOP},
    {"text_wall", TextType::TEXT_WALL},
    {"text_water", TextType::TEXT_WATER},
    {"win", TextType::TEXT_WIN},
    {"you", TextType::TEXT_YOU}
};

std::unordered_map<TextType, std::string> EnumsUtility::textTypeToStringMap_ = {
    {TextType::TEXT_IS, " is"},
    {TextType::TEXT_BABA, " Ba"},
    {TextType::TEXT_FLAG, " Fl"},
    {TextType::TEXT_GRASS, " Gr"},
    {TextType::TEXT_KILL, " Kl"},
    {TextType::TEXT_LAVA, " La"},
    {TextType::TEXT_PUSH, " Pu"},
    {TextType::TEXT_ROCK, " Rc"},
    {TextType::TEXT_SINK, " Si"},
    {TextType::TEXT_STOP, " St"},
    {TextType::TEXT_WALL, " Wl"},
    {TextType::TEXT_WATER, " Wt"},
    {TextType::TEXT_WIN, " Wi"},
    {TextType::TEXT_YOU, " Yu"}
};

std::unordered_map<TextType, std::string> EnumsUtility::textTypeAsStringMap_ = {
    {TextType::TEXT_IS, "is"},
    {TextType::TEXT_BABA, "text_baba"},
    {TextType::TEXT_FLAG, "text_flag"},
    {TextType::TEXT_GRASS, "text_grass"},
    {TextType::TEXT_KILL, "kill"},
    {TextType::TEXT_LAVA, "text_lava"},
    {TextType::TEXT_PUSH, "push"},
    {TextType::TEXT_ROCK, "text_rock"},
    {TextType::TEXT_SINK, "sink"},
    {TextType::TEXT_STOP, "stop"},
    {TextType::TEXT_WALL, "text_wall"},
    {TextType::TEXT_WATER, "text_water"},
    {TextType::TEXT_WIN, "win"},
    {TextType::TEXT_YOU, "you"}
};

std::unordered_map<std::string, MaterialType> EnumsUtility::stringMaterialTypeMap_ = {
    {"baba", MaterialType::BABA},
    {"flag", MaterialType::FLAG},
    {"grass", MaterialType::GRASS},
    {"rock", MaterialType::ROCK},
    {"lava", MaterialType::LAVA},
    {"wall", MaterialType::WALL},
    {"water", MaterialType::WATER}
};

std::unordered_map<MaterialType, std::string> EnumsUtility::materialTypeToStringMap_ = {
    {MaterialType::BABA, " X "},
    {MaterialType::FLAG, " P "},
    {MaterialType::GRASS, " . "},
    {MaterialType::LAVA, " * "},
    {MaterialType::ROCK, " o "},
    {MaterialType::WALL, " | "},
    {MaterialType::WATER, " ~ "}
};

std::unordered_map<MaterialType, std::string> EnumsUtility::materialTypeAsStringMap_ = {
    {MaterialType::BABA, "baba"},
    {MaterialType::FLAG, "flag"},
    {MaterialType::GRASS, "grass"},
    {MaterialType::LAVA, "lava"},
    {MaterialType::ROCK, "rock"},
    {MaterialType::WALL, "wall"},
    {MaterialType::WATER, "water"}
};

std::unordered_map<Property, MaterialType> EnumsUtility::propertyToMaterialTypeMap_ = {
    {Property::IS_BABA, MaterialType::BABA},
    {Property::IS_FLAG, MaterialType::FLAG},
    {Property::IS_GRASS, MaterialType::GRASS},
    {Property::IS_LAVA, MaterialType::LAVA},
    {Property::IS_ROCK, MaterialType::ROCK},
    {Property::IS_WALL, MaterialType::WALL},
    {Property::IS_WATER, MaterialType::WATER}
};

std::unordered_map<TextType, MaterialType> EnumsUtility::textTypeToMaterialTypeMap_ = {
    {TextType::TEXT_BABA, MaterialType::BABA},
    {TextType::TEXT_FLAG, MaterialType::FLAG},
    {TextType::TEXT_ROCK, MaterialType::ROCK},
    {TextType::TEXT_WALL, MaterialType::WALL},
    {TextType::TEXT_GRASS, MaterialType::GRASS},
    {TextType::TEXT_WATER, MaterialType::WATER},
    {TextType::TEXT_LAVA, MaterialType::LAVA}
};

std::unordered_map<TextType, Property> EnumsUtility::textTypeToPropertyMap_ = {
    {TextType::TEXT_BABA, Property::IS_BABA},
    {TextType::TEXT_FLAG, Property::IS_FLAG},
    {TextType::TEXT_ROCK, Property::IS_ROCK},
    {TextType::TEXT_WALL, Property::IS_WALL},
    {TextType::TEXT_GRASS, Property::IS_GRASS},
    {TextType::TEXT_WATER, Property::IS_WATER},
    {TextType::TEXT_LAVA, Property::IS_LAVA},
    {TextType::TEXT_YOU, Property::IS_YOU},
    {TextType::TEXT_WIN, Property::IS_WIN},
    {TextType::TEXT_STOP, Property::IS_STOP},
    {TextType::TEXT_PUSH, Property::IS_PUSH},
    {TextType::TEXT_SINK, Property::IS_SINK},
    {TextType::TEXT_KILL, Property::IS_KILL}
};

TextType EnumsUtility::stringToTextType(std::string & s)
{
    auto it = stringTextTypeMap_.find(s);
    if (it != stringTextTypeMap_.end())
    {
        return it->second;
    }
    else
    {
        throw std::invalid_argument("unrecognized string (text type): " + s);
    }
}

std::string EnumsUtility::textTypeToString(TextType textType)
{
    auto it = textTypeToStringMap_.find(textType);
    if (it != textTypeToStringMap_.end())
    {
        return it->second;
    }
    else
    {
        return " ??";
    }
}

std::string EnumsUtility::textTypeAsString(TextType textType)
{
    auto it = textTypeAsStringMap_.find(textType);
    if (it != textTypeAsStringMap_.end())
    {
        return it->second;
    }
    else
    {
        return " ??";
    }
}

MaterialType EnumsUtility::stringToMaterialType(std::string& s)
{
    auto it = stringMaterialTypeMap_.find(s);
    if (it != stringMaterialTypeMap_.end())
    {
        return it->second;
    }
    else
    {
        throw std::invalid_argument("unrecognized string (material type): " + s);
    }
}

std::string EnumsUtility::materialTypeToString(MaterialType type)
{
    auto it = materialTypeToStringMap_.find(type);
    if (it != materialTypeToStringMap_.end())
    {
        return it->second;
    }
    else
    {
        return " ? ";
    }
}

std::string EnumsUtility::materialTypeAsString(MaterialType type)
{
    auto it = materialTypeAsStringMap_.find(type);
    if (it != materialTypeAsStringMap_.end())
    {
        return it->second;
    }
    else
    {
        return " ? ";
    }
}

MaterialType EnumsUtility::propertyToMaterialType(Property property)
{
    auto it = propertyToMaterialTypeMap_.find(property);
    if (it != propertyToMaterialTypeMap_.end())
    {
        return it->second;
    }
    else
    {
        return MaterialType::MTNULL;
    }
}

MaterialType EnumsUtility::textTypeToMaterialType(TextType text)
{
    auto it = textTypeToMaterialTypeMap_.find(text);
    if (it != textTypeToMaterialTypeMap_.end())
    {
        return it->second;
    }
    else
    {
        throw std::invalid_argument("Text is not a material");
    }
}

Property EnumsUtility::textTypeToProperty(TextType text)
{
    auto it = textTypeToPropertyMap_.find(text);
    if (it != textTypeToPropertyMap_.end())
    {
        return it->second;
    }
    else
    {
        throw std::invalid_argument("Text is not a property");
    }
}


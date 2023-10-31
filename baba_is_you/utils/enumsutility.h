/*********************************************************************
 * @file  utils/enumsutility.h
 *********************************************************************/

#ifndef ENUMSUTILITY_H
#define ENUMSUTILITY_H

#include <iostream>
#include <unordered_map>

enum class TextType;
enum class MaterialType;
enum class Property;

/*!
 * \brief The EnumsUtility class provides utility functions to work
 * with enumerations used in the game. The methods prototypes are
 * self-explanatory.
 */
class EnumsUtility
{
private:
    static std::unordered_map<std::string, TextType> stringTextTypeMap_;
    static std::unordered_map<TextType, std::string> textTypeToStringMap_;
    static std::unordered_map<TextType, std::string> textTypeAsStringMap_;

    static std::unordered_map<std::string, MaterialType> stringMaterialTypeMap_;
    static std::unordered_map<MaterialType, std::string> materialTypeToStringMap_;
    static std::unordered_map<MaterialType, std::string> materialTypeAsStringMap_;

    static std::unordered_map<Property, MaterialType> propertyToMaterialTypeMap_;
    static std::unordered_map<TextType, MaterialType> textTypeToMaterialTypeMap_;
    static std::unordered_map<TextType, Property> textTypeToPropertyMap_;

public:

    EnumsUtility();

    static TextType stringToTextType(std::string &);
    static std::string textTypeToString(TextType);
    static std::string textTypeAsString(TextType);

    static MaterialType stringToMaterialType(std::string&);
    static std::string materialTypeToString(MaterialType);
    static std::string materialTypeAsString(MaterialType);

    static MaterialType propertyToMaterialType(Property);
    static MaterialType textTypeToMaterialType(TextType);
    static Property textTypeToProperty(TextType);
};


#endif // ENUMSUTILITY_H

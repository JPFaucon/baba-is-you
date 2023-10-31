#include "model/rule.h"

Rule::Rule(MaterialType m, Property p)
    : materialType_ {m},
      property_ {p}
{}

const MaterialType & Rule::getMaterialType() const
{
    return materialType_;
}

const Property & Rule::getProperty() const
{
    return property_;
}

bool Rule::operator==(const Rule& other) const {
    return materialType_ == other.materialType_
            && property_ == other.property_;
}

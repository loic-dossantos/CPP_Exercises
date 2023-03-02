#include "StringLeaf.hpp"

StringLeaf::StringLeaf(std::string value)
    : Leaf(NodeKind::STRING)
    , _value { value }
{}

std::string StringLeaf::print() const
{
    return '"' + _value + '"';
}

const std::string& StringLeaf::data() const
{
    return _value;
}

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(std::string value)
{
    return std::make_unique<StringLeaf>(value);
}
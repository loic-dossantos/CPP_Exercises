#include "IntLeaf.hpp"

IntLeaf::IntLeaf(int value)
    : Leaf(NodeKind::INT)
    , _value { value }
{}

std::string IntLeaf::print() const
{
    return std::to_string(_value);
}

int IntLeaf::data() const
{
    return _value;
}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int value)
{
    return std::make_unique<IntLeaf>(value);
}
#pragma once

#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>

class StringLeaf : public Leaf
{
public:
    StringLeaf(std::string value);

    std::string print() const;

    const std::string& data() const;

    static std::unique_ptr<StringLeaf> make_ptr(std::string value);

private:
    std::string _value {};
};
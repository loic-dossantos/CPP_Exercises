#pragma once

#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>

class IntLeaf : public Leaf
{
public:
    IntLeaf(int value);

    std::string print() const;

    int data() const;

    static std::unique_ptr<IntLeaf> make_ptr(int value);

private:
    int _value {};
};
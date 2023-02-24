#pragma once

#include <string>

#include "Leaf.hpp"
#include "NodeKind.hpp"

class IntLeaf : public Leaf {
    public:
        IntLeaf(int value) : Leaf(NodeKind::INT), _value{value} {}

        std::string print() const {
            return std::to_string(_value);
        }

        int data() const {
            return _value;
        }

    private:
        int _value {};
};
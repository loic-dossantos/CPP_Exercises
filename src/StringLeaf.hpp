#pragma once

#include <string>

#include "Leaf.hpp"
#include "NodeKind.hpp"

class StringLeaf : public Leaf {
    public:
        StringLeaf(std::string value) : Leaf(NodeKind::STRING), _value{value} {}

        std::string print() const {
            return '"' + _value + '"';
        }

        std::string data() const {
            return _value;
        }

    private:
        std::string _value {};
};
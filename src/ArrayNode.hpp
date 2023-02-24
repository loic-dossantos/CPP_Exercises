#pragma once

#include <string>

#include "NodeKind.hpp"
#include "Node.hpp"

class ArrayNode : public Node {
    public:
        ArrayNode() : Node(NodeKind::ARRAY) {}

        std::string print() const override {return "[]";}

    private:
};
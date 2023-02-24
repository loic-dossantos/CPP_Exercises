#pragma once

#include <string>

#include "NodeKind.hpp"
#include "Node.hpp"

class ObjectNode : public Node {
    public:
        ObjectNode() : Node(NodeKind::OBJECT) {}

        std::string print() const override {return "{}";}

    private:
};
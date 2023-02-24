#pragma once

#include <memory>

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

class Node : public InstanceCounter {
    public:
        Node() {}

        Node(NodeKind kind) : _kind{kind} {}

        NodeKind kind() {
            return _kind;
        }

        virtual std::string print() const = 0;


    private:
        NodeKind _kind {};
};

using NodePtr = std::make_unique<Node>();
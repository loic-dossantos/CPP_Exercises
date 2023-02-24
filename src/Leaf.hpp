#pragma once

#include "Node.hpp"

class Leaf : public Node {
    public:
        Leaf() {}

        Leaf(NodeKind kind) : Node(kind) {}

    private:
};
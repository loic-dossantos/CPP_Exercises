#pragma once

#include "Node.hpp"

class Leaf : public Node
{
public:
    Leaf(NodeKind kind);

    virtual int height();

    virtual int node_count();

private:
};
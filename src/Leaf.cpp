#include "Leaf.hpp"

Leaf::Leaf(NodeKind kind)
    : Node(kind)
{}

int Leaf::height()
{
    return 0;
}

int Leaf::node_count()
{
    return 1;
}
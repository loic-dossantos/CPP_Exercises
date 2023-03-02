#include "Node.hpp"

Node::Node(NodeKind kind)
    : _kind { kind }
{}

NodeKind Node::kind()
{
    return _kind;
}
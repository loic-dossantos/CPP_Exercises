#pragma once

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <memory>

class Node : public InstanceCounter
{
public:
    virtual ~Node() = default;

    Node(NodeKind kind);

    NodeKind kind();

    virtual std::string print() const = 0;

    virtual int height() const = 0;

    virtual int node_count() const = 0;

private:
    NodeKind _kind {};
};

using NodePtr = std::unique_ptr<Node>;
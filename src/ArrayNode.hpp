#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>
#include <vector>

class ArrayNode : public Node
{
public:
    ArrayNode();

    std::string print() const override;

    static std::unique_ptr<ArrayNode> make_ptr();

    int child_count() const;

    void push_back(NodePtr elem);

    int height();

    int node_count();

private:
    std::vector<NodePtr> _array {};
};
#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

#include <map>
#include <memory>
#include <string>

class ObjectNode : public Node
{
public:
    ObjectNode();

    std::string print() const override;

    static std::unique_ptr<ObjectNode> make_ptr();

    int child_count() const;

    void insert(std::string key, NodePtr value);

    static std::unique_ptr<ObjectNode> make_ptr(std::map<std::string, NodePtr> map);

    int height();

    int node_count();

private:
    std::map<std::string, NodePtr> _map {};
};
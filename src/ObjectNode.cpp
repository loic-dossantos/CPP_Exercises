#include "ObjectNode.hpp"

ObjectNode::ObjectNode()
    : Node(NodeKind::OBJECT)
{}

std::string ObjectNode::print() const
{
    std::string str       = "{";
    std::string delimitor = "";

    for (auto it = _map.begin(); it != _map.end(); it++)
    {
        str += delimitor;
        str += "\"" + it->first + "\":";
        str += it->second->print();
        delimitor = ",";
    }
    str += "}";
    return str;
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr()
{
    return std::make_unique<ObjectNode>();
}

int ObjectNode::child_count() const
{
    return _map.size();
}

void ObjectNode::insert(std::string key, NodePtr value)
{
    _map.emplace(std::move(key), std::move(value));
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr(std::map<std::string, NodePtr> data)
{
    auto result  = std::make_unique<ObjectNode>();
    result->_map = std::move(data);
    return result;
}

int ObjectNode::height()
{
    int max = 0;
    for (auto it = _map.begin(); it != _map.end(); it++)
    {
        if (it->second->height() > max)
        {
            max = it->second->height();
        }
    }
    return max + 1;
}

int ObjectNode::node_count()
{
    int sum = 0;
    for (auto it = _map.begin(); it != _map.end(); it++)
    {
        sum += it->second->node_count();
    }
    return sum + 1;
}
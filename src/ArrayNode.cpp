#include "ArrayNode.hpp"

ArrayNode::ArrayNode()
    : Node(NodeKind::ARRAY)
{}

std::string ArrayNode::print() const
{
    std::string str       = "[";
    std::string delimitor = "";

    for (unsigned i = 0; i < _array.size(); i++)
    {
        str += delimitor + _array[i]->print();
        delimitor = ",";
    }

    str += "]";
    return str;
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr()
{
    return std::make_unique<ArrayNode>();
}

int ArrayNode::child_count() const
{
    return _array.size();
}

void ArrayNode::push_back(NodePtr elem)
{
    _array.push_back(std::move(elem));
}

int ArrayNode::height()
{
    int max = 0;
    for (auto it = _array.begin(); it != _array.end(); it++)
    {
        if (it->get()->height() > max)
        {
            max = it->get()->height();
        }
    }
    return max + 1;
}

int ArrayNode::node_count()
{
    int sum = 0;
    for (auto it = _array.begin(); it != _array.end(); it++)
    {
        sum += it->get()->node_count();
    }
    return sum + 1;
}
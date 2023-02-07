#pragma once
#include "PlushStore.hpp"

#include <iostream>
#include <string>

class Kid
{
public:
    Kid(std::string name, int money)
        : _name(name)
        , _money(money) {}

    std::string get_name() const { return _name; }

    int get_money() const { return _money; }

    void buy_plush(PlushStore plush_store) {}

private:
    std::string _name {};
    int         _money { 0 };
};

std::ostream& operator<<(std::ostream& stream, const Kid& k) {
    return stream << k.get_name() << " has " << k.get_money() << " euros.";
}
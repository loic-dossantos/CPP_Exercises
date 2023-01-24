#pragma once
#include <string>
#include <iostream>

class Kid {
public:
    Kid(std::string name, int money) : _name(name), _money(money)
    {}

    std::string get_name() const {
        return _name;
    }

    int get_money() const {
        return _money;
    }

private:
    std::string _name {};
    int _money {0};
};


std::ostream& operator<<(std::ostream& stream, const Kid& k) {
    return stream << k.get_name() << " has " << k.get_money() << " euros.";
}
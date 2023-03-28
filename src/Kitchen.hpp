#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <vector>

#include "../lib/Unit.hpp"

class Kitchen
{
private:
    std::vector<Unit*> _units{};
public:
    Kitchen() {};

    const Unit& register_unit(Unit unit) {
        _units.emplace(_units.end(), &unit);
        return unit;
    }

    const Unit* find_unit(const std::string &s) {
        for(auto it = _units.begin(); it != _units.end(); it++) {
            if((*it)->name == s) {
                return *it;
            }
        }
        return nullptr;
    }
};

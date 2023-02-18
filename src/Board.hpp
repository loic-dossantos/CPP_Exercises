#pragma once

#include "Monster.hpp"
#include "Spell.hpp"
#include "Trap.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Board {

public:
    bool monsters_full() { return _monsters.size() == 5; }

    bool spells_traps_full() { return _spells.size() + _traps.size() == 5; }

    bool put(std::unique_ptr<Monster> monster) {
        if (!monsters_full()) {
            _monsters.push_back(std::move(monster));
            return true;
        }
        return false;
    }

    bool put(std::unique_ptr<Spell> spell) {
        if (!spells_traps_full()) {
            _spells.push_back(std::move(spell));
            return true;
        }
        return false;
    }

    bool put(std::unique_ptr<Trap> trap) {
        if (!spells_traps_full()) {
            _traps.push_back(std::move(trap));
            return true;
        }
        return false;
    }

private:
    std::vector<std::unique_ptr<Monster>> _monsters {};
    std::vector<std::unique_ptr<Spell>>   _spells {};
    std::vector<std::unique_ptr<Trap>>    _traps {};
};
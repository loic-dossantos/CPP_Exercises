#pragma once

#include "Card.hpp"

#include <string>

#define TRAP_SYMBOL u8"罠"

enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

std::string to_string(TrapType trap_type) {
    switch (trap_type) {
    case TrapType::Normal:
        return "Normal";
    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";
    }
    return "";
}

class Trap : public Card
{

public:
    Trap(const std::string& id, const std::string& name, TrapType trap_type)
        : Card(id, CardType::Trap)
        , _trap_type { trap_type } {
        set_name(name);
        _symbol = TRAP_SYMBOL;
    }

    TrapType get_trap_type() const { return _trap_type; }

private:
    TrapType _trap_type {};
};
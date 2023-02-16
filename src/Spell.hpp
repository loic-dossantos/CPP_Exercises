#pragma once

#include <string>
#include "Card.hpp"

enum class SpellType {
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};

std::string to_string(SpellType spell_type) {
    switch(spell_type) {
        case SpellType::Normal: return "Normal";
        case SpellType::Equip: return "Equip";
        case SpellType::Continuous: return "Continuous";
        case SpellType::QuickPlay: return "Quick-Play";
        case SpellType::Field: return "Field";
    }
    return "";
}

class Spell : public Card {
    
    public:
        Spell(const std::string &id, const std::string &name, SpellType spell_type) 
        : Card(id, CardType::Spell), _spell_type {spell_type} {
            set_name(name);
        }

        SpellType get_spell_type() const {
            return _spell_type;
        }

    private:
        SpellType _spell_type {};
};
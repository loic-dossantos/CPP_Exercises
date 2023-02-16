#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"

#include <string>
#include <vector>

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(std::string s, PC pc)
        : _name { s }
        , _pc { pc } {
        for (auto i = 0; i < 6; i++) {
            _pokeballs.emplace_back(Pokeball());
        }
    }

    std::string name() const { return _name; }

    std::vector<Pokeball> pokeballs() const { return _pokeballs; }

    void capture(Pokemon pokemon) {
        pokemon.trainer();
        return;
        /*for (auto pokeball : _pokeballs) {
            if (!pokeball.empty()) {

                return;
            }
        }
        _pc.transfer(pokemon);*/
    }

    /*void store_in_pc(int pokemon_id) {
        for (auto pokeball : _pokeballs) {
            if (!pokeball.empty()) {
                if(pokeball.pokemon.id() == pokemon_id) {

                    return;
                }
            }
        }
    }*/

    /*void fetch_from_pc(std::string pokemon_name) {
        for (auto pokemon : _pc.pokemons()) {
            if(pokemon.name() == pokemon_name) {

                return;
            }
        }
    }*/

private:
    std::string           _name {};
    PC                    _pc {};
    std::vector<Pokeball> _pokeballs {};
};

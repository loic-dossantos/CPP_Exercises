#pragma once

#include "Pokemon.h"

#include <vector>

class Pokedex
{
public:
    Pokedex() {}

    void add(Pokemon pokemon) { _pokedex.emplace_back(pokemon); }

    std::vector<Pokemon> find(std::string pokemon_name) {
        std::vector<Pokemon> pokemons {};
        for (auto pokemon : _pokedex) {
            if (pokemon.name() == pokemon_name) {
                pokemons.emplace_back(pokemon);
            }
        }
        return pokemons;
    }

private:
    std::vector<Pokemon> _pokedex {};
};

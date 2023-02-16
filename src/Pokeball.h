#pragma once

#include "Pokemon.h"

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    Pokeball() {}

    bool empty() const { return _empty; }

    void store(PokemonPtr pokemon) {
        _pokemon = std::move(pokemon);
        _empty   = false;
    }

    Pokemon pokemon() { return *_pokemon; }

private:
    bool       _empty { true };
    PokemonPtr _pokemon;
};

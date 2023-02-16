#pragma once

#include <memory>
#include <string>

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(std::string s)
        : _name { s }
        , _id { counter++ } {}

    Pokemon(const Pokemon& p)
        : _name { p.name() }
        , _id { counter++ } {}

    std::string name() const { return _name; }

    int id() const { return _id; }

    Pokemon& operator=(const Pokemon& other) {
        _name    = other.name();
        _trainer = other.trainer();
        return *this;
    }

    void set_trainer(std::string trainer) { _trainer = trainer; }

    std::string trainer() const { return _trainer; }

private:
    std::string       _name {};
    int               _id {};
    static inline int counter {};
    std::string       _trainer {};
};

using PokemonPtr = std::unique_ptr<Pokemon>;
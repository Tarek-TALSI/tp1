#ifndef POKEDEX_HPP
#define POKEDEX_HPP
#include "Pokemon_vector.hpp"


class Pokedex : public PokemonVector {

private:

    Pokedex();
    ~Pokedex();

    Pokedex(const Pokedex&) = delete;
    Pokedex& operator=(const Pokedex&) = delete;
public:
    static Pokedex& getInstance();

    Pokemon getClonePokemon(int id) const;
    
};

#endif 
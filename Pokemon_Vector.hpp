#ifndef Pokemon_vector_hpp
#define Pokemon_vector_hpp

#include <vector>
#include "Pokemon.hpp"

class Pokemon_Vector {

protected:

    std::vector<Pokemon> pokemons;

public:
    void addPokemon(const Pokemon& pokemon);


    void displayAllPokemons() const;

};








#endif

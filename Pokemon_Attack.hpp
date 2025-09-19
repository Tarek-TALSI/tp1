#ifndef TP_CPP_POKEMON_ATTACK_HPP
#define TP_CPP_POKEMON_ATTACK_HPP

#include "Pokemon_Vector.hpp"

class Pokemon_Attack : public Pokemon_Vector
{
public:
    Pokemon_Attack(){};
    void addPokemon(const Pokemon& pokemon); // Redefinition of addPokemon from the Pokemon_Vector class
};


#endif //TP_CPP_POKEMON_ATTACK_HPP
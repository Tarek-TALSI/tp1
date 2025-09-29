#ifndef TP_CPP_POKEMON_ATTACK_HPP
#define TP_CPP_POKEMON_ATTACK_HPP

#include "Pokemon_Vector.hpp"

class Pokemon_Attack : public Pokemon_Vector
{
private:
    std::vector<Pokemon> team;
public:
    Pokemon_Attack(){};
    void addPokemon(const Pokemon& pokemon); // Redefinition of addPokemon from the Pokemon_Vector class

    const std::vector<Pokemon>& getTeam() const {
        return team;}
    
};
std::vector<Pokemon> generateRandomTeam(int teamSize);

#endif //TP_CPP_POKEMON_ATTACK_HPP
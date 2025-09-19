#include <iostream>
#include "Pokemon_Attack.hpp"

void Pokemon_Attack::addPokemon(const Pokemon& pokemon) {
    if (std::size(pokemons)>=6) {
        std::cout << "You can't add more than 6 pokemons in your attack team." << std::endl;
        return;
    }
    pokemons.push_back(pokemon);
    std::cout << "Pokemon " << pokemon.getName() << " added to the attack team." << std::endl;
    return;
}

#include <iostream>
#include "Pokemon_Attack.hpp"
#include "Pokedex.hpp"
#include "Pokemon.hpp"

std::vector<Pokemon> generateRandomTeam(int teamSize = 6) {
    std::vector<Pokemon> team;
    for (int i = 0; i < teamSize; ++i) {
        int randomId = std::rand() % 151 + 1; // Pokémon 1 à 151
        Pokemon p = Pokedex::getInstance().getClonePokemon(randomId);
        team.push_back(p);
    }
    return team;
}

void Pokemon_Attack::addPokemon(const Pokemon& pokemon) {
    if (std::size(pokemons)>=6) {
        std::cout << "You can't add more than 6 pokemons in your attack team." << std::endl;
        return;
    }
    pokemons.push_back(pokemon);
    std::cout << "Pokemon " << pokemon.getName() << " added to the attack team." << std::endl;
    return;
}

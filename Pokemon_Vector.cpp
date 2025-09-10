#include"Pokemon_vector.hpp"
#include <iostream>



void PokemonVector::addPokemon(const Pokemon& pokemon) {
    pokemons.push_back(pokemon);

}
void PokemonVector::displayAllPokemons() const {
    for (auto pokemon : pokemons) {
        pokemon.displayInfo();
        std::cout << "------------------------" << std::endl;
    }
}
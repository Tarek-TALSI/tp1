#include"Pokemon_Vector.hpp"
#include <iostream>



void Pokemon_Vector::addPokemon(const Pokemon& pokemon) {
    pokemons.push_back(pokemon);

}
void Pokemon_Vector::displayAllPokemons() const {
    for (auto pokemon : pokemons) {
        pokemon.displayInfo();
        std::cout << "------------------------" << std::endl;
    }
}
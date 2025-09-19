#include <iostream>


#include "Pokemon.hpp"
#include "Pokemon_Vector.hpp"
#include "Pokedex.hpp"
#include "Pokemon_Attack.hpp"
#include "Pokemon_Party.hpp"    


int main() {

    
/*
//prendre des dégats

    Pokemon pikachu(25, "Pikachu", 1,35.0 ,35.0 ,55.0 ,40.0);
    Pokemon squirtle(7, "Squirtle", 1,44.0 ,44.0 ,48.0 ,65.0);

    pikachu.displayInfo();
    squirtle.displayInfo();
    
    squirtle.doAttack(pikachu);
    pikachu.doAttack(squirtle);

    Pokemon copiedPikachu = pikachu;
    Pokemon copiedSquirtle = squirtle;
    copiedPikachu.displayInfo();
    copiedSquirtle.displayInfo();
    
    return 0;
}*/


/*
//definir une liste de pokemons
    Pokemon pikachu(25, "Pikachu", 1,35.0 ,35.0 ,55.0 ,40.0);
    Pokemon squirtle(7, "Squirtle", 1,44.0 ,44.0 ,48.0 ,65.0);
    Pokemon charmander(4, "Charmander", 1,39.0 ,39.0 ,52.0 ,43.0);
    

    PokemonVector pokemonCollection;
    pokemonCollection.addPokemon(pikachu);
    pokemonCollection.addPokemon(squirtle);
    pokemonCollection.addPokemon(charmander);
    

    pokemonCollection.displayAllPokemons();

    return 0;

    */

    
    /*
    //utiliser le pokedex

    Pokedex& dex = Pokedex::getInstance();
    
    
    //Pokemon clone = dex.getClonePokemon(25);
    
    
    //clone.displayInfo();

    // trying to get a second pokedex

    Pokedex& dex2 = Pokedex::getInstance();


    std::cout<<(&dex==&dex2)<<std::endl;
    
    return 0;
    */


    //creer une equipe d'attaque
    Pokemon pikachu(25, "Pikachu", 1,35.0 ,35.0 ,55.0 ,40.0);
    Pokemon squirtle(7, "Squirtle", 1,44.0 ,44.0 ,48.0 ,65.0);
    Pokemon charmander(4, "Charmander", 1,39.0 ,39.0 ,52.0 ,43.0);
    Pokemon bulbasaur(1, "Bulbasaur", 1,45.0 ,45.0 ,49.0 ,49.0);
    Pokemon jigglypuff(39, "Jigglypuff", 1,115.0 ,115.0 ,45.0 ,20.0);
    Pokemon mew(151, "Mew", 1,100.0 ,100.0 ,100.0 ,100.0);
    Pokemon mewtwo(150, "Mewtwo", 1,106.0 ,106.0 ,110.0 ,90.0);

    Pokemon_Attack attackTeam;
    attackTeam.addPokemon(pikachu);
    attackTeam.addPokemon(squirtle);
    attackTeam.addPokemon(charmander);
    attackTeam.addPokemon(bulbasaur);
    attackTeam.addPokemon(jigglypuff);
    attackTeam.addPokemon(mew);
    attackTeam.addPokemon(mewtwo); // This should not be added
    attackTeam.displayAllPokemons();
    return 0;
}

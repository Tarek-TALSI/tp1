#include "Pokedex.hpp"
#include "Pokemon.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Pokedex& Pokedex::getInstance() {
    static Pokedex instance;
    return instance;
}

Pokedex::Pokedex() {
    std::ifstream file("pokedex.csv");
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture de pokedex.csv" << std::endl;
        return;
    }
    
    std::string line;
   
    std::getline(file, line);
    
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        int id;
        std::string name;
        int evolution;
        double hitPoint;
        double hitPointMax;
        double attack;
        double defense;
        
        std::getline(iss, token, ',');
        id = std::stoi(token);
        std::getline(iss, token, ',');
        name = token;
        std::getline(iss, token, ',');
        evolution = std::stoi(token);
        std::getline(iss, token, ',');
        hitPoint = std::stod(token);
        std::getline(iss, token, ',');
        hitPointMax = std::stod(token);
        std::getline(iss, token, ',');
        attack = std::stod(token);
        std::getline(iss, token, ',');
        defense = std::stod(token);
        
        
        Pokemon p(id, name, evolution, hitPoint, hitPointMax, attack, defense);
        addPokemon(p);
    }
    file.close();
}

Pokedex::~Pokedex() {
    
}

Pokemon Pokedex::getClonePokemon(int searchId) const {
    
    for (const auto& p : pokemons) {
        if (p.getId() == searchId) {  
            return p;  
        }
    }
    std::cerr << "Pokemon avec l'id " << searchId << " introuvable." << std::endl;
    
    return Pokemon(0, "Unknown", 0, 0.0, 0.0, 0.0, 0.0);
}
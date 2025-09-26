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
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string token;

        std::getline(iss, token, ',');
        int id = std::stoi(token);

        std::getline(iss, token, ',');
        std::string name = token;

        std::getline(iss, token, ',');
        std::getline(iss, token, ',');
        std::getline(iss, token, ',');

        std::getline(iss, token, ',');
        double hitPoint = std::stod(token);
        double hitPointMax = hitPoint;

        std::getline(iss, token, ',');
        double attack = std::stod(token);

        std::getline(iss, token, ',');
        double defense = std::stod(token);

        std::getline(iss, token, ',');
        double speed = std::stod(token);

        Pokemon p(id, name, 0, hitPoint, hitPointMax, attack, defense,speed);
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
    return Pokemon(0, "Unknown", 0, 0.0, 0.0, 0.0, 0.0,0.0);
}

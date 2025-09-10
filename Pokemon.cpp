#include "Pokemon.hpp"
#include <iostream>

Pokemon::Pokemon(int id, std::string name,int evolution, double hitPoint, double hitPointmax,
     double attack, double defense)
    : id(id), name(name),evolution(evolution), hitPoint(hitPoint),hitPointMax(hitPointmax)
    , attack(attack)
    , defense(defense)
    {std::cout << "Pokemon " << name << " created." << std::endl;}

Pokemon::Pokemon(const Pokemon& otherpokemon)
    : id(otherpokemon.id), name(otherpokemon.name),evolution(otherpokemon.evolution),
    hitPoint(otherpokemon.hitPoint),hitPointMax(otherpokemon.hitPointMax),
    attack(otherpokemon.attack), defense(otherpokemon.defense)
    
    {std::cout << "Pokemon " << name << " copied." << std::endl;}

Pokemon::~Pokemon() {std::cout << "Pokemon " << name << " destroyed." << std::endl;}

void Pokemon::doAttack(Pokemon& target) {
    std::cout << name << " is attacking " << target.name <<std::endl;
    double damage = (attack/target.defense)*10;
    if (damage < 0) damage = 0;
    target.hitPoint= target.hitPoint - damage; 
    if (target.hitPoint < 0){target.hitPoint = 0;}
    std::cout <<target.name<<"lost"<<damage<<"points of health"<<std::endl;
    
}

void Pokemon::displayInfo() const {
    std::cout << "Pokemon's info\n"
              << "ID         : " << id << "\n"
              << "Name    : " << name << "\n"
              << "Evolution    : " << evolution << "\n"
              << "Health         : " << hitPoint << "\n"
              << "Healthmax        : " << hitPointMax << "\n"
              << "Attack    : " << attack << "\n"
              << "Defense    : " << defense << "\n";
}



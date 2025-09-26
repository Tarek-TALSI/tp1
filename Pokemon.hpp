#ifndef POKEMON_HPP
#define POKEMON_HPP
#include <string>

class Pokemon{

    private:
        int id;
        std::string name;
        int evolution;
        double hitPoint;
        double hitPointMax;
        double attack;
        double defense;
        double speed;
    public:
    
    Pokemon(int id, std::string name,int evolution, double hitPoint,double hitPointmax, 
    double attack, double defense, double speed);

    Pokemon(const Pokemon& otherpokemon);
    
    ~Pokemon();

    void displayInfo() const;

    int getId() const {return id;}

    void doAttack(Pokemon& target);
    std::string getName() const;
    double getHitPoint() const {return hitPoint;}
    double getSpeed() const {return speed;}
};

#endif
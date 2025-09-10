
#include "Pokemon.hpp"


int main() {
    

    Pokemon pikachu(25, "Pikachu", 1,35.0 ,35.0 ,55.0 ,40.0);
    Pokemon squirtle(7, "Squirtle", 1,44.0 ,44.0 ,48.0 ,65.0);

    pikachu.displayInfo();
    squirtle.displayInfo();
    
    squirtle.doAttack(pikachu);

    Pokemon copiedPikachu = pikachu;
    Pokemon copiedSquirtle = squirtle;
    copiedPikachu.displayInfo();
    copiedSquirtle.displayInfo();
    
    return 0;
}

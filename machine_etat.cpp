#include "machine_etat.hpp"


GameState* EcranAccueil::handle() {
    std::cout << "=== POKEMON ATTACK ===\n";
    std::cout << "Appuyez sur Entree pour commencer...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    return new Exploration();
}


GameState* Exploration::handle() {
    std::cout << "\n--- Exploration ---\n";
    std::cout << "1. Continuer d'explorer\n2. Quitter\n";
    int choix;
    std::cin >> choix;

    if (choix == 2) return nullptr;
    else if (choix == 1) {
        int r = std::rand() % 2;
        if (r == 0) return new Rencontre();
        else return new Combat();
    } else {
        std::cout << "Il faut écouter les consignes !\n"; 
        return new Exploration; 
        
    }
}


GameState* Rencontre::handle() {
    std::cout << "\n>>> Rencontre avec un Pokemon sauvage !\n";
    int randomId_R = std::rand() % 151 + 1; 
    Pokemon clone = Pokedex::getInstance().getClonePokemon(randomId_R);
    std::cout << "C'est un " << clone.getName() << " !" << std::endl;

    while (true) {
        std::cout << "Veux-tu le capturer ? (oui/non): ";
        std::string choix;
        std::cin >> choix;

        if (choix == "non") {
            std::cout << "Tu as laissé partir le Pokemon. Tu fais donc parti du lobby anti-exploitation des pokemons.\n";
            return new Exploration();
        }

        if (choix == "oui") {
            while (true) {
                std::cout << "Es-tu sûr de vouloir perpétrer le cycle de la haine et de la répression envers ce Pokemon ? (oui/non): ";
                std::string reponse;
                std::cin >> reponse;

                if (reponse == "non") {
                    std::cout << "Tu es redevenu un être humain et ce Pokemon peut retourner gambader dans la prairie.\n";
                    return new Exploration();
                }

                if (reponse == "oui") {
                    std::cout << "D'accord, sans âme. Tu essayes de capturer ce Pokemon en l'ayant blessé.\n";
                    bool succes = (std::rand() % 2 == 0);
                    if (succes) {
                        std::cout << "Capture réussie ... Un Pokemon de plus subira ton joug.\n";
                    } else {
                        std::cout << "Capture échouée. Tu n'as même pas réussi à capturer un Pokemon.\n";
                    }
                    std::cout << "Avant de repartir en exploration, le jeu t'informes que tu as reproduit des erreurs du passé dans cette grande distopie qu'est Pokemon. \n";
                    return new Rencontre();
                }

                std::cout << "Il faut écouter les consignes !\n";
            }
        }

        std::cout << "Il faut écouter les consignes !\n";
    }
}



GameState* Combat::handle() {
    std::cout << "\n!!! Combat dans l'arene !!!\n";
    int randomId_h = std::rand() % 151 + 1; 
    Pokemon clone1 = Pokedex::getInstance().getClonePokemon(randomId_h);
    
    std::cout << "Un" <<clone1.getName()<< "veut en découdre !\n";
    std::cout << "\n veut tu attaquer avec le pouvoir de l'amitié ou avec la force brute et aléatoire ? (oui/non) ";
    std::string reponse;
    std::cin >> reponse;
    if (reponse == "oui") {
        std::cout << "Tu as choisi le pouvoir de l'amitié !\n";
        std::cout << "Victoire ! Vous avez vole un Pokemon mais avec amitié donc ça va.\n";
        return new Exploration();
    } else {
    bool victoire = (std::rand() % 2 == 0);
    if (victoire) {
        std::cout << "Victoire (mais c'est pas bien car l'amitié c'est mieux)! Vous avez vole un Pokemon ce qui fait de vous une mauvaise personne.\n";
        return new Exploration();
    } else {
        std::cout << "Vous avez perdu et vous auriez du choisir l'amitié.\n";
        return new GameOver();
    }
}
}


GameState* GameOver::handle() {
    std::cout << "\n=== GAME OVER ===\n";
    std::cout << "Recommencer ? (oui/non): ";
    std::string restart;
    std::cin >> restart;
    if (restart == "oui") return new EcranAccueil(); 
    else return nullptr;
}



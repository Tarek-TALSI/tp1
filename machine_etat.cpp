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
    std::cout << "Veut tu le capturer ?(oui/non): ";
    std::string c;
    std::cin >> c;
    if (c=="non") {
        std::cout << "Tu as laissé partir le Pokemon. Tu fais donc parti du lobby anti-exploitation des pokemons \n";
        return new Exploration();
    } else if (c == "oui") {

        std::cout << "Est-tu sur de vouloir perpertrer le cycle de la haine et de la répression envers ce qui s'apparente à une réalité distopique critiquant la société d'aujourdhui ?(oui/non): ";
        std::string reponse;
        std::cin >> reponse;
        if (reponse == "non") {
            std::cout << "Tu est redevenu un être humain et ce Pokemon peut retourner gambader dans la prairie \n";
            return new Exploration();}
        else if (reponse == "oui") {
            std::cout << "Daccord sans âme.\n Tu essayes alors de capturer ce Pokemon en l'ayant bien blessé avant car tu es pour la souffrance des Pokemons \n"; 
            bool succes = (std::rand() % 2 == 0);
            if (succes) {
                std::cout << "Capture reussie ... Un pokemon de plus subira le joug de cette société\n";
            }
            else {
                std::cout << "Capture echouee. Tu est une horrible personne même pas capable de capturer un Pokemon. \n";
            }
            return new Rencontre; 
        }
        else {
            std::cout << "Il faut écouter les consignes !\n"; 
            return new Rencontre; 
        }
    }
    else {
        std::cout << "Il faut écouter les consignes !\n"; 
        return new Rencontre; 
    }
    return new Exploration();
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



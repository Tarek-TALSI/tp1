#include "machine_etat.hpp"
#include "Pokemon.hpp"

int taille_equipe=0;
Pokemon_Attack attackTeam;

bool askYesNo(const std::string& question) {
    while (true) {
        std::cout << question << " (oui/non): ";
        std::string reponse;
        std::cin >> reponse;

        if (reponse == "oui") return true;
        if (reponse == "non") return false;

        std::cout << "Réponse invalide, tape 'oui' ou 'non'.\n";
    }
}



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
        if (taille_equipe<6){
            std::cout << "Il te manque "<<6-taille_equipe<<" pokemons pour avoir une équipe complète.\n";
            return new Rencontre();
        }
        
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

    
    if (!askYesNo("Veux-tu le capturer ?")) {
        std::cout << "Tu as laissé partir le Pokemon. Tu fais donc parti du lobby anti-exploitation des pokemons.\n";
        return new Exploration();
    }

    
    if (!askYesNo("Es-tu sûr de vouloir perpétrer le cycle de la haine et de la répression envers ce Pokemon ?")) {
        std::cout << "Tu es redevenu un être humain et ce Pokemon peut retourner gambader dans la prairie.\n";
        return new Exploration();
    }

    
    std::cout << "D'accord, sans âme. Tu essayes de capturer ce Pokemon en l'ayant blessé.\n";
    std::cout << "Capture réussie ... Un Pokemon de plus subira ton joug.\n";
    taille_equipe++;
    attackTeam.addPokemon(clone);

    std::cout << "Avant de repartir en exploration, le jeu t'informes que tu as reproduit des erreurs du passé dans cette grande distopie qu'est Pokemon.\n";
    return new Exploration();
}
    





GameState* Combat::handle() {
    std::cout << "\n!!! Combat dans l'arene !!!\n";
    int randomId_h = std::rand() % 151 + 1; 
    Pokemon clone1 = Pokedex::getInstance().getClonePokemon(randomId_h);
    
    std::cout << "Un " <<clone1.getName()<< " veut en découdre !\n";
    
    std::cout << "Choisis ton Pokemon pour le combat"<<std::endl;

    while(true){
        int randomId_p = std::rand() % 151 + 1;
        Pokemon clone2= Pokedex::getInstance().getClonePokemon(randomId_p);
        std::cout <<"est ce que tu veux combattre avec "<<clone2.getName()<<" ? (oui/non) ";
        std::string reponse;
        std::cin>>reponse;
        if(reponse=="oui"){

            while(clone1.getHitPoint()>0 && clone2.getHitPoint()>0){
                std::cout<<"------------------------"<<std::endl;
                Pokemon* first;
                Pokemon* second;

                if(clone1.getSpeed()>=clone2.getSpeed()){
                    first=&clone1;
                    second=&clone2;
                }
                else{
                    first=&clone2;
                    second=&clone1;
                }

                first->doAttack(*second);
                if(clone1.getHitPoint()<=0) break;
            
                second->doAttack(*first);
                if(clone2.getHitPoint()<=0) break;
                std::cout<<"il reste "<<clone1.getHitPoint()<<" points de vie a "<<clone1.getName()<<std::endl;
                std::cout<<"il reste "<<clone2.getHitPoint()<<" points de vie a "<<clone2.getName()<<std::endl;
                std::cout<<"Veut tu continuer le combat ou fuir? (continuer/fuir) ";
                std::string action;
                std::cin>>action;
                if(action=="fuir"){
                    std::cout<<"Tu as fui le combat, tu es un lâche !"<<std::endl;
                    return new Exploration();
                }
                else if(action!="continuer"){
                    std::cout<<"Il faut écouter les consignes !"<<std::endl;
                }
                

            }
            if(clone1.getHitPoint()<=0){
                std::cout<<"Bravo tu as gagné le combat !"<<std::endl;
                return new Exploration();
            }
            else{
                std::cout<<"Dommage tu as perdu le combat !"<<std::endl;
                return new GameOver();
        }
    }
}
}

GameState* CombatDresseur::handle() {
    std::cout << "\n=== Défi d'un dresseur adverse ! ===\n";

    // Génération des deux teams
    std::cout << "Ton équipe :\n";
    auto playerTeam = attackTeam.getTeam(); // Ton équipe déjà capturée
    for (auto& p : playerTeam) {
        std::cout << " - " << p.getName() << " (" << p.getHitPoint() << " HP)\n";
    }

    std::cout << "\nEquipe adverse :\n";
    auto opponentTeam = generateRandomTeam(6);
    for (auto& p : opponentTeam) {
        std::cout << " - " << p.getName() << " (" << p.getHitPoint() << " HP)\n";
    }

    std::cout << "\n=== Début du combat ===\n";

    int playerIndex = 0;
    int opponentIndex = 0;

    while (playerIndex < playerTeam.size() && opponentIndex < opponentTeam.size()) {
        Pokemon& playerPokemon = playerTeam[playerIndex];
        Pokemon& opponentPokemon = opponentTeam[opponentIndex];

        std::cout << "\nCombat : " << playerPokemon.getName() << " vs " << opponentPokemon.getName() << "\n";

        while (playerPokemon.getHitPoint() > 0 && opponentPokemon.getHitPoint() > 0) {
            // Attaque en fonction de la vitesse
            if (playerPokemon.getSpeed() >= opponentPokemon.getSpeed()) {
                playerPokemon.doAttack(opponentPokemon);
                if (opponentPokemon.getHitPoint() <= 0) break;
                opponentPokemon.doAttack(playerPokemon);
            } else {
                opponentPokemon.doAttack(playerPokemon);
                if (playerPokemon.getHitPoint() <= 0) break;
                playerPokemon.doAttack(opponentPokemon);
            }

            std::cout << playerPokemon.getName() << " HP: " << playerPokemon.getHitPoint()
                      << " | " << opponentPokemon.getName() << " HP: " << opponentPokemon.getHitPoint() << "\n";

            if (!askYesNo("Continuer le combat ?")) {
                std::cout << "Tu as fui le combat !\n";
                return new Exploration();
            }
        }

        // Passer au Pokémon suivant si l'un est KO
        if (playerPokemon.getHitPoint() <= 0) {
            std::cout << playerPokemon.getName() << " est KO !\n";
            playerIndex++;
        }
        if (opponentPokemon.getHitPoint() <= 0) {
            std::cout << opponentPokemon.getName() << " est KO !\n";
            opponentIndex++;
        }
    }

    if (playerIndex >= playerTeam.size()) {
        std::cout << "\nTous tes Pokémon sont KO... Tu as perdu !\n";
    } else {
        std::cout << "\nTous les Pokémon adverses sont KO ! Victoire !\n";
    }

    return new Exploration();
}


GameState* GameOver::handle() {
    std::cout << "\n=== GAME OVER ===\n";
    std::cout << "Recommencer ? (oui/non): ";
    std::string restart;
    std::cin >> restart;
    if (restart == "oui") return new EcranAccueil(); 
    else return nullptr;
}



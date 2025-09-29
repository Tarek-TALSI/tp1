#pragma once
#include <iostream>
#include <limits>
#include <cstdlib>
#include "Pokedex.hpp"
#include "Pokemon.hpp"
#include "Pokemon_Attack.hpp"


extern int taille_equipe;
extern Pokemon_Attack attackTeam;

class GameState {
public:
    virtual ~GameState() = default;
    virtual GameState* handle() = 0;
};

class EcranAccueil : public GameState { public: GameState* handle() override; };
class Exploration : public GameState { public: GameState* handle() override; };
class Rencontre : public GameState { public: GameState* handle() override; };
class Combat : public GameState { public: GameState* handle() override; };
class CombatDresseur : public GameState { public: GameState* handle() override; };
class GameOver : public GameState { public: GameState* handle() override; };

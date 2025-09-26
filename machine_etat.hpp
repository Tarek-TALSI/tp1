#pragma once
#include <iostream>
#include <limits>
#include <cstdlib>
#include "Pokedex.hpp"
#include "Pokemon.hpp"

class GameState {
public:
    virtual ~GameState() = default;
    virtual GameState* handle() = 0;
};

class EcranAccueil : public GameState {
public:
    GameState* handle() override;
};

class Exploration : public GameState {
public:
    GameState* handle() override;
};

class Rencontre : public GameState {
public:
    GameState* handle() override;
};

class Combat : public GameState {
public:
    GameState* handle() override;
};

class GameOver : public GameState {
public:
    GameState* handle() override;
};

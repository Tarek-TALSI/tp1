cmake_minimum_required(VERSION 3.28.3)
project(tp1)

set(CMAKE_CXX_STANDARD 20)


add_executable(tp1 main.cpp
                    Pokemon.cpp
                    Pokemon.hpp
                    Pokemon_Vector.cpp
                    Pokemon_Vector.hpp
                    Pokedex.cpp
                    Pokedex.hpp
                    Pokemon_Party.hpp
                    Pokemon_Attack.cpp
                    Pokemon_Attack.hpp
                    machine_etat.cpp
                    machine_etat.hpp)

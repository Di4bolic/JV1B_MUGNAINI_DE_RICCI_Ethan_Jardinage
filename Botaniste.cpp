#ifndef BOTANISTE_CPP
#define BOTANISTE_CPP

#include "Botaniste.h"
#include <iostream>

    Botaniste::Botaniste(): _argent(10), _jardin({Plante("Menthe")}), _nbrEngrais(10){}        

    void Botaniste::dormir(){
        for (int i=0; i != _jardin.size(); ++i) 
        {
            _jardin[i].finDeJournee();
        }
    }

    void Botaniste::acheterPlante(int typePlante){
        if (typePlante == 1)
        {
            _jardin.push_back(Plante("Menthe"));
            _argent -= 10;
        }
        else if (typePlante == 2)
        {
            _jardin.push_back(Fleur("Pisselit des étoiles"));
            _argent -= 20;
        }
        else
        {
            _jardin.push_back(Carnivore("Bouffeuse d'Hommes"));
            _argent -= 30;
        }
    }

    void Botaniste::montrePlantes(){
        std::cout<< " " <<std::endl;
        std::cout<< "Voici votre jardin :\n" <<std::endl;
        for (int i=0; i != _jardin.size(); ++i) 
        {
            if (_jardin[i].verifierEtat() == false)
            {
                /*On affiche une croix s'il n'y a plus de plante à l'emplacement*/
                std::cout<< "X";
            }
            else
            {
                std::cout<< "O";
            }
        }
        std::cout<< "\n" <<std::endl;
    }   

    std::vector<Plante> Botaniste::getJardin(){
        return _jardin;
    }

    void Botaniste::ajouteArgent(int argent){
        _argent += argent;
    }  

    void Botaniste::perdEngrai(){
        _nbrEngrais -= 1;
    }

    void Botaniste::gagneEngrai(){
        _nbrEngrais += 1;
        _argent -= 2;
    }

#endif
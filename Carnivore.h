#ifndef CARNIVORE_H
#define CARNIVORE_H

#include <string>
#include "Plante.cpp"

class Carnivore : public Plante{
  
    public:

    Carnivore(std::string espece);

    int _temps;

    int vendrePlante();
    // permet de vendre la plante

    void finDeJournee();
    // permet de vérifier si la plante peut pousser

    void afficheEtat();
    // renvoie le nom de l'espèce , sa santé , son hydratation et si elle mange
        
};

#endif
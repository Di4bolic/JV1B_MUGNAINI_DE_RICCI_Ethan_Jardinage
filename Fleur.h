#ifndef FLEUR_H
#define FLEUR_H

#include <string>
#include "Plante.cpp"

class Fleur : public Plante{
  
    public:

    Fleur(std::string espece);

    std::string _valeur;
    int _temps;

    int vendrePlante();
    // permet de vendre la plante

    void finDeJournee();
    // permet de vérifier si la plante peut pousser

    
        
};

#endif
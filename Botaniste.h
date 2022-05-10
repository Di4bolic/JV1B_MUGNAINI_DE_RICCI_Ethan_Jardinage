#ifndef BOTANISTE_H
#define BOTANISTE_H

#include "Plante.cpp"
#include "Fleur.cpp"
#include "Carnivore.cpp"
#include <string>
#include <vector>

class Botaniste{

    protected:

        int _argent;
        int _nbrEngrais;
        std::vector<Plante> _jardin;
        
    public:

        Botaniste();

        void dormir();
        // passe au jour suivant

        void acheterPlante(int typePlante);
        // permet d'acheter une plante

        void montrePlantes();
        // permet de montrer la liste des plantes

        std::vector<Plante> getJardin();
        // renvoie le jardin

        void ajouteArgent(int argent);
        // ajoute de l'argent

        void perdEngrai();
        // perd un engrai

        void gagneEngrai();
        // gagne un engrai

};

#endif
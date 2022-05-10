#ifndef PLANTE_H
#define PLANTE_H

#include <string>

class Plante{

    protected:

        std::string _espece;
        int _sante;
        int _hydratation;
        int _stade;
        bool _engrais;
        bool _taille;
        bool _arrose;
        
    public:

        Plante();
        Plante(std::string espece);

        void afficheEtat();
        // renvoie le nom de l'espèce , sa santé , son hydratation

        void utiliseEngrais();
        // permet de donner de l'engrais à la plante

        void utiliseTaille();
        // permet de tailler la plante

        void utiliseArrose();
        // permet d'arroser la plante

        int vendrePlante();
        // permet de vendre la plante

        bool verifierEtat();
        // permet de vérifier si la plante est toujours là

        void finDeJournee();
        // permet de vérifier si la plante peut pousser

};

#endif
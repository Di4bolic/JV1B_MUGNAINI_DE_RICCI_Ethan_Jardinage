#ifndef PLANTE_CPP
#define PLANTE_CPP

#include "Plante.h"
#include <iostream>

    Plante::Plante(): _espece("SansEspece"), _sante(10), _hydratation(10), _stade(1), _engrais(false), _taille(false), _arrose(false){}

    Plante::Plante(std::string espece):
        _espece(espece), _sante(10), _hydratation(10), _stade(1), _engrais(false), _taille(false), _arrose(false){}


    void Plante::afficheEtat(){
        // renvoie le nom de l'animal , son affection et sa faim
        std::cout<< "Ton/ta " << _espece << " :\n" <<std::endl;
        std::cout<< "Son niveau de santé est de " << _sante << "/10" <<std::endl;
        std::cout<< "Son niveau d'hydratation est de " << _hydratation << "/10\n" <<std::endl;
    }
        

    void Plante::utiliseEngrais(){
        if (_engrais == true)
        {
            std::cout<< "Vous ne pouvez pas en donner vous l'avez déjà fait aujourd'hui ..." <<std::endl;
        }
        _engrais = true;
    }

    void Plante::utiliseTaille(){
        if (_taille == true)
        {
            _sante -= 2;
        }
        _sante += 1;
        _taille = true;
    }

    void Plante::utiliseArrose(){
        if (_arrose == true)
        {
            _sante -= 2;
        }
        _sante += 1;
        _arrose = true;
    }

    int Plante::vendrePlante(){
        /*On retire la plante du sol*/
        _espece = "trou dans le sol";
        _sante = 0;
        return 10+_stade;
    }
    
    bool Plante::verifierEtat(){
        if (_espece == "trou dans le sol")
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }

    void Plante::finDeJournee(){
        if (_sante >= 7)
        {
            if (_engrais == true)
            {
                _stade += 1;
                _engrais = false;
            }
            if (_arrose == true)
            {
                _stade += 1;
                _sante += 1;
                _arrose = false;
            }
            else
            {
                _sante -= 1;
            }
            if (_taille == true)
            {
                _stade += 1;
                _sante += 1;
                _taille = false;
            }
            else
            {
                _sante -= 1;
            }
            
        }
        else if (_sante <= 3)
        {
            _stade -= 1;
        }
        if (_stade > 5)
        {
            _stade = 5;
        }
        if (_sante <= 0)
        {
            _sante = 0;
            _espece = "trou dans le sol";
        }
        
        
    }        

#endif
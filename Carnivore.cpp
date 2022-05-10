#include "Carnivore.h"

Carnivore::Carnivore(std::string espece) : Plante() {
    _espece = espece;
    _temps = 7;
}

int Carnivore::vendrePlante(){
        _espece = "trou dans le sol";
        _sante = 0;
        return 30+_stade*_stade;
}

void Carnivore::finDeJournee(){
    if (_temps <= 0)
    {
        _sante -= 1;
    }
    
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

    _temps -= 1;

}

void Carnivore::afficheEtat(){
    // renvoie le nom de l'animal , son affection et sa faim
    std::cout<< "Ton/ta " << _espece << " :\n" <<std::endl;
    std::cout<< "Son niveau de santé est de " << _sante << "/10" <<std::endl;
    std::cout<< "Son niveau d'hydratation est de " << _hydratation << "/10" <<std::endl;
    if (_temps <= 0)
        {
            std::cout<< "La plante à faim ! Vous la nourissez pour éviter qu'elle vous mange ...\n" <<std::endl;
            /*Je la nourrie automatiquement -> voir pb dans main.cpp*/
            _temps = 7;
        }
        else
        {
            std::cout<< "La plante diggère une mouche\n" <<std::endl;
        }
}
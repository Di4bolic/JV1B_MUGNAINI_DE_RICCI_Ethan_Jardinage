#include "Fleur.h"

Fleur::Fleur(std::string espece) : Plante() {
    _espece = espece;
    _valeur = "normal";
    _temps = 4;
}

int Fleur::vendrePlante(){
/*On retire la plante du sol*/
    _espece = "trou dans le sol";
    _sante = 0;
    /*On vend la fleur*/
    if (_valeur == "En fleur")
    {
        return (20+_stade)*2;
    }
    else if (_valeur == "Fanée")
    {
        return (20+_stade)/10;
    }
    else
    {
        return 20+_stade;
    }
}

void Fleur::finDeJournee(){
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
    /*Fleur en fleur ou fanée*/
    if (_stade == 20)
    {
        if (_valeur != "Fanée")
        {
            _valeur = "En fleur";
        }
    }
    if (_valeur == "En fleur")
    {
        _temps -= 1;
        if (_temps == 0)
        {
            _valeur = "Fanée";
        }
        
    }
}
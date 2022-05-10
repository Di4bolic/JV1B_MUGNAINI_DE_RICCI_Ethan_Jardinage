#include "Plante.cpp"
#include "Botaniste.cpp"
#include "Fleur.cpp"
#include "Carnivore.cpp"
#include <iostream>
#include <string>


int main(){

    /*Imlémentation du joueur*/
    Botaniste * joueur = new Botaniste();
    joueur->acheterPlante(1);

    int choix;
    int choixAction;
    std::string choixNourriture;

    /*Boucle de jeu*/
    while (true)
    {
        /*Actions du joueur*/
        std::cout<< "Que voulez-vous faire ? ( Travailler : 1 / Dormir : 2 / Acheter de l'engrai : 3 / Acheter une plante : 4 )" <<std::endl;
        std::cin >> choix;

        if (choix == 2)
        {
            joueur->dormir();
        }
        else if (choix == 3)
        {
            joueur->gagneEngrai();
        }
        else if (choix == 4)
        {
            std::cout<< "Quelle plante ? ( Menthe : 1 / Fleur : 2 / Carnivor : 3 )" <<std::endl;
            std::cin >> choix;
            joueur->acheterPlante(choix);
        }
        else
        {
            /*Le joueur veut travailler*/
            joueur->montrePlantes();
            std::cout<< "De quelle plante voulez-vous vous occuper ? ( Numéro de la plante -> ex: 1 )" <<std::endl;
            std::cin >> choix;

            /*On vérifie si une plante est bien présente ( si elle n'a pas été vendue ou si elle n'est pas morte )*/
            if (joueur->getJardin()[choix].verifierEtat() == true)
            {
                joueur->getJardin()[choix].afficheEtat();                

                std::cout<< "Que voulez-vous faire ? ( Utiliser de l'engrais : 1 / La tailler : 2 / L'arroser : 3 / La vendre : 4 )" <<std::endl;
                std::cin >> choixAction;
                /*Je voulais faire une action nourrir pour la plante carnivore comme
                c'est une plante , mais j'ai des attributs supplémentaires par rapport
                à la classe mère et en les appelant ou en appelant une fonction pas
                définie dans Plante ça ne fonctionne pas*/

                /*Le joueur choisit ce qu'il veut faire avec la plante*/
                if (choixAction == 1)
                {
                    joueur->getJardin()[choix].utiliseEngrais();
                    joueur->perdEngrai();
                }
                else if (choixAction == 2)
                {
                    joueur->getJardin()[choix].utiliseTaille();
                }
                else if (choixAction == 3)
                {
                    joueur->getJardin()[choix].utiliseArrose();
                }
                else
                {
                    joueur->ajouteArgent(joueur->getJardin()[choix].vendrePlante());
                    joueur->getJardin()[choix].finDeJournee();
                }
            }
            else
            {
                std::cout<< "La plante dont vous voulez vous occuper est un trou dans le sol" <<std::endl;
            }
        }
    }
    return 0;
}
# Egoheim - Jeu de Duel Fast-Paced en 2D Top-Down

**Egoheim** est un jeu de duel rapide en 2D top-down où deux joueurs s'affrontent dans un environnement dynamique. Le jeu utilise SDL2 et SDL2_image pour la gestion des graphismes et des interactions.

## Pré-requis:
- **Visual Studio 2022** avec le support de C++.
- **vcpkg** : Un gestionnaire de paquets pour C++ utilisé pour gérer les dépendances SDL2 et SDL2_image.
- **SDL2** et **SDL2_image** : Bibliothèques nécessaires au fonctionnement du jeu.

## Instructions d'installation

Depuis votre invite de commande, clonez le dépôt à l'endroit de votre choix avec : <br>
- git clone https://github.com/Alias10294/Egoheim.git

Pour installer vcpkg, toujours dans l'invite de commande, clonez ce dépôt à un endroit de votre choix (peut-être placé hors du projet pour utilisation dans d'autres projets): <br>
- git clone https://github.com/microsoft/vcpkg.git

Ensuite pour mettre en place vcpkg, utilisez les instructions suivantes:
- cd vcpkg
- .\bootstrap-vcpkg.bat 
<br>Vous pourrez installer dedans les librairies nécessaires au fonctionnement du projet.
- vcpkg install sdl2
- vcpkg install sdl2-image
Ensuite, il suffit de lier vcpkg au projet avec:
- vcpkg integrate install

Depuis Visual Studio 2022, le projet peut maintenant être ouvert depuis le fichier .sln, et il suffira de compiler et exécuter le code.
Si une erreur de compilation LNK2019 en rapport avec la fonction main() se présente, il faudra probablement aller dans les propriétés du projet.
Depuis l'Explorateur de solutions:
###Propriétés >> C/C++ >> Préprocesseur >> Définitions Préprocesseur 
De là, il suffit de modifier les défintions pour y ajouter SDL_MAIN_HANDLED.

## Execution
Maintenant, le fichier devrait être fin prêt, et il ne reste plus qu'à exécuter le programme.

## Ressources
- [SDL2 Documentation](https://wiki.libsdl.org/)
- [SDL2_image Documentation](https://www.libsdl.org/projects/SDL_image/)
- [vcpkg Documentation](https://github.com/microsoft/vcpkg)

## Bon jeu !

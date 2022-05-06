## PROGRAME DE RESOLUTION (Incomplet) ##

## JEU: USOWAN


## Spécification du fichier d'entrée:

première ligne:
h l
Hauteur et largeur de la grille de jeu

lignes précédées par 'n':
n x y i
indique que la case de coordonées x, y (origine de la grille en haut à gauche (0, 0)) contient un nombre
avec pour valeur i

lignes précédées par 'r':
r k i1 i2 ... ik-1
indique une région composées des k cases d'indices i1, i2, ..., ik-1
Les indices sont comptées en partant de 0, de gauche à droite puis de haut en bas


## Installation du solveur

Le solveur utilisé est Varisat (https://crates.io/crates/varisat)
Ecrit en Rust, il a besoin d'être compilé et installé avant l'exécution du programe

La procédure d'installation de Rust, très simple, est détaillée sur le site https://www.rust-lang.org
Elle permet d'installer l'outil de gestion de projet "cargo"

Ensuite, naviger dans le terminal jusqu'au dossier du programe, et exécuter la commande:
cargo install --force varisat-cli

Cette commande téléchargera le solveur depuis crates.io (nécessite une connexion à internet) et le compilera

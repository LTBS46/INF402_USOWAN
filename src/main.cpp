#include "common.hpp"

#include <exception>        // exception
#include <filesystem>       // is_regular_file, path
#include <fstream>          // ifstream
#include <iostream>         // cerr, endl
#include <string>           // string

using std::cerr;                        // flux d'erreur (stderr)
using std::cin;                         // flux d'entrée (stdin)
using std::cout;                        // flux de sortie (stdout)
using std::endl;                        // symbole de fin de ligne
using std::exception;                   // la class de base pour les erreur
using std::filesystem::is_regular_file; // teste si le fichier un fichier normal
using std::filesystem::path;            // le type chemin de fichier
using std::ifstream;                    // type fichier en lecture
using std::string;                      // type chaine de caractere

/// main function
int main(int argc, char** argv) try {
    if (argc != 2) {
        if (argc == 1) {
            /// pas d'argument
            cerr << "il n'y a pas de fichier a résoudre." << endl;
            return -1;
        } else {
            /// trop >1
            cerr << "il y a trop d'argument : " << (argc - 1) << "." << endl;
            return -1;
        }
    } else {
        /// argv[1] est le nom du fichier a résoudre

        /* nom du fichier */
        path file_name = path(string(argv[1]));
        
        /* on regarde si il s'agit d'un fichier normal */
        if(! is_regular_file(file_name)) {
            cerr << "le chemin indiqué n'est pas un fichier." << endl;
            return -1;
        }
        
        /* pas besoin de le fermer il sera détruit en sorti de scope */
        ifstream input = ifstream(file_name);
    }
} catch (exception& e) {
    cerr << "erreur : \"" << e.what() << "\" caught" << endl;
    return -2;
}

#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using std::cerr;            // flux d'erreur (stderr)
using std::endl;            // symbole de fin de ligne
using std::exception;
using std::ifstream;        // type fichier en lecture
using std::string;          // type chaine de caractere

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
        string file_name = argv[1];

        /* pas besoin de le fermer il sera détruit en sorti de scope */
        ifstream input = ifstream(file_name);
    }
} catch (exception& e) {
    cerr << "erreur : \"" << e.what() << "\" caught" << endl;
    return -2;
}

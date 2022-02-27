#include "fstream"

using std::ifstream;

/// main function
int main(int argc, char** argv) {
    if (argc != 2) {
        if (argc == 1) {
            /// pas d'argument
        } else {
            /// trop >1
        }
    } else {
        /// argv[1] est le nom du fichier a résoudre

        /* pas besoin de le fermer il sera détruit en sorti de scope */
        ifstream input = ifstream(argv[1]);
    }
}

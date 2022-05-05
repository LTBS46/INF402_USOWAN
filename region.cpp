#include "region.hpp"


Region::Region() {}

void Region::CreerClauses() {

    // Si une case est menteur, les autres ne le sont pas
    ClauseUnMenteur();

    // Combinaisons si une case  n'est pas menteur

}

void Region::ClauseUnMenteur() {
    for (Case c : cases) {
        Clause new_clause = Clause(FND);
        Variable menteur = c.var;

        new_clause.vars.push_back(menteur);

        for (Case c1 : cases) {
            if (c.var.GetIndex() == c1.var.GetIndex()) {
                continue;
            } else {
                Variable non_menteur = c1.var;
                non_menteur.SetNeg(!c1.var.GetNeg());

                new_clause.vars.push_back(non_menteur);
            }
        }

        clausesRegion.form.push_back(new_clause);
    }
}



void Region::RenderClauses(ostream& file) {
    if (clausesRegion.type != FNC) {
        clausesRegion.Convert();
    }
    for (Clause c : clausesRegion.form) {
        file << c.GetDimacs() << "\n";
    }
}
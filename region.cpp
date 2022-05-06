#include "region.hpp"

Region::Region() { }

void Region::CreerClauses(LUT case_type_lut) {
    // Si une case est menteur, les autres ne le sont pas
    // std::cout << "Creating clauses for new region" << std::endl;
    ClauseUnMenteur();
    ClauseConfigNonMenteur(case_type_lut);
    ClauseConfigMenteur(case_type_lut);
    
    clausesRegion.AfficherFormule();
    // std::cout << "Done with creating region" << std::endl;
    // Combinaisons si une case  n'est pas menteur
}

void Region::ClauseUnMenteur() {
    for (Case c : cases) {
        Clause new_clause = Clause(forme::FND);
        Variable menteur = c.var;

        new_clause.vars.push_back(menteur);

        for (Case c1 : cases) {
            if (c.var.GetIndex() != c1.var.GetIndex()) {
                Variable non_menteur = c1.var;
                non_menteur.SetNeg(!c1.var.GetNeg());

                new_clause.vars.push_back(non_menteur);
            }
        }

        clausesRegion.form.push_back(new_clause);
    }
}

void Region::ClauseConfigNonMenteur(LUT case_type_lut) {
    for (Case c : cases) {

        int available = case_type_lut.GetAvailableCaseCount(c.GetIndex());

        if (c.GetN() > available) { // Cas impossible: nombre de cases adjacentes disponibles < nombre de la case
            Clause single = Clause(forme::FND);
            Variable menteur = c.var;
            menteur.SetNeg(false);
            single.vars.push_back(menteur);
            clausesRegion.form.push_back(single);

        } else {

            vector<vector<int>> combos = case_type_lut.GetCombinationNonMenteur(c.GetIndex(), c.GetN());

            for (vector<int> comb : combos) {
                Clause clause = Clause(forme::FND);

                Variable non_menteur = c.var;
                non_menteur.SetNeg(true);
                clause.vars.push_back(non_menteur);

                for (int i : comb) {
                    Variable var = Variable(i);
                    var.SetNeg(false);
                    var.SetType(varType::COCHEE);
                    clause.vars.push_back(var);
                }
                clausesRegion.form.push_back(clause);
            }
        }


    }
}

void Region::ClauseConfigMenteur(LUT case_type_lut) {
    for (Case c : cases) {

        int available = case_type_lut.GetAvailableCaseCount(c.GetIndex());

        
        for (int k=0; k<available; k++) {
            if (k==c.GetN()) {
                continue;
            }

            vector<vector<int>> combos = case_type_lut.GetCombinationNonMenteur(c.GetIndex(), k);

            for (vector<int> comb : combos) {
                Clause clause = Clause(forme::FND);

                Variable menteur = c.var;
                menteur.SetNeg(false);
                clause.vars.push_back(menteur);

                for (int i : comb) {
                    Variable var = Variable(i);
                    var.SetNeg(false);
                    var.SetType(varType::COCHEE);
                    clause.vars.push_back(var);
                }

                clausesRegion.form.push_back(clause);
            }
        }


    }
}

void Region::RenderClauses(ostream& file) {
    if (clausesRegion.type != forme::FNC) {
        clausesRegion.Convert();
    }

    for (Clause c : clausesRegion.form) {
        file << c.GetDimacs() << "\n";
    }

}

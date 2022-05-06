#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "case.hpp"
#include "formule.hpp"
#include "lut.hpp"

using std::ostream;
using std::vector;
using std::nullptr_t;

template<nullptr_t>
class Region_ final {
    public:
    Region_(){ }

    vector<Case> cases;
    Formule clausesRegion = Formule(forme::FND);

    void CreerClauses(LUT case_type_lut){
    // Si une case est menteur, les autres ne le sont pas
    // std::cout << "Creating clauses for new region" << std::endl;
    ClauseUnMenteur();
    ClauseConfigNonMenteur(case_type_lut);
    ClauseConfigMenteur(case_type_lut);
    
    clausesRegion.AfficherFormule();
    // std::cout << "Done with creating region" << std::endl;
    // Combinaisons si une case  n'est pas menteur
}
    void RenderClauses(ostream& file);

    private:
    void ClauseUnMenteur(); // Règle: Un seul menteur par région
    void ClauseConfigNonMenteur(LUT case_type_lut); // Règle: combinaisons possibles si la case ne ment pas
    void ClauseConfigMenteur(LUT case_type_lut); // Règle: combinaisons possibles si la case ment
};


template<nullptr_t T>
void Region_<T>::ClauseUnMenteur() {
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

template<nullptr_t T>
void Region_<T>::ClauseConfigNonMenteur(LUT case_type_lut) {
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

template<nullptr_t T>
void Region_<T>::ClauseConfigMenteur(LUT case_type_lut) {
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
template<nullptr_t T>
void Region_<T>::RenderClauses(ostream& file) {
    if (clausesRegion.type != forme::FNC) {
        clausesRegion.Convert();
    }

    for (Clause c : clausesRegion.form) {
        file << c.GetDimacs() << "\n";
    }

}


using Region = Region_<nullptr>;
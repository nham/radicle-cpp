#include "common.hpp"

Atom::Atom(string s) {
    sym = s;
}

List::List(Expr *list, int n) {
    exprs = list;
    size = n;
}

bool Atom::is_atom() {
    return true;
}

bool Atom::is_empty_list() {
    return false
}

bool List::is_atom() {
    return false;
}

bool List::is_empty_list() {
    return exprs == nullptr;
}

Env::Env() {
    bindings = new map<string, Expr>();
}

EvalError::EvalError(string s) {
    error = s;
}

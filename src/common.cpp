#include "common.hpp"

Expr::Expr(string& s) {
    type = Expr::ExprType::Atom;
    sym = &s;
}

Expr::Expr(Expr* list, int n) {
    type = Expr::ExprType::List;
    exprs = list;
    exprs_size = n;
}

bool Expr::is_atom() {
    return type == Expr::ExprType::Atom;
}

bool Expr::is_list() {
    return type == Expr::ExprType::List;
}

bool Expr::is_empty_list() {
    return is_list() && exprs_size == 0;
}

Env::Env() {
    bindings = new map<string, Expr>();
}

EvalError::EvalError(string s) {
    error = s;
}

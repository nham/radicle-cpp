#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <map>
#include <tuple>

using std::string;
using std::map;
using std::tuple;

struct Expr {
    enum class ExprType : int {Nil, Atom, List};

    ExprType type = ExprType::Nil;
    string* sym = nullptr;
    Expr* exprs = nullptr;
    int exprs_size = 0;

    Expr() = default;
    explicit Expr(string& s);
    Expr(Expr* exprs, int n);

    bool is_atom();
    bool is_list();
    bool is_empty_list();
};


struct Env {
    map<string, Expr> *bindings;

    Env();
};

using ExprEnv = tuple<Expr, Env&>;

struct EvalError {
    string error;
    EvalError(string s);
};

#endif

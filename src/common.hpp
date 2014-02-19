#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <map>
#include <tuple>

using std::string;
using std::map;
using std::tuple;

struct Expr {
    explicit Expr(string s = "");
    Expr(string s, Expr *ch, int len);

    virtual bool is_atom() = 0;

    bool is_list() {
        return !is_atom();
    }

    virtual bool is_empty_list() = 0;
};

struct Atom : public Expr {
    string sym;
    explicit Atom(string s);
};

struct List : public Expr {
    Expr* exprs = nullptr;
    int size = 0;
    List() = default;
    List(Expr *list, int n);
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

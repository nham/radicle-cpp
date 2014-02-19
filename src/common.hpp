#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <map>
#include <tuple>

using std::string;
using std::map;
using std::tuple;

struct Expr {
    string sym;
    Expr *children;
    int chlen;

    explicit Expr(string s = "");
    Expr(string s, Expr *ch, int len);

    bool is_atom();
    bool is_list();
    bool is_empty_list();
    string getsym();
};


struct Env {
    map<string, Expr> *bindings;

    Env();
};

using ExprEnv = tuple<Expr, Env>;

struct EvalError;

#endif

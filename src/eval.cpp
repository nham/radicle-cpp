#include "eval.hpp"

#include <tuple>

using std::make_tuple;

ExprEnv eval(Expr expr, Env& env) {
    if (expr.is_atom()) {
        return ExprEnv { Expr {"wowowow" + expr.getsym()}, env };

    }
    return ExprEnv {expr, env};
}


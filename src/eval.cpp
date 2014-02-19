#include "eval.hpp"

#include <tuple>

using std::make_tuple;

ExprEnv eval(Expr expr, Env& env) {
    if (expr.is_atom()) {
        return ExprEnv( Expr("can't yet lookup " + expr.sym), env);
    } else if (expr.is_empty_list()) {
        throw EvalError("No procedure to call.");
    } else {
        if (expr.sym == "quote") {
            if (expr.chlen != 1)
                throw EvalError("`quote` expects exactly one argument.");
            else
                return ExprEnv(expr, env);

        } else if(expr.sym == "atom") {
            if (expr.chlen != 1)
                throw EvalError("`atom` expects exactly one argument.");
            else {
                auto res = eval(expr.children[0], env);
                auto val = res.get<0>;

                if (val.is_atom() || val.is_empty_list()) {
                    return Atom("t");
                } else {
                    return List();
                }
                return ExprEnv(expr, env);
            }

        } else if(expr.sym == "eq") {
        } else if(expr.sym == "first") {
        } else if(expr.sym == "rest") {
        } else if(expr.sym == "cons") {
        } else if(expr.sym == "cond") {
        } else {
            throw EvalError("Unimplemented.");
        }

    }
    return ExprEnv {expr, env};
}


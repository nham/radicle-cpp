#include "eval.hpp"

#include <tuple>

using std::make_tuple;

bool is_symbol(Expr& expr, string s) {
    if (!expr.is_atom()) return false;
    return *(expr.sym) == s;
}

ExprEnv eval(Expr& expr, Env& env) {
    if (expr.is_atom()) {
        throw EvalError("Unimplemented.");
    } else if (expr.is_empty_list()) {
        throw EvalError("No procedure to call.");
    } else {
        auto head = expr.exprs[0];
        if (is_symbol(head, "quote")) {
            if (expr.exprs_size != 1)
                throw EvalError("`quote` expects exactly one argument.");
            else
                return ExprEnv(expr, env);

        } else if(is_symbol(head, "atom")) {
            if (expr.exprs_size != 1)
                throw EvalError("`atom` expects exactly one argument.");
            else {
                auto res = eval(expr.exprs[1], env);
                auto val = std::get<0>(res);

                if (val.is_atom() || val.is_empty_list()) {
                    return Expr("t");
                } else {
                    return Expr(nullptr, 0);
                }
                return ExprEnv(expr, env);
            }

        } else if(is_symbol(head, "eq")) {
        } else if(is_symbol(head, "first")) {
        } else if(is_symbol(head, "rest")) {
        } else if(is_symbol(head, "cons")) {
        } else if(is_symbol(head, "cond")) {
        } else {
            throw EvalError("Unimplemented.");
        }

    }
    return ExprEnv {expr, env};
}



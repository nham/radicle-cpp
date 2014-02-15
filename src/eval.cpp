#include "common.hpp"

#include <tuple>

struct EvalResult {
    Expr expr;
    Env env;
};

EvalResult eval(Expr expr, Env env) {
    return EvalResult {expr, env};
}


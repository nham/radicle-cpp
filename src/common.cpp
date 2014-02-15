#include "common.hpp"

using namespace std;

Expr::Expr(string s) {
    sym = s;
    children = nullptr;
    chlen = 0;
}

Expr::Expr(string s, Expr *ch, int len) {
    sym = s;
    children = ch;
    chlen = len;
}

bool Expr::is_atom() {
    return children == nullptr;
}

bool Expr::is_list() {
    return ! is_atom();
}

bool Expr::is_empty_list() {
    return is_list() && chlen == 0;
}

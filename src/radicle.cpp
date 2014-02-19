#include "common.hpp"
#include "eval.hpp"

#include <iostream>

using std::cout;

void interpret_file(char* fname) {
    for (; fname != '\0'; ++fname) {
        cout << *fname << '\n';
    }
}


int main(int argc, char* argv[]) {

    if (argc == 1) {
        cout << "Repl not yet implemented.\n";
    } else if (argc > 2) {
        cout << "radicle: Only one source file allowed.\n";
    } else {
        cout << argv[1] << '\n';
        auto x = Expr("quote");
        cout << x.is_atom() << '\n';

        auto y = Expr("foo", nullptr, 0);
        cout << y.is_atom() << '\n';

        auto a = Expr("a");
        auto b = Expr("b");
        auto c = Expr("c");
        Expr abc[3] = {a, b, c};
        auto z = Expr("quote", abc, 3);
        cout << z.is_atom() << z.is_list() << '\n';

        Expr nope[] = {};
        auto z2 = Expr("foo", nope, 0);
        cout << z2.is_atom() << z2.is_list() << '\n';

        auto env = Env();
        auto res = eval(x, env);

        //interpret_file(argv[1]);
    }
}

#include <string>

using namespace std;

struct Env;

class Expr {
    string sym;
    Expr *children;
    int chlen;
    public:
        explicit Expr(string s = "");
        Expr(string s, Expr *ch, int len);
        bool is_atom();
        bool is_list();
        bool is_empty_list();
};

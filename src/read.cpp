#include "read.hpp"

#include <cctype>

using std::isspace;


vector<string> tokenize(string& input) {
    vector<string> tokens {};
    string token;
    bool is_paren = false;
    for (auto c : input) {
        if (!inside_token && isspace(c))
            continue;

        if (c == '(' || c == ')')
            is_parent == true;

        if (token != "" && (is_paren || isspace(c))) {
            tokens.push_back(token);

            token = "";

        }

        if (is_paren) {
            token.push_back(c);
            tokens.push_back(token);
        }

    }

}

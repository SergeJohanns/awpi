#include <iostream>
#include <string>
#include <queue>
#include "asp.hpp"
#include "lexer.hpp"
#include "constants.hpp"
#include "symbol_check.hpp"

void syntax_error(std::string message) {
    std::cout << message << std::endl;
    exit(ERROR_STATUS);
}

void not_empty(std::queue<std::string> &tokens) {
    if (tokens.empty()) {
        syntax_error("Unexpected EOL");
    }
}

std::queue<std::string> tokenize(std::string source) {
    std::queue<std::string> out;
    int space = source.find(' ');
    while (space != -1) {
        out.push(source.substr(0, space));
        source = source.substr(space + 1);
        space = source.find(' ');
    }
    return out;
}

std::queue<std::string> fetch_do(std::queue<std::string> &tokens) {
    if (tokens.front() != DO) {
        syntax_error("Unexpected symbol \"" + tokens.front() + "\", expected " + DO + ".");
    }
    tokens.pop(); // Remove DO
    std::queue<std::string> out;
    while (!tokens.empty() && tokens.front() != OD) {
        out.push(tokens.front());
        tokens.pop();
    }
    not_empty(tokens);
    tokens.pop(); // Remove OD
    return out;
}

AbstractSyntaxTree lex(std::queue<std::string> tokens) {
    if (tokens.empty()) {
        return AbstractSyntaxTree("");
    }
    std::string token = tokens.front();
    tokens.pop();
    auto out = AbstractSyntaxTree("");
    if (token == "") {
        return lex(tokens);
    } else if (token == WHILE) {
        out = AbstractSyntaxTree(WHILE);
        not_empty(tokens);
        out.children.push_back(AbstractSyntaxTree(tokens.front()));
        tokens.pop();
        not_empty(tokens);
        auto body = fetch_do(tokens);
        out.children.push_back(lex(body));
    } else if (is_identifier(token)) {
        not_empty(tokens);
        if (tokens.front() == ASSIGN) {
            out = AbstractSyntaxTree(ASSIGN);
            out.children.push_back(AbstractSyntaxTree(token));
            tokens.pop();
            not_empty(tokens);
            if (is_constant(tokens.front())) {
                out.children.push_back(AbstractSyntaxTree(tokens.front()));
                tokens.pop();
            } else if (is_identifier (tokens.front())) {
                auto first = tokens.front();
                tokens.pop();
                not_empty(tokens);
                auto expr = AbstractSyntaxTree("");
                if (tokens.front() == PLUS) {
                    expr = AbstractSyntaxTree(PLUS);
                } else if (tokens.front() == MINUS) {
                    expr = AbstractSyntaxTree(MINUS);
                } else {
                    syntax_error("Invalid expression \"" + tokens.front() + "\"");
                }
                tokens.pop();
                not_empty(tokens);
                auto second = tokens.front();
                tokens.pop();
                if (!is_identifier(tokens.front())) {
                    syntax_error("Invalid identifier \"" + second + "\"");
                }
                expr.children.push_back(AbstractSyntaxTree(first));
                expr.children.push_back(AbstractSyntaxTree(second));
            } else {
                syntax_error("Invalid identifier \"" + tokens.front() + "\"");
            }
        } else {
            syntax_error("Unexpected identifier \"" + token + "\"");
        }
    } else {
        syntax_error("Unexpected symbol \"" + token + "\"");
    }
    auto cons = AbstractSyntaxTree(CONS);
    cons.children.push_back(out);
    cons.children.push_back(lex(tokens));
    return cons;
}

AbstractSyntaxTree lex(std::string source) {
    return lex(tokenize(source));
}

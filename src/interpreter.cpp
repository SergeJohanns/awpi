#include <string>
#include <unordered_map>
#include "interpreter.hpp"
#include "constants.hpp"
#include "natural.hpp"
#include "errors.hpp"
#include "asp.hpp"

void has_var(state &program_state, std::string &key) {
    if (program_state.count(key) == 0) {
        symbol_undefined(key);
    }
}

Natural eval(AbstractSyntaxTree code, state &program_state) {
    has_var(program_state, code.children[0].token);
    has_var(program_state, code.children[1].token);
    if (code.token == PLUS) {
        return Natural(code.children[0].token) + Natural(code.children[1].token);
    } else if (code.token == MINUS) {
        return Natural(code.children[0].token) - Natural(code.children[1].token);
    } else {
        symbol_undefined(code.token);
        return Natural::zero();
    }
}

void exec(AbstractSyntaxTree code, state &program_state) {
    if (code.token == NOP) {
    } else if (code.token == WHILE) {
        has_var(program_state, code.children[0].token);
        while (program_state[code.children[0].token] != Natural::zero()) {
            exec(code.children[1], program_state);
        }
    } else if (code.token == ASSIGN) {
        Natural value = Natural::zero();
        if (code.children[1].token == PLUS || code.children[1].token == MINUS) {
            value = eval(code.children[1], program_state);
        } else {
            value = Natural(code.children[1].token);
        }
        program_state[code.children[0].token] = value;
    } else if (code.token == CONS) {
        exec(code.children[0], program_state);
        exec(code.children[1], program_state);
    } else {
        invalid_ast(code);
    }
}

state exec(AbstractSyntaxTree code) {
    state prog = state();
    exec(code, prog);
    return prog;
}
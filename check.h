#pragma once
#include <iostream>
#include <vector>
#include "check.h"


void help() {
    std::cout << "Contact jayden@pludo.dev for technical support" << std::endl;
}

void leave() {
    std::cout << "thanks for using plush <3" << std::endl;
    exit(EXIT_SUCCESS);
}

void add(float a, float b) {
    std::cout << a + b << std::endl;
}

void multiply(float a, float b) {
    std::cout << a * b << std::endl;
}

void divide(float a, float b) {
    std::cout << a / b << std::endl;
}

void squareroot(float a) {
    std::cout << sqrt(a) << std::endl;
}

std::vector<std::string> split(std::string input) {
    std::vector<std::string> args;
    std::string temp = "";
    for (char c : input + ' ') { // append space at the end so I can detect when last word actually ends
        if (c == ' ' || c == '\n' || c == '\0') {
            args.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }

    return args;
}

bool exists(std::string init_arg, std::vector<std::string> possible_commands) {
    for (std::string command : possible_commands) {
        if (init_arg == command) {
            return true;
        }
    }
    return false;
}


void execute(std::vector<std::string> &args) {
    if (args.at(0) == "help") { help(); }
    else if (args.at(0) == "leave") { leave(); }

    else if (args.at(0) == "add") {
        try {
            float arg1 = stof(args.at(1));
            float arg2 = stof(args.at(2));
            add(arg1, arg2);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: add a b" << std::endl;
        }
    }

    else if (args.at(0) == "multiply") {
        try {
            float arg1 = stof(args.at(1));
            float arg2 = stof(args.at(2));
            multiply(arg1, arg2);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: multiply a b" << std::endl;
        }
    }

    else if (args.at(0) == "divide") {
        try {
            float arg1 = stof(args.at(1));
            float arg2 = stof(args.at(2));
            divide(arg1, arg2);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: divide a b" << std::endl;
        }
    }
}
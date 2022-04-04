#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include "check.h"


void help() {
    // print file
    std::ifstream help("help.plush");
    if (help.is_open()) {
        std::cout << help.rdbuf();
    }
}

void leave() {
    std::cout << "thanks for using plush <3" << std::endl;
    exit(EXIT_SUCCESS);
}

void clear() {
    system("cls");
}

void add(float a, float b) {
    std::cout << a + b << std::endl;
}

void sub(float a, float b) {
    std::cout << a - b << std::endl;
}

void mult(float a, float b) {
    std::cout << a * b << std::endl;
}

void div(float a, float b) {
    std::cout << a / b << std::endl;
}

void power(float a, float b) {
    std::cout << pow(a, b) << std::endl;
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
    else if (args.at(0) == "leave") { if (args.size() > 2) { std::cout << "too many arguments | usage: leave" << std::endl; } else { leave(); } }

    else if (args.at(0) == "clear") { if (args.size() > 2) { std::cout << "too many arguments | usage: clear" << std::endl; } else { clear(); } }

    else if (args.at(0) == "add") {
        if (args.size() > 3) {
            std::cout << "too many arguments | usage: add a b" << std::endl;
            return;
        }
        try {
            float arg1 = stof(args.at(1));
            float arg2 = stof(args.at(2));
            add(arg1, arg2);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: add a b" << std::endl;
        }
    }

    else if (args.at(0) == "sub") {
        if (args.size() > 3) {
            std::cout << "too many arguments | usage: sub a b" << std::endl;
            return;
        }

        try {
            float arg1 = stof(args.at(1));
            float arg2 = stof(args.at(2));
            sub(arg1, arg2);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: sub a b" << std::endl;
        }
    }

    else if (args.at(0) == "mult") {
        if (args.size() > 3) {
            std::cout << "too many arguments | usage: mult a b" << std::endl;
            return;
        }

        try {
            float arg1 = stof(args.at(1));
            float arg2 = stof(args.at(2));
            mult(arg1, arg2);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: mult a b" << std::endl;
        }
    }

    else if (args.at(0) == "div") {
        if (args.size() > 3) {
            std::cout << "too many arguments | usage: div a b" << std::endl;
            return;
        }

        try {
            float arg1 = stof(args.at(1));
            float arg2 = stof(args.at(2));
            div(arg1, arg2);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: div a b" << std::endl;
        }
    }

    else if (args.at(0) == "power") {
        if (args.size() > 3) {
            std::cout << "too many arguments | usage: power a b" << std::endl;
            return;
        }
        try {
            float arg1 = stof(args.at(1));
            float arg2 = stof(args.at(2));
            power(arg1, arg2);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: power a b" << std::endl;
        }
    }

    else if (args.at(0) == "sqrt") {
        if (args.size() > 2) {
            std::cout << "too many arguments | usage: sqrt a" << std::endl;
            return;
        }
        try {
            float arg1 = stof(args.at(1));
            squareroot(arg1);
        } catch(...) {
            std::cerr << "plush couldn't parse your arguments | usage: sqrt a" << std::endl;
        }
    }
}
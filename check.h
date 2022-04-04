#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include "check.h"

// I honestly hate how horribly this looks, originally it was a file that would be loaded then printed, but I want
// this shell to be a standalone executable, therefore I cannot have a reliance on external files
void help() {
    std::cout << "general" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "leave | quits the shell | usage: leave" << std::endl;
    std::cout << "clear | clears the console | usage: clear" << std::endl;
    std::cout << std::endl;
    std::cout << "arithmetic" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "add | adds two numbers | usage: add a b" << std::endl;
    std::cout << "sub | subtracts two numbers | usage: sub a b" << std::endl;
    std::cout << "mult | multiplies two numbers | usage: mult a b" << std::endl;
    std::cout << "div | divides two numbers | usage: div a b" << std::endl;
    std::cout << "power | gets a to the power of b | usage: power a b" << std::endl;
    std::cout << "sqrt | gets the squareroot of a | usage: sqrt a" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
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
    if (args.at(0) == "help") { if (args.size() > 1) { std::cout << "too many arguments | usage: help" << std::endl; } else { help(); } }
    else if (args.at(0) == "leave") { if (args.size() > 1) { std::cout << "too many arguments | usage: leave" << std::endl; } else { leave(); } }

    else if (args.at(0) == "clear") { if (args.size() > 1) { std::cout << "too many arguments | usage: clear" << std::endl; } else { clear(); } }

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
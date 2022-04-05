#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <stdlib.h>
#include "check.h"


#define INFO_BUFFER_SIZE 32767



// I honestly hate how horrible this looks, originally it was a file that would be loaded then printed, but I want
// this shell to be a standalone executable, therefore I cannot have a reliance on external files
void help() {
    std::cout << std::endl;
    std::cout << "contact: jayden@pludo.dev" << std::endl;
    std::cout << std::endl;
    std::cout << "general" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "leave  | quits the shell                    | usage: leave" << std::endl;
    std::cout << "clear  | clears the console                 | usage: clear" << std::endl;
    std::cout << "create | creates a file                     | usage: create hello.txt" << std::endl;
    std::cout << "delete | deletes a file                     | usage: delete hello.txt" << std::endl;
    std::cout << "rename | renames a file                     | usage: rename hello.txt bye.txt" << std::endl;
    std::cout << "wdir   | gets working directory             | usage: wdir" << std::endl;
    std::cout << "cdir   | changes working directory          | usage: cdir dir" << std::endl;
    std::cout << "hash   | outputs the hash of a given file   | usage: hash hello.txt" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "arithmetic" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "add   | adds two numbers         | usage: add a b" << std::endl;
    std::cout << "sub   | subtracts two numbers    | usage: sub a b" << std::endl;
    std::cout << "mult  | multiplies two numbers   | usage: mult a b" << std::endl;
    std::cout << "div   | divides two numbers      | usage: div a b" << std::endl;
    std::cout << "power | gets a to the power of b | usage: power a b" << std::endl;
    std::cout << "sqrt  | gets the squareroot of a | usage: sqrt a" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void leave() {
    std::cout << "thanks for using plush <3" << std::endl;
    exit(EXIT_SUCCESS);
}

void clear() {
    system("cls");
}

void create(std::string file_name) {
    std::cout << "creating file '" << file_name << "'" << std::endl;
    std::ofstream file(file_name);
    file.close();
}

void wdir() {
    std::cout << std::filesystem::current_path() << std::endl;
}

void cdir(std::string dir) {
    chdir(dir.c_str());
}

void hash(std::string file_name) {
    std::cout << std::filesystem::hash_value(file_name) << std::endl;
}

void rename(std::string original, std::string rename) {
    std::cout << "renaming '" << original << "' to '" << rename << "'" << std::endl;
    std::filesystem::rename(original, rename);
}

void deletef(std::string file_name) {
    std::cout << "are you sure you want to delete '" << file_name << "'? (y/n): ";
    char i;
    std::cin >> i;
    if (i == 'y') {   
        std::cout << "deleting '" << file_name << "'" << std::endl;
        remove(file_name.c_str());
    } else if (i == 'n') {
        std::cout << "cancelling operation" << std::endl;
    } else {
        std::cout << "undefined option, cancelling operation" << std::endl;
    }
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
    else if (args.at(0) == "leave") {
        if (args.size() > 1) {
            std::cout << "too many arguments | usage: leave" << std::endl;
        } else {
            leave();
        } 
    }

    else if (args.at(0) == "clear") {
        if (args.size() > 1) {
            std::cout << "too many arguments | usage: clear" << std::endl;    
        } else {
            clear();
        } 
    }

    else if (args.at(0) == "create") {
        try {
            if (args.size() > 2) {
                std::cout << "too many arguments | usage: create hello.txt" << std::endl;
            } else {
                create(args.at(1));
            }
        } catch (...) {
            std::cout << "not enough arguments | usage: create hello.txt" << std::endl;
        }
    }

    else if (args.at(0) == "delete") {
        try {
            if (args.size() > 2) {
                std::cout << "too many arguments | usage: delete hello.txt" << std::endl;
            } else {
                deletef(args.at(1));
            }
        } catch (...) {
            std::cout << "not enough arguments | usage: delete hello.txt" << std::endl;
        }
    }


    else if (args.at(0) == "wdir") {
        if (args.size() > 1) {
            std::cout << "too many arguments | usage: wdir" << std::endl;
        } else {
            wdir(); 
        } 
    }

    else if (args.at(0) == "cdir") {
        try {  
            if (args.size() > 2) {
                std::cout << "too many arguments | usage: cdir dir" << std::endl;
            } else {
                cdir(args.at(1));
            } 
        } catch(...) {
            std::cout << "not enough arguments | usage: cdir dir" << std::endl;
        }
    }

    else if (args.at(0) == "hash") {
        try {  
            if (args.size() > 2) {
                std::cout << "too many arguments | usage: hash hello.txt" << std::endl;
            } else {
                hash(args.at(1));
            } 
        } catch(...) {
            std::cout << "not enough arguments | usage: hash hello.txt" << std::endl;
        }
    }

    else if (args.at(0) == "rename") {
        try {
            if (args.size() > 3) {
                std::cout << "too many arguments | usage: rename hello.txt bye.txt" << std::endl;
            } else {
                rename(args.at(1), args.at(2));
            }
        } catch (...) {
            std::cout << "not enough arguments | usage: rename hello.txt bye.txt" << std::endl;
        }
    }

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
            std::cerr << "not enough arguments | usage: add a b" << std::endl;
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
            std::cerr << "not enough arguments | usage: sub a b" << std::endl;
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
            std::cerr << "not enough arguments | usage: mult a b" << std::endl;
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
            std::cerr << "not enough arguments | usage: div a b" << std::endl;
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
            std::cerr << "not enough arguments | usage: power a b" << std::endl;
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
            std::cerr << "not enough arguments | usage: sqrt a" << std::endl;
        }
    }
}
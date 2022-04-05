#include <iostream>
#include <vector>

#include "logging.h"
#include "check.h"

std::vector<std::string> commands = {"help", "leave", "clear", "create", "wdir", "cdir",
                                     "rename", "hash", "add", "sub", "mult", "div",
                                     "power", "sqrt", "delete"};

bool active = true;
void loop() {
    while (active) {
        std::cout << "plush > ";
        std::string input = pull();
        std::vector<std::string> args = split(input);

        if (exists(args.at(0), commands)) {
            execute(args);
        } else {
            std::cout << '"' << args.at(0) << '"' << " isn't recognized as a command" << std::endl;
        }
    }
}

int main() {
    std::cout << "welcome to plush, a lightweight shell" << std::endl;
    std::cout << "get started with 'help'" << std::endl;
    loop();
    return EXIT_SUCCESS;
}
#include <iostream>
#include <vector>
#include <map>

#include "logging.h"
#include "check.h"

std::vector<std::string> commands = {"help", "leave", "add", "multiply", "divide"};

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
    loop();
    return EXIT_SUCCESS;
}
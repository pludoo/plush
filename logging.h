#pragma once
#include <iostream>
#include <string>

void put(std::string message) { std::cout << message << std::endl; }
void put_error(std::string message) { std::cerr << "error: " << message << std::endl; }
std::string pull() { std::string temp; getline(std::cin, temp); return temp; }
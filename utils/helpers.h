#ifndef HELPERS_H
#define HELPERS_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

void clear_screen() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Unix/Linux
    #endif
}

void loadEnv(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open .env file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        int commentPos = line.find('#');
        if (commentPos != std::string::npos) {
            line = line.substr(0, commentPos);
        }
        if (line.empty()) continue;

        // Split the line into key and value
        int delimiterPos = line.find('=');
        if (delimiterPos == std::string::npos) continue;

        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        // Remove any leading/trailing whitespace from key and value
        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);

        // Set the environment variable
        if (setenv(key.c_str(), value.c_str(), 1) != 0) {
            std::cerr << "Error: Could not set environment variable " << key << std::endl;
        }
    }
}

#endif // DEBUG

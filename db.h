#ifndef DATABASE__H
#define DATABASE__H

#include <iostream>
#include <string>
#include <vector>  
#include "models/user.h"
#include "models/travel.h"
#include "models/register.h"

class Database {

    static std::vector<User> users;
    static std::vector<Travel> travels;
    static std::vector<Register> registers;

public:
    // Static initialization of travels
    static void initialize() {
        if (Database::travels.empty()) {
            Database::travels.emplace_back("Sao Paulo", "2024-08-08");
            Database::travels.emplace_back("Minas Gerais", "2024-08-08");
            Database::travels.emplace_back("Paris", "2024-08-08");
        }
    }
    
    static void insertTravel(std::string travel, std::string date) {
        travels.emplace_back(travel, date);
    }

    static std::vector<Travel> selectAllFromTravels() {
        return Database::travels;
    }

    static void insertRegister(std::string name, std::string email, std::string travel, std::string date) {
        registers.emplace_back(name, email, travel, date);
    }

    static std::vector<Register> selectAllFromRegister() {
      return Database::registers;
    }
};

std::vector<Travel> Database::travels = std::vector<Travel>();  
std::vector<Register> Database::registers = std::vector<Register>();  

#endif

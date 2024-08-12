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
    static void initialize() {
            Database::travels.emplace_back("Miami", "10/09/2024");
            Database::travels.emplace_back("Los Angeles", "03/02/2025");
            Database::travels.emplace_back("Paris", "24/02/2025");
            Database::travels.emplace_back("Roma", "11/10/2024");

            Database::registers.emplace_back("Ryan de Oliveira", "ryandehallo229@gmail.com", "Miami", "10/09/2024");
            Database::registers.emplace_back("Marcelo Correa", "macorrea-@hotmail.com", "Los Angeles", "03/02/2025");
        // }
    }
    
    static void insertUser(std::string name, std::string email) {
        users.emplace_back(name, email);
    }

    static void insertTravel(std::string travel, std::string date) {
        travels.emplace_back(travel, date);
    }

    static std::vector<Travel> selectAllFromTravels() {
        return Database::travels;
    }

    static void insertRegister(User user, Travel travel) {
        registers.emplace_back(user.getName(), user.getEmail(), travel.getName(), travel.getDate());
    }

    static std::vector<Register> selectAllFromRegister() {
      return Database::registers;
    }
};

std::vector<Travel> Database::travels = std::vector<Travel>();  
std::vector<Register> Database::registers = std::vector<Register>();  
std::vector<User> Database::users = std::vector<User>();  

#endif

#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <string>
#include <string>
#include <vector>
#include "../db.h"

class UserController {
public: 
    static User post(std::string name, std::string email) {
        Database::insertUser(name, email);
        return User(name, email);
    }
};

#endif
#include <string>
#include <string>
#include <vector>
#include "../db.h"

class RegisterController {
public: 
    static void post(std::string name, std::string email, std::string travel, std::string date) {
        Database::insertRegister(name, email, travel, date);
    }

    static std::vector<Register> get() {
        return Database::selectAllFromRegister();
    }
};
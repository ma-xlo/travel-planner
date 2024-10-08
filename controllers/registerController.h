#include <string>
#include <string>
#include <vector>
#include "../db.h"

class RegisterController {
public: 
    static void post(User user, Travel travel) {
        Database::insertRegister(user, travel);
    }

    static std::vector<Register> get() {
        return Database::selectAllFromRegister();
    }
};
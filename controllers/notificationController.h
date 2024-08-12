#ifndef NOTIFICATIONCONTROLLER_H
#define NOTIFICATIONCONTROLLER_H

#include <string>
#include <string>
#include <vector>
#include "../db.h"

class NotificationController {
public: 
    static std::vector<Register> get() {
        return Database::selectAllFromRegister();
    }
};

#endif
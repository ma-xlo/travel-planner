#ifndef TRAVELCOTROLLER_H
#define TRAVELCOTROLLER_H

#include <string>
#include <string>
#include <vector>
#include "../db.h"

class TravelController {
public: 
    static std::vector<Travel> get() {
        return Database::selectAllFromTravels();
    }

    static void post(std::string travel, std::string date) {
        Database::insertTravel(travel, date);
    }
};

#endif
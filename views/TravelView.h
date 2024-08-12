#ifndef TRAVELVIEW_H
#define TRAVELVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "../db.h"
#include "../controllers/travelController.h"

class TravelView {
public:
    static std::vector<Travel> travels;

    static void create() {
        std::string travel;
        std::string date;
        std::string option;
        std::cout<<"Viagem: ";
        std::getline (std::cin, travel);
        std::cout<<"Data: ";
        std::getline (std::cin, date);
        TravelController::post(travel, date); 

        std::cout<<std::endl<<"Adicionado com suceso!"<<std::endl;
        std::getline (std::cin, option);

    }

    static void list() {
        TravelView::travels = TravelController::get(); 
        printf("+--------------------------------------------------------+\n");
        printf("|                     Viagens Agendadas                  |\n");
        printf("+--------------------------------------------------------+\n");
        printf("| Destino                                   | Data       |\n");
        printf("+-------------------------------------------+------------+\n");
        for (const auto& travel : travels) {
            printf("| %-41s | %-10s |\n", travel.getName().c_str(), travel.getDate().c_str());
        }
        printf("+-------------------------------------------+------------+\n");
        std::string option;
        std::getline (std::cin, option);
        return; 
    }
};

#endif // TRIPSVIEW_H

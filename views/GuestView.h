#ifndef GUESTVIEW_H
#define GUESTVIEW_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "../db.h"
#include "../controllers/travelController.h"
#include "../controllers/registerController.h"
#include "../controllers/userController.h"
#include "../utils/helpers.h"

class GuestsView {
public:
    static std::vector<Travel> travels;

    static void create () {
        std::string name;
        std::string email;

        printf("Nome: ");
        std::getline (std::cin, name);
        printf("Email: ");
        std::getline (std::cin, email);

        // Cria usuario convidado
        User user = UserController::post(name, email);
        // Obtem lista de viagens agendadas
        GuestsView::travels = TravelController::get(); 

        clear_screen();
        int count = 1;
        printf("+-----------------------------------------------------------+\n");
        printf("|                     Viagens Agendadas                     |\n");
        printf("+--------+-------------------------------------+------------+\n");
        printf("| Opcao  | Destino                             | Data       |\n");
        printf("+--------+-------------------------------------+------------+\n");
        for (const auto& travel : travels) {
            printf("| %-6d | %-35s | %-10s |\n", count++, travel.getName().c_str(), travel.getDate().c_str());
        }
        printf("+--------+-------------------------------------+------------+\n");
        std::cout<<"Viagem: ";
        std::string option;
        std::getline (std::cin, option);
        
        int travelIndex = std::stoi(option);
        Travel selectedTravel = travels[travelIndex - 1];
        
        // Realiza um cadastro de usuario convidado
        RegisterController::post(user, selectedTravel);

        std::cout<<std::endl<<"Adicionado com suceso!"<<std::endl;
        std::getline (std::cin, option);
    }

    static void list() {
        std::vector<Register> registers = RegisterController::get();

        printf("+-------------------------------------------------------------------------------------------+\n");
        printf("|                                        Convidados                                         |\n");
        printf("+----------------------+--------------------------------+---------------------+-------------+\n");
        printf("| Nome                 | Email                          | Viagem              | Data        |\n");
        printf("+----------------------+--------------------------------+---------------------+-------------+\n");
        for (const auto& registerUser : registers) {
            printf("| %-20s | %-30s | %-19s | %-11s |\n",
                registerUser.getName().c_str(),
                registerUser.getEmail().c_str(),
                registerUser.getTravel().c_str(),
                registerUser.getDate().c_str());
        }
        printf("+----------------------+--------------------------------+---------------------+-------------+\n");
        std::string option;
        std::getline (std::cin, option);
    }
};


#endif 
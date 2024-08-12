#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "db.h"
#include "services/notification.h"

//
// Utils
//
#include "utils/helpers.h"

//
// Views
//
#include "views/MenuView.h"
#include "views/TravelView.h"
#include "views/GuestView.h"

//
// Controllers
//
#include "controllers/notificationController.h"

std::vector<Travel> TravelView::travels;
std::vector<Travel> GuestsView::travels;

int main() {
    Database::initialize();
    Subject subject;
    EmailNotifier emailNotifier;

    subject.addObserver(&emailNotifier);

    std::string opcao;
    std::string mainUser;

    clear_screen();
    std::cout<<"Usuário: ";
    std::getline (std::cin, mainUser);

    while (true) {
      clear_screen();
      opcao = MenuView::menu();

      switch (opcao[0]) {
        case '1':
          clear_screen();
          TravelView::create();  
          break;
        case '2':
          clear_screen();
          TravelView::list();  
          break;
        case '3':
          clear_screen();
          GuestsView::create();  
          break;
        case '4':
          clear_screen();
          GuestsView::list();  
          break;
        case '5':
          clear_screen();
          std::vector<Register> guestUsers = NotificationController::get();
          
          for (const auto& user : guestUsers) {
            subject.notifyObservers(mainUser, user.getName(), user.getEmail(), user.getTravel(), user.getDate());
          }

          std::cout << "Todos os convidados foram notificados!" << std::endl;
          std::string option;
          std::getline (std::cin, option);
          break;
      }
    }
    return 0;
}

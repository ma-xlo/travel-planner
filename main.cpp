// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <stdlib.h>
// #include "db.h"
// #include "services/notification.h"

// //
// // Utils
// //
// #include "utils/helpers.h"

// //
// // Views
// //
// #include "views/menu.h"
// #include "views/TripsView.h"
// // #include "views/createTripView.h"
// // #include "views/addParticipantView.h"
// // #include "views/visualizeParticipantsView.h"

// int main() {
//   // Database db;
//   // EmailNotifier emailNotifier;

//   while(true) {
//     clear_screen();
//     // std::string opcao = menu();
//     Trips::view();
    
//     // if(opcao == "1") {
//     //   clear_screen();
//     // //   // createTripView();
//     // }
//     // if (opcao == "2") {
//     //   clear_screen();
//     // }

//     // else if (opcao == "3") {
//     //   clear_screen();
//     //   // addParticipantView(db);
//     // }

//     // else if (opcao == "4") {
//     //   clear_screen();
//       // visualizeParticipantsView(db);
//     // }
//     // else if (opcao == "5") {
//     //   clear_screen();
//       // emailNotifier.notify(db);
//     //   std::cout << "Todos os participantes foram notificados!" << std::endl;
//     //   std::string option;
//     //   std::getline (std::cin, option);
//     // }
//   }
//   return 0;
// }
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
#include "views/TripsView.h"
#include "views/GuestView.h"

std::vector<Travel> TripsView::travels;
std::vector<Travel> GuestsView::travels;

int main() {
    Database::initialize();
    std::string opcao;

    while (true) {
      clear_screen();
      opcao = menu();

      switch (opcao[0]) {
      case '1':
        clear_screen();
        TripsView::create();  
        break;
      case '2':
        clear_screen();
        TripsView::list();  
        break;
      case '3':
        clear_screen();
        GuestsView::create();  
        break;
      case '4':
        clear_screen();
        GuestsView::list();  
      break;
      default:
        break;
      }
    }

    return 0;
}

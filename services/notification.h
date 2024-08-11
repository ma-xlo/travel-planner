#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "../db.h"
#include "../utils/helpers.h"

const std::string SENDGRID_API_KEY = "teste-teste-teste";
const std::string TEMPLATE_ID = "teste-teste-teste";

class EmailNotifier {
public:
  std::string recipientName = "Recipient Name"; 
  std::string content = "Teste de envio de email"; 
  std::string subject = "Bem vindo ao Planner!"; 

  int sendEmail(
    std::string user,
    std::string invitedUser,
    std::string email,
    std::string travel,
    std::string date) {

    std::string command = "curl --request POST "
                          "--url https://api.sendgrid.com/v3/mail/send "
                          "--header \"Authorization: Bearer " + SENDGRID_API_KEY + "\" "
                          "--header \"Content-Type: application/json\" "
                          "--data '{\"personalizations\": [{\"to\": [{\"email\": \"" + email + "\"}], "
                          "\"dynamic_template_data\": {\"user\": \"" + user + "\", \"invitedUser\": \"" + invitedUser + "\", \"travel\": \"" + travel + "\", \"date\": \"" + date + "\"}}], "
                          "\"from\": {\"email\": \"correa.marcelo@aluno.ifsp.edu.br\"}, "
                          "\"template_id\": \""+ TEMPLATE_ID + "\"}'";
    std::system(command.c_str());
    return 0;
  }

  void notify(Database& db) {
    std::vector<Register> invitedUsers = db.selectAllFromRegister();

    for (const auto& invitedUser : invitedUsers) {
        this->sendEmail(
          "Ryan",
          invitedUser.getName(),
          invitedUser.getEmail(),
          invitedUser.getTravel(),
          invitedUser.getDate()
        );
    }
  }

};

#endif 
#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "../db.h"
#include "../utils/helpers.h"

const std::string SENDGRID_API_KEY = "teste-teste-teste";
const std::string TEMPLATE_ID = "teste-teste-teste";

class Observer {
public:
    virtual ~Observer() {}
    virtual void update(const std::string& user, const std::string& guestUser, const std::string& email, const std::string& travel, const std::string& date) = 0;
};

class EmailNotifier : public Observer {
public:
    std::string recipientName = "Recipient Name"; 
    std::string content = "Teste de envio de email"; 
    std::string subject = "Bem vindo ao Planner!"; 

    int sendEmail(
        std::string user,
        std::string guestUser,
        std::string email,
        std::string travel,
        std::string date
    ) {
        std::string command = "curl --request POST "
                              "--url https://api.sendgrid.com/v3/mail/send "
                              "--header \"Authorization: Bearer " + SENDGRID_API_KEY + "\" "
                              "--header \"Content-Type: application/json\" "
                              "--data '{\"personalizations\": [{\"to\": [{\"email\": \"" + email + "\"}], "
                              "\"dynamic_template_data\": {\"user\": \"" + user + "\", \"invitedUser\": \"" + guestUser + "\", \"travel\": \"" + travel + "\", \"date\": \"" + date + "\"}}], "
                              "\"from\": {\"email\": \"correa.marcelo@aluno.ifsp.edu.br\"}, "
                              "\"template_id\": \""+ TEMPLATE_ID + "\"}'";
        std::system(command.c_str());
        return 0;
    }

    void update(const std::string& user, const std::string& guestUser, const std::string& email, const std::string& travel, const std::string& date) override {
        sendEmail(user, guestUser, email, travel, date);
    }
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyObservers(const std::string& user, const std::string& guestUser, const std::string& email, const std::string& travel, const std::string& date) {
        for (Observer* observer : observers) {
            observer->update(user, guestUser, email, travel, date);
        }
    }
};


#endif
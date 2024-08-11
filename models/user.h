#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>

class User {
private:
  std::string name;
  std::string email;
public:
  User(std::string name, std::string email) {
    this->name = name;
    this->email = email;
  }

  std::string getName() const { return this->name; }
  std::string getEmail() const { return this->email; }
};

#endif // USER_H




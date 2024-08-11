#ifndef REGISTER_H
#define REGISTER_H

#include <string>
#include <vector>

class Register {
private:
  std::string name;
  std::string travel;
  std::string date;
  std::string email;

public:
  Register(std::string name, std::string email, std::string travel, std::string date) {
    this->name = name;
    this->email = email;
    this->travel = travel;
    this->date = date;
  }

  // Getter methods marked as const
  std::string getName() const { return name; }
  std::string getTravel() const { return travel; }
  std::string getDate() const { return date; }
  std::string getEmail() const { return email; }
};

#endif // USER_H

#ifndef TRAVEL_H
#define TRAVEL_H

#include <string>
#include <vector>

class Travel {
private:
  std::string name;
  std::string date;
public:
  Travel(std::string name, std::string date) {
    this->name = name;
    this->date = date;
  }

  std::string getName() const { return this->name; }
  std::string getDate() const { return this->date; }
};


#endif // USER_H

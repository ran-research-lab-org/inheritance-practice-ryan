#include "Employee.h"
#include <string>

Employee::Employee(const std::string& name, int id, const std::string& type) {
    this->name = name;
    this->id = id;
    this->type = type;
}

/* IMPLEMENT GETTERS*/
std::string Employee::getType() const {
    return type;
}

std::string Employee::getName() const {
    return name;
}

int Employee::getID() const {
    return id;
}

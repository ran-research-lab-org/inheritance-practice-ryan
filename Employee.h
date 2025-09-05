// Parent Class Employee
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
// Attributes
protected:
    std::string name;
    int id;
    std::string type; // "Hourly" or "Salaried"

// Methods
public:
	// TODO: Constructor
    Employee();
    Employee(const std::string& name, int id, const std::string& type);
    virtual ~Employee() {}

    // Virtual function to calculate payment
    virtual double calculatePay() const = 0;

    // TODO: Getters
    std::string getType() const;
    std::string getName() const;
    int getID() const;
};

#endif


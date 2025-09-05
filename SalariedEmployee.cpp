#include "SalariedEmployee.h"
#include "Employee.h"

SalariedEmployee::SalariedEmployee(const std::string& name, int id, double yearlyPayment) : Employee(name, id, "Salaried") {
    this->yearlyPayment = yearlyPayment;
}
/*TODO: calculate Payment */
double SalariedEmployee::calculatePay() const {
    return yearlyPayment / 26;
}

/* IMPLEMENT GETTERS*/
double SalariedEmployee::getYearlyPayment() const {
    return yearlyPayment;
}

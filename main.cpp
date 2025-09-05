#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

using namespace std;

// Reads CSV: ID,Name,Type,PayPerHour,WorkedHours,YearlyPayment
void readFile(const string& filename, vector<HourlyEmployee>& hourlyEmployees, vector<SalariedEmployee>& salariedEmployees) {
    ifstream file(filename);
    string line;

    // Read file with employees information
    while (getline(file, line)) {
        stringstream ss(line);
        string name, type, token;
        int id;
        double payPerHour = 0, workedHours = 0, yearlyPayment = 0;

        getline(ss, token, ','); id = stoi(token);
        getline(ss, name, ',');
        getline(ss, type, ',');
        getline(ss, token, ','); payPerHour = stod(token);
        getline(ss, token, ','); workedHours = stod(token);
        getline(ss, token, ','); yearlyPayment = stod(token);

        if (type == "Hourly") {
            hourlyEmployees.emplace_back(name, id, payPerHour, workedHours);
        } else if (type == "Salaried") {
            salariedEmployees.emplace_back(name, id, yearlyPayment);
        }
    }
}

void displayEmpInfo(const vector<HourlyEmployee> hourlyEmployees, const vector<SalariedEmployee> salariedEmployees) {
    cout << "Hourly Employees:\n";
    for (auto &e : hourlyEmployees) {
        cout << "ID: " << to_string(e.getID()) << " | ";
        cout << "Name: " << e.getName() << " | ";
        cout << "Pay this period: $" << e.calculatePay() << "\n";
    }

    cout << "\nSalaried Employees:\n";
    for (auto &e : salariedEmployees) {
        cout << "ID: " << to_string(e.getID()) << " | ";
        cout << "Name: " << e.getName() << " | ";
        cout << "Pay this period: $" << e.calculatePay() << "\n";
    }
}

int main() {
    
    /* TODO: Define two vectors: HourlyEmployee and SalariedEmployee */
    vector<HourlyEmployee> hourEmp;
    vector<SalariedEmployee> salarEmp;

    // TODO: Add vectors to readFile call, hourly first
    readFile("employee_info.csv", hourEmp,salarEmp);
    double result = 0;

    // TODO: Print the results
    // Remember that you can use the range based for loop
    // Display the results of each type of employee
    displayEmpInfo(hourEmp, salarEmp);
    return 0;
}

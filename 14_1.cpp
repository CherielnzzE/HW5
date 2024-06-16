#include <iostream>
#include<cstdlib>
#include <string>
using namespace std;

class SalariedEmployee {
protected:
    string name;
    string ssn;
    double salary;
public:
    void setName(const string& nm) {
        name = nm;
    }
    void setSSN(const string& s) {
        ssn = s;
    }
    void setSalary(double sal) {
        salary = sal;
    }
    string getName() const {
        return name;
    }
    string getSSN() const {
        return ssn;
    }
    double getSalary() const {
        return salary;
    }
    virtual void printCheck() const {
        cout << "Pay to the order of " << name << " $" << salary << endl;
    }
};

class Administrator : public SalariedEmployee {
protected:
    string title;
    string areaOfResponsibility;
    string supervisor;

public:
    Administrator(const string& nm, const string& s, double sal,
        const string& t, const string& area, const string& sup) {
        name = nm;
        ssn = s;
        salary = sal;
        title = t;
        areaOfResponsibility = area;
        supervisor = sup;
    }

    void setTitle(const string& t) {
        title = t;
    }

    void setAreaOfResponsibility(const string& area) {
        areaOfResponsibility = area;
    }

    void setSupervisor(const string& sup) {
        supervisor = sup;
    }

    void print() const {
        cout << "Name: " << name << endl;
        cout << "SSN: " << ssn << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Title: " << title << endl;
        cout << "Area of Responsibility: " << areaOfResponsibility << endl;
        cout << "Supervisor: " << supervisor << endl;
    }

    // Overriding printCheck() to add specific notation
    virtual void printCheck() const override {
        cout << "..........................................\n";
        cout << "Pay to the order of " << name << " $" << salary << endl;
        cout << "..........................................\n";
    }
};

int main() {
    Administrator admin("John Doe", "123-45-6789", 80000.0, "Director", "Production", "Jane Smith");

    // Outputting admin's details
    admin.print();

    // Printing a check for admin
    admin.printCheck();

    return 0;
}
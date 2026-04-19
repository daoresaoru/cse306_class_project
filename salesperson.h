#ifndef SALESPERSON_H
#define SALESPERSON_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Employee {
    private:
        double gross = 0;
        double subCommission = 0;
        int sales = 0;
        string name;
        int employeeID, bossID;

    public:
        Employee() {
            name = "";
            employeeID = 0;
            bossID = 0;
            
        }
        Employee(string n, int i, int j) {
            name = n;
            employeeID = i;
            bossID = j;
            
        }
        virtual double getCommission() = 0;
        
        void addIncome(double price) {
            gross += price;
        }

        void addSales(int quantity) {
            sales += quantity;
        }

        void addSubCommission(double amount) {
            subCommission += amount;
        }

        string getName(){
            return name;
        }

        int geteID(){
            return employeeID;
        }

        int getbID(){
            return bossID;
        }

        double getIncome() {
            return gross;
        }

        double getSales() {
            return sales;
        }

        double getSubCommission() {
            return subCommission;
        }
};

class Sales : public Employee {

    public:
        Sales(string name, int employeeID, int bossID):Employee(name, employeeID, bossID) {
        
        
    }
    double getCommission() override {
        return getIncome() * 0.05;
    }

    
};

class SuperSales : public Employee{
    public:
        SuperSales(string name, int employeeID, int bossID):Employee(name, employeeID, bossID) {
        
    }
    double getCommission() override {
        return getIncome() * 0.065;
    }
    
};
class Supervisor : public SuperSales{
    public:
        Supervisor(string name, int employeeID, int bossID):SuperSales(name, employeeID, bossID) {
        
        
    }
    double getCommission() override {
        return getIncome() * 0.065 + getSubCommission();
    }

    
};
class Manager : public SuperSales {
    public:
        Manager(string name, int employeeID, int bossID):SuperSales(name, employeeID, bossID) {
        
        
    }
    double getCommission() override {
        return getIncome() * 0.065 + getSubCommission();
    }

    
};
#endif
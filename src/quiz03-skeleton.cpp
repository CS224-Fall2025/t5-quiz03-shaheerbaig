#include <iostream>
using namespace std;

class Employee{
    protected:
        static int employeeCount;
        string name;
        double salary;
    public:        
        Employee(string n, double s){
            employeeCount ++;
            name = n;
            salary = s;
        }
        
        virtual void displayInfo(){
            cout << "Name: " << name << ", Salary: " << salary;            
        }
        // static void showTotalEmployees(){
        //     cout << employeeCount;
        // }
        // virtual ~Employee();
};

class Staff : public Employee {
    private:
    string department;
    public:
    Staff (string n, double s, string d = "") : Employee(n, s) , department(d){
        Employee().employeeCount = 0;
    };                

    virtual void displayInfo(){
        cout << "Name: " << name << " (Staff), Salary: " << salary << endl;            
    }

};
class Faculty : public Employee {
    private:
    string department;
    public:
    Faculty (string n, double s, string d = "") : Employee(n, s) , department(d){};                
    
    virtual void displayInfo(){
        cout << "Name: " << name << " (Faculty), Salary: " << salary << endl;            
    }
};

int main() {
    int n;
    cin >> n;

    Employee* emps[n];
    for (int i = 0; i < n; i++){
        string type, nam;
        double sal;
        cin >> type >> nam >> sal;

        Employee* emp;

        if(type == "Staff"){
            emp = new Staff(nam, sal);
        }
        else{
            emp = new Faculty(nam, sal);
        }

        emps[i] = emp;
    }

    for (int i = 0; i < n; i++){
        emps[i]->displayInfo();
    }

    // Employee.showTotalEmployees();
}
#include <iostream>
#include<string>
using namespace std;

struct Employee {
    int id;
    string name;
    double basicSalary;
    char grade;
    string department;
    double allowance;
    double netSalary;
    int tax;
};

Employee emp[100];
int countEmp = 0;

void addEmployee() {
    cout << "\nEnter Employee ID: ";
    cin >> emp[countEmp].id;
    cout << "Enter Name: ";
    cin >> emp[countEmp].name;
    cout << "Enter Basic Salary: ";
    cin >> emp[countEmp].basicSalary;
    cout << "Enter Grade: ";
    cin >> emp[countEmp].grade;
     cout << "Enter Allowance: ";
    cin >> emp[countEmp].allowance;

    cout << "Enter Department: ";
    cin >> emp[countEmp].department;

    double basic = emp[countEmp].basicSalary;
    
   int tax = basic * 0.05; 

    emp[countEmp].netSalary = basic + emp[countEmp].allowance - tax;

    countEmp++;
    cout << "\nEmployee Added Successfully !\n";
}

void displayEmployees() {
    if (countEmp == 0) {
        cout << "\nNo Records Found!\n";
        return;
    }

    cout << "\n---- Employee Records ----\n";
    for (int i = 0; i < countEmp; i++) {
        cout << "\nID: " << emp[i].id;
        cout << "\nName: " << emp[i].name;
        cout << "\nBasic Salary: " << emp[i].basicSalary;
        cout << "\nGrade: " << emp[i].grade;
        cout << "\nAllowance: " << emp[i].allowance;
        cout << "\nNet Salary: " << emp[i].netSalary;
        cout << "\nDepartment: " << emp[i].department;
         
        cout << "\n------------------------";
    }
}

void searchEmployee() {
    int id;
    cout << "\nEnter ID to Search: ";
    cin >> id;

    for (int i = 0; i < countEmp; i++) {
        if (emp[i].id == id) {
            cout << "\nRecord Found\n";
            cout << "ID: " << emp[i].id;
            cout << "\nName: " << emp[i].name;
            cout << "\nBasic Salary: " << emp[i].basicSalary;
            cout << "\nGrade: " << emp[i].grade;
            cout << "\nAllowance: " << emp[i].allowance;
            cout << "\nNet Salary: " << emp[i].netSalary;
            return;
        }
    }
    cout << "\nRecord Not Found\n";
}

void deleteEmployee() {
    int id;
    cout << "\nEnter ID to Delete: ";
    cin >> id;

    for (int i = 0; i < countEmp; i++) {
        if (emp[i].id == id) {
            for (int j = i; j < countEmp - 1; j++) {
                emp[j] = emp[j + 1];
            }
            countEmp--;
            cout << "\nRecord Deleted Successfully\n";
            return;
        }
    }
    cout << "\nRecord Not Found\n";
}

void updateEmployee() {
    int id;
    cout << "\nEnter ID to Update: ";
    cin >> id;

    for (int i = 0; i < countEmp; i++) {
        if (emp[i].id == id) {
            cout << "Enter New Basic Salary: ";
            cin >> emp[i].basicSalary;
            cout << "Enter New Grade: ";
            cin >> emp[i].grade;
            cout << "Enter New Department: ";
            cin >> emp[i].department;
            cout << "Enter New Allowance: ";
    cin >> emp[countEmp].allowance;
    

            double basic = emp[i].basicSalary;
            
            double tax = basic * 0.05;

            emp[i].netSalary = basic + emp[i].allowance - tax;

            cout << "\nRecord Updated !\n";
            return;
        }
    }
    cout << "\nRecord Not Found\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Salary Management System =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Update Employee\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: updateEmployee(); break;
            case 6: return 0;
            default: cout << "\nInvalid Choice\n";
        }
    }
}

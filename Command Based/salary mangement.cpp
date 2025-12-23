#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Employee {
    int id;
    string name;
    string fatherName;
    string cnic;
    string dateOfJoining;
    double basicSalary;
    char grade;
    string department;
    double allowance;
    double deduction;
    int overtimeHours;
    double overtimeRate;
    double overtimePay;
    double tax;
    double netSalary;
};

Employee emp[100];
int countEmp = 0;

void clearScreen() {
    system("cls");
}

void saveToFile() {
    ofstream file("employees.txt");
    for (int i = 0; i < countEmp; i++) {
        file << "ID: " << emp[i].id << endl;
        file << "Name: " << emp[i].name << endl;
        file << "Father Name: " << emp[i].fatherName << endl;
        file << "CNIC: " << emp[i].cnic << endl;
        file << "Date of Joining: " << emp[i].dateOfJoining << endl;
        file << "Basic Salary: " << emp[i].basicSalary << endl;
        file << "Grade: " << emp[i].grade << endl;
        file << "Allowance: " << emp[i].allowance << endl;
        file << "Deduction: " << emp[i].deduction << endl;
        file << "Overtime Hours: " << emp[i].overtimeHours << endl;
        file << "Overtime Rate: " << emp[i].overtimeRate << endl;
        file << "Overtime Pay: " << emp[i].overtimePay << endl;
        file << "Tax is 5% of basic salary: " << emp[i].tax << endl;
        file << "Net Salary: " << emp[i].netSalary << endl;
        file << "Department: " << emp[i].department << endl;
        file << "----------------------------" << endl;
    }
    file.close();
}

void loadFromFile() {
    ifstream file("employees.txt");
    if (!file) return;

    string label;

    while (file >> label >> emp[countEmp].id) {
        file >> label >> emp[countEmp].name;
        file >> label >> label >> emp[countEmp].fatherName;
        file >> label >> emp[countEmp].cnic;
        file >> label >> label >> label >> emp[countEmp].dateOfJoining;
        file >> label >> label >> emp[countEmp].basicSalary;
        file >> label >> emp[countEmp].grade;
        file >> label >> emp[countEmp].allowance;
        file >> label >> emp[countEmp].deduction;
        file >> label >> label >> emp[countEmp].overtimeHours;
        file >> label >> label >> emp[countEmp].overtimeRate;
        file >> label >> label >> emp[countEmp].overtimePay;
        file >> label >> emp[countEmp].tax;
        file >> label >> label >> emp[countEmp].netSalary;
        file >> label >> emp[countEmp].department;
        file >> label;
        countEmp++;
    }
    file.close();
}

void addEmployee() {
    clearScreen();

    cout << "\nEnter Employee ID: ";
    cin >> emp[countEmp].id;

    cout << "Enter Name: ";
    cin >> emp[countEmp].name;

    cout << "Enter Father Name: ";
    cin >> emp[countEmp].fatherName;

    cout << "Enter CNIC: ";
    cin >> emp[countEmp].cnic;

    cout << "Enter Date of Joining(dd-mm-yyyy): ";
    cin >> emp[countEmp].dateOfJoining;

    cout << "Enter Basic Salary: ";
    cin >> emp[countEmp].basicSalary;

    cout << "Enter Grade: ";
    cin >> emp[countEmp].grade;

    cout << "Enter Allowance: ";
    cin >> emp[countEmp].allowance;

    cout << "Enter Deduction: ";
    cin >> emp[countEmp].deduction;

    cout << "Enter Overtime Hours: ";
    cin >> emp[countEmp].overtimeHours;

    cout << "Enter Overtime Rate: ";
    cin >> emp[countEmp].overtimeRate;

    cout << "Enter Department: ";
    cin >> emp[countEmp].department;

    emp[countEmp].overtimePay = emp[countEmp].overtimeHours * emp[countEmp].overtimeRate;
    emp[countEmp].tax = emp[countEmp].basicSalary * 0.05;
    emp[countEmp].netSalary =
        emp[countEmp].basicSalary +
        emp[countEmp].allowance +
        emp[countEmp].overtimePay -
        emp[countEmp].tax -
        emp[countEmp].deduction;

    countEmp++;
    saveToFile();
    cout << "\nEmployee Added Successfully!\n";
}

void displayEmployees() {
    clearScreen();

    if (countEmp == 0) {
        cout << "\nNo Records Found!\n";
        return;
    }

    for (int i = 0; i < countEmp; i++) {
        cout << "\n------------------------";
        cout << "\nID: " << emp[i].id;
        cout << "\nName: " << emp[i].name;
        cout << "\nFather Name: " << emp[i].fatherName;
        cout << "\nCNIC: " << emp[i].cnic;
        cout << "\nDate of Joining: " << emp[i].dateOfJoining;
        cout << "\nBasic Salary: " << emp[i].basicSalary;
        cout << "\nGrade: " << emp[i].grade;
        cout << "\nAllowance: " << emp[i].allowance;
        cout << "\nDeduction: " << emp[i].deduction;
        cout << "\nOvertime Hours: " << emp[i].overtimeHours;
        cout << "\nOvertime Rate: " << emp[i].overtimeRate;
        cout << "\nOvertime Pay: " << emp[i].overtimePay;
        cout << "\nTax is 5% of basic salary:" << emp[i].tax;
        cout << "\nNet Salary: " << emp[i].netSalary;
        cout << "\nDepartment: " << emp[i].department;
        cout << "\n------------------------";
    }
}

void searchEmployee() {
    clearScreen();

    int id;
    cout << "\nEnter ID to Search: ";
    cin >> id;

    for (int i = 0; i < countEmp; i++) {
        if (emp[i].id == id) {
            cout << "\nRecord Found";
            cout << "\nID: " << emp[i].id;
            cout << "\nName: " << emp[i].name;
            cout << "\nFather Name: " << emp[i].fatherName;
            cout << "\nCNIC: " << emp[i].cnic;
            cout << "\nDate of Joining: " << emp[i].dateOfJoining;
            cout << "\nBasic Salary: " << emp[i].basicSalary;
            cout << "\nGrade: " << emp[i].grade;
            cout << "\nAllowance: " << emp[i].allowance;
            cout << "\nDeduction: " << emp[i].deduction;
            cout << "\nOvertime Hours: " << emp[i].overtimeHours;
            cout << "\nOvertime Rate: " << emp[i].overtimeRate;
            cout << "\nOvertime Pay: " << emp[i].overtimePay;
            cout << "\nTax is 5% of basic salary: " << emp[i].tax;
            cout << "\nNet Salary: " << emp[i].netSalary;
            cout << "\nDepartment: " << emp[i].department;
            return;
        }
    }
    cout << "\nRecord Not Found";
}

void deleteEmployee() {
    clearScreen();

    int id;
    cout << "\nEnter ID to Delete: ";
    cin >> id;

    for (int i = 0; i < countEmp; i++) {
        if (emp[i].id == id) {
            for (int j = i; j < countEmp - 1; j++) {
                emp[j] = emp[j + 1];
            }
            countEmp--;
            saveToFile();
            cout << "\nRecord Deleted Successfully";
            return;
        }
    }
    cout << "\nRecord Not Found";
}

void updateEmployee() {
    clearScreen();

    int id;
    cout << "\nEnter ID to Update: ";
    cin >> id;

    for (int i = 0; i < countEmp; i++) {
        if (emp[i].id == id) {
            cout << "Enter New Basic Salary: ";
            cin >> emp[i].basicSalary;

            cout << "Enter New Grade: ";
            cin >> emp[i].grade;

            cout << "Enter New Allowance: ";
            cin >> emp[i].allowance;

            cout << "Enter New Deduction: ";
            cin >> emp[i].deduction;

            cout << "Enter New Overtime Hours: ";
            cin >> emp[i].overtimeHours;

            cout << "Enter New Overtime Rate: ";
            cin >> emp[i].overtimeRate;

            cout << "Enter New Department: ";
            cin >> emp[i].department;

            emp[i].overtimePay = emp[i].overtimeHours * emp[i].overtimeRate;
            emp[i].tax = emp[i].basicSalary * 0.05;
            emp[i].netSalary =
                emp[i].basicSalary +
                emp[i].allowance +
                emp[i].overtimePay -
                emp[i].tax -
                emp[i].deduction;

            saveToFile();
            cout << "\nRecord Updated Successfully";
            return;
        }
    }
    cout << "\nRecord Not Found";
}

int main() {
    loadFromFile();

    int choice;
    while (true) {
        cout << "\n===== Salary Management System =====";
        cout << "\n1. Add Employee";
        cout << "\n2. Display All Employees";
        cout << "\n3. Search Employee";
        cout << "\n4. Delete Employee";
        cout << "\n5. Update Employee";
        cout << "\n6. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: updateEmployee(); break;
            case 6: return 0;
            default: cout << "\nInvalid Choice";
        }
    }
}


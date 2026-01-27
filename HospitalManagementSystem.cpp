#include <iostream>
#include <list>
#include <string>
using namespace std;

class Hospital
{
public:
    struct Patient
    {
        int id;
        string name;
        int age;
    };

    list<Patient> patients;

    bool isDuplicateID(int id)               
    {
        for (auto p : patients)
        {
            if (p.id == id)
                return true;     
        }
        return false;
    }

    void insertPatient(int id, string name, int age)
    {
        if (id <= 0 || name.empty() || age <= 0)              //Validation
        {
            cout << "Invalid ID or Name or Age\n";
            return;
        }

        if (isDuplicateID(id))                                      //Validation
        {
            cout << "Duplicate Patient ID not allowed\n";
            return;
        }

        Patient p;
        p.id = id;
        p.name = name;
        p.age = age;

        patients.push_back(p);
        cout << "Patient admitted\n";
    }

    void deletePatient(int id)
    {
        if (patients.empty())                                           
        {
            cout << "No records available\n";
            return;
        }

        for (auto it = patients.begin(); it != patients.end(); it++)
        {
            if (it->id == id)
            {
                patients.erase(it);
                cout << "Patient discharged\n";
                return;
            }
        }

        cout << "Patient not found\n";
    }

    void searchPatient(int id)
    {
        if (patients.empty())
        {
            cout << "No records available\n";
            return;
        }

        for (auto p : patients)
        {
            if (p.id == id)
            {
                cout << "Patient Found\n";
                cout << "ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Age: " << p.age << endl;
                return;
            }
        }

        cout << "Patient not found\n";
    }

    void countPatients()
    {
        cout << "Total Patients: " << patients.size() << endl;
    }

    void displayPatients()
    {
        if (patients.empty())
        {
            cout << "No records available\n";
            return;
        }

        for (auto p : patients)
        {
            cout << "ID: " << p.id
                 << " Name: " << p.name
                 << " Age: " << p.age << endl;
        }
    }
};
int main()
{
    Hospital h;
    int choice, id, age;
    string name;
    do{
        cout << "\n1. Admit Patient";
        cout << "\n2. Discharge Patient";
        cout << "\n3. Search Patient";
        cout << "\n4. Count Patients";
        cout << "\n5. Display Patients";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            h.insertPatient(id, name, age);
            break;

        case 2:
            cout << "Enter ID to delete: ";
            cin >> id;
            h.deletePatient(id);
            break;

        case 3:
            cout << "Enter ID to search: ";
            cin >> id;
            h.searchPatient(id);
            break;

        case 4:
            h.countPatients();
            break;

        case 5:
            h.displayPatients();
            break;

        case 6:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
     while (choice != 6);
    return 0;
}

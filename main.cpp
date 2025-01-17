#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Structure to hold student information
struct Student {
    int id;
    string name;
    vector<double> grades;
};

// Class to manage student records
class StudentGradeSystem {
private:
    vector<Student> students;

    double calculateAverage(const vector<double>& grades) {
        if (grades.empty()) return 0.0;
        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

public:
    // Add a student to the system
    void addStudent(int id, const string& name) {
        if (find_if(students.begin(), students.end(), [id](const Student& s) { return s.id == id; }) != students.end()) {
            cout << "Error: A student with ID " << id << " already exists.\n";
            return;
        }
        students.push_back({id, name, {}});
        cout << "Student added successfully.\n";
    }

    // Add multiple students to the system
    void addMultipleStudents() {
        int count;
        cout << "How many students do you want to add? ";
        cin >> count;
        cin.ignore(); // Ignore any leftover newline character

        for (int i = 0; i < count; ++i) {
            int id;
            string name;
            cout << "Enter details for student " << i + 1 << ":\n";
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            addStudent(id, name);
        }
    }

    // Remove a student from the system by ID
    void removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student removed successfully.\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    // Add grades to a student
    void addGrades(int id, const vector<double>& grades) {
        for (auto& student : students) {
            if (student.id == id) {
                student.grades.insert(student.grades.end(), grades.begin(), grades.end());
                cout << "Grades added successfully.\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    // Display all students with their average grades
    void displayAllStudents() {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(15) << "Average Grade\n";
        cout << "--------------------------------------------\n";
        for (const auto& student : students) {
            double avg = calculateAverage(student.grades);
            cout << setw(5) << student.id
                 << setw(20) << student.name
                 << setw(15) << fixed << setprecision(2) << avg << "\n";
        }
    }

    // Search for a student by ID or Name
    void searchStudent() {
        cout << "Search by (1) ID or (2) Name? ";
        int option;
        cin >> option;
        cin.ignore();

        if (option == 1) {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            for (const auto& student : students) {
                if (student.id == id) {
                    displayStudentDetails(student);
                    return;
                }
            }
            cout << "Student with ID " << id << " not found.\n";
        } else if (option == 2) {
            string name;
            cout << "Enter student name: ";
            getline(cin, name);
            for (const auto& student : students) {
                if (student.name == name) {
                    displayStudentDetails(student);
                    return;
                }
            }
            cout << "Student with name \"" << name << "\" not found.\n";
        } else {
            cout << "Invalid option.\n";
        }
    }

    // Display detailed student information
    void displayStudentDetails(const Student& student) {
        cout << "\n--- Student Details ---\n";
        cout << "ID: " << student.id << "\n";
        cout << "Name: " << student.name << "\n";
        cout << "Grades: ";
        if (student.grades.empty()) {
            cout << "No grades available.\n";
        } else {
            for (double grade : student.grades) {
                cout << grade << " ";
            }
            cout << "\nAverage Grade: " << fixed << setprecision(2) << calculateAverage(student.grades) << "\n";
        }
        cout << "-----------------------\n";
    }
};

int main() {
    StudentGradeSystem system;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Add Multiple Students\n";
        cout << "3. Remove Student\n";
        cout << "4. Add Grades\n";
        cout << "5. Display All Students\n";
        cout << "6. Search for Student\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            cout << "Enter student ID: ";
            cin >> id;
            cin.ignore(); // Ignore newline character
            cout << "Enter student name: ";
            getline(cin, name);
            system.addStudent(id, name);
            break;
        }
        case 2:
            system.addMultipleStudents();
            break;
        case 3: {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            system.removeStudent(id);
            break;
        }
        case 4: {
            int id, n;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter number of grades: ";
            cin >> n;
            vector<double> grades(n);
            cout << "Enter grades: ";
            for (int i = 0; i < n; i++) {
                cin >> grades[i];
            }
            system.addGrades(id, grades);
            break;
        }
        case 5:
            system.displayAllStudents();
            break;
        case 6:
            system.searchStudent();
            break;
        case 7:
            cout << "Thank you for using the Student Management System. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

//structure to hold student information
struct Student {
    int id;
    string name;
    vector<double> grades;
};

//Class to manage student records
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
        }

    public:
    //Add a student to the system
    void addStudent( int id, const string& name) {
        students.push_back({id, name, ()});
        cout << "Student added successfully.\n";
    }

    // remove a student from the system by ID
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

    // Add a grade to a student
    void addGrades(int id, const vector<double>& grades) {
        for (auto& student : students) {
            if (student.id == id) {
                student.grades.insert(student.grades.end(), grades.end());
                cout << "Grades added successfully.\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    // Display all students with their average grades
    void displayAllStudents() {
        if (students.empty()) {
            cout << "No Students Found.\n";
            return;
        }
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Average Grade\n";
        cout << "--------------------------------------------\n";
        for (const auto& student : students)
    }
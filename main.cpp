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
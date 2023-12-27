#include <iostream>
using namespace std;

void getGrades(int** &grades, int number_of_students, double* &average) {
    int number_of_tests;
    for (int i = 0; i < number_of_students; ++i) {
        cout << "Enter number of tests for student " << (i + 1) << ": ";
        cin >> number_of_tests;

        grades[i] = new int[number_of_tests];
        double sum = 0;
        for (int j = 0; j < number_of_tests; ++j) {
            cout << "Enter score for test " << (j + 1) << ": ";
            cin >> grades[i][j];
            sum += grades[i][j];
        }
        average[i] = sum / number_of_tests;
    }
}

void dispAverage(double* average, int number_of_students) {
    for (int i = 0; i < number_of_students; ++i) {
        cout << "Average for student " << (i + 1) << ": " << average[i] << endl;
    }
}

int main() {
    int number_of_students;
    int** grades;
    double* average;

    cout << "How many students? ";
    cin >> number_of_students;

    grades = new int*[number_of_students];
    average = new double[number_of_students];

    getGrades(grades, number_of_students, average);
    dispAverage(average, number_of_students);

    for (int i = 0; i < number_of_students; ++i) {
        delete[] grades[i];
    }
    delete[] grades;
    delete[] average;

    return 0;
}

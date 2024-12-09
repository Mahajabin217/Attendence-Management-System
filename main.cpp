#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int Roll_Number;
    string Name;
    bool is_present;
};

void records(vector<Student> &students) {
    cout << "Roll No\t\tName\t\tAttendance\n";
    cout << "______________________________________________\n";
    for (const auto &student : students) {
        cout << student.Roll_Number << "\t\t" << student.Name << "\t\t"
            << (student.is_present ? "Present" : "Absent") << "\n";
    }
}

int find_student(vector<Student> &students, int Roll_Number) {
    int left = 0, right = students.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].Roll_Number == Roll_Number) {
            return mid;
        } else if (students[mid].Roll_Number < Roll_Number) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void update_attendence(vector<Student> &students, int Roll_Number) {
    int index = find_student(students, Roll_Number);
    if (index != -1) {
        students[index].is_present = true;
        cout << "Attendance marked as Present for Roll No " << Roll_Number << "\n";
    } else {
        cout << "Student with Roll No " << Roll_Number << " is not found\n";
    }
}

int main() {
    vector<Student> students = {
        {101, "Ritu", false},
        {102, "Rima", false},
        {103, "Riya", false},
        {104, "Maya", false},
        {105, "Sima", false}
    };

    int choice;
    while (true) {
        cout << "\nAttendance Management System\n";
        cout << "1. Display Records\n";
        cout << "2. Update Attendance\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            records(students);
        } else if (choice == 2) {
            int roll;
            cout << "Enter Roll Number: ";
            cin >> roll;
            update_attendence(students, roll);
        } else if (choice == 3) {
            cout << "Thank You\n";
            break;
        } else {
            cout << "Invalid choice, try again\n";
        }
    }

    return 0;
}

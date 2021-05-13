#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    Student(const string &surname, const std::string &name, int course, const string &group,
            const string &studentCard) : surname(surname), name(name), course(course), group(group),
                                              studentCard(studentCard) {}

    Student() {}

    void print() const {
        cout << surname << " " << name << " " << course << " " << group << " " << studentCard << endl;
    }

    string surname;
    string name;
    int course;
    string group;
    string studentCard;
};

void swap(Student &xp, Student &yp)
{
    Student temp = xp;
    xp = yp;
    yp = temp;
}

void sortByCourse(vector<Student> &arr) {
    int i, j;
    int n = arr.size();
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].course > arr[j + 1].course)
                swap(arr[j], arr[j + 1]);
}

void sortByGroup(vector<Student> &arr) {
    int i, j;
    int n = arr.size();
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].group > arr[j + 1].group)
                swap(arr[j], arr[j + 1]);
}

Student studentWithLongestSurname(vector<Student> arr){
    Student result;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].surname.length() > result.surname.length()){
            result = arr[i];
        }
    }
    return result;
}

int main() {

    vector<Student> students;
    ifstream file;
    file.open("students.txt");
    while (!file.eof()) {
        string surname;
        string name;
        int course;
        string group;
        string studentCard;
        file >> surname >> name >> course >> group >> studentCard;
        students.push_back(Student(surname, name, course, group, studentCard));
    }

    for (int i = 0; i < students.size(); i++) {
        students[i].print();
    }
    cout << "----------------------" << endl;

    sortByCourse(students);
    for (int i = 0; i < students.size(); i++) {
        students[i].print();
    }
    cout << "----------------------" << endl;

    sortByGroup(students);
    for (int i = 0; i < students.size(); i++) {
        students[i].print();
    }
    cout << "----------------------" << endl;

    Student longest = studentWithLongestSurname(students);
    longest.print();

    return 0;
}

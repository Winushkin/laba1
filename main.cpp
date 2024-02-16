#include "iostream"
#include "string"
#include <fstream>
using namespace std;


struct Student{
    string fullName;
    string gender;
    int group;
    int id;
    signed char exams[3] = {};
    signed char tests[5] = {};
    float avarageGrade;
};


//main funcs;
void clearStream() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void showMenu(){
    cout << "1. add new student";
    cout << "2. edit student info";
    cout << "3. show students";
    cout << "4. show students in group";
    cout << "5. show top 3 student";
    cout << "6. show students amount by gender";
    cout << "7. show students's grades info";
    cout << "8. show Ks' students";
}


void nextLine(int amount = 1){
    for (int repeat = 0; repeat < amount; repeat++){
        cout << "\n";
    }
}

// student funcs;

float avg(int exams[3], int tests[5]){
    float sum = 0;
    for (int i = 0; i < 3; i++){
        sum += exams[i];
    }
    for (int i = 0; i < 5; i++){
        sum += tests[i];
    }
    return sum / 8.0;
}


Student addStudent(string fullName, string gender, int group, int id, int Exams[3], int tests[5]){
    Student student;
    student.fullName = fullName;
    student.gender = gender;
    student.group = group;
    student.id = id;

 return student;
}


void addStudent(){
    ifstream in("students.txt");
    string line;
    if ( in.is_open() ){
        while( getline(in, line) ) {
            cout << line;
        }
    }
    in.close();

}


int main(){
    Student student;
    string fullName;
    string gender;
    int group;
    int id;
    string enterExams;
    int Exams[3] = {};
    string enterTests;
    int tests[5] = {};
    float avarageGrade;

    for ( int problem = 0; problem < 100; problem ++ ){
        showMenu();
        cout << "choose problem";

        switch (problem) {

            case 1:
                cout << "fullName: "; cin >> fullName; nextLine();
                cout << "gender: "; cin >> gender; nextLine();
                cout << "group: "; cin >> group; nextLine();
                cout << "id: "; cin >> id; nextLine();
                cout << "enter exam's grades by Space:"; cin >> enterExams;
                cout << "enter test's grades by Space:"; cin >> enterTests;


                student.fullName = fullName;
                student.gender = gender;
                student.group = group;
                student.id = id;
                for (int i = 0; i < 3; i++){
                    student.exams[i] = (signed char)enterExams[2 * i];
                }

                for (int i = 0; i < 5; i++){
                    student.tests[i] = (signed char)enterTests[2 * i];
                }
                student.avarageGrade = avg(student.exams, student.tests);
        }

    }
    addStudent();
}
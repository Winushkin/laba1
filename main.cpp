#include "iostream"
#include "string"
#include <fstream>
using namespace std;

const signed char examsAmount = 3;
const signed char testsAmount = 5;


//system("cls");

struct Student{
    string fullName;
    string gender;
    int group;
    int id = 0;
    int exams[3];
    int tests[5];
    float averageGrade;
};


//main funcs;
void clearStream() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void nextLine(int amount = 1) {
    for (int repeat = 0; repeat < amount; repeat++) {
        cout << "\n";
    }
}


void showMenu(){
    cout << "1. add new student"; nextLine();
    cout << "2. edit student info"; nextLine();
    cout << "3. show students"; nextLine();
    cout << "4. show students in group"; nextLine();
    cout << "5. show top 3 student"; nextLine();
    cout << "6. show students amount by gender"; nextLine();
    cout << "7. show students's grades info"; nextLine();
    cout << "8. show Ks' students"; nextLine();
}

// student funcs;

float avg( int *exams, int *tests){
    float sum = 0;
    for (int i = 0; i < 3; i++){
        sum += float(*(exams + i));
    }
    for (int i = 0; i < 5; i++){
        sum += float(*(tests + i));
    }
    return (sum / 8.0);
}

Student findStudent(int group, int id, int studentsAmount, Student *students){
    for (int i = 0; i < studentsAmount; i++ ){
        if ( (( students + i )->group == group) &&  (( students + i )->id == id) ) {
            return *( students + i );
        }
    }
    return Student();
}


void showStudentInfo(Student student){
    cout << student.fullName; nextLine();
    cout << student.group; nextLine();
    cout << student.id; nextLine();
    cout << student.gender; nextLine();
    for ( int i = 0; i < examsAmount; i ++ ){
        cout << student.exams[i] << " ";
    }
    nextLine();
    for ( int i = 0; i < testsAmount; i ++ ){
        cout << student.tests[i] << " ";
    }
    nextLine();
    cout << student.averageGrade;
    nextLine();
}


void editStudent(int group, int id){



}


void addStudent(Student student){


}


void showStudentsByGroup(int groupNum, int studentsAmount, Student *students, Student *group){
    int index = 0;
    for ( int i = 0; i < studentsAmount; i++ ){

       if( ((students + i)->group) == groupNum ){
           *(group + index) = *(students + i);
           index++;
       }

    }
}



void addStudent(){
    ifstream in("database.txt");
    string line;
    if ( in.is_open() ){
        while( getline(in, line) ) {
            cout << line;
        }
    }
    in.close();

}


int main(){
    int problem;
    int groupNum, id;
    int studentsAmount;
    Student students[60] = {};
    Student group[30];
    Student student;


    for ( int repeats = 0; repeats < 100; repeats++ ){
        nextLine();
        showMenu();
        cout << "choose problem: "; cin >> problem; nextLine();

        switch (problem) {

            case 1:
                cout << "fullName: "; cin >> student.fullName; clearStream();
                cout << "gender: "; cin >> student.gender; clearStream();
                cout << "group: "; cin >> student.group; clearStream();
                cout << "id: "; cin >> student.id; clearStream();
                cout << "enter exam's grades by Space: ";
                for (int i = 0; i < examsAmount; i++) cin >> student.exams[i];
                clearStream();
                cout << "enter test's grades by Space: ";
                for (int i = 0; i < testsAmount; i++) cin >> student.tests[i];
                clearStream();
                student.averageGrade = avg(student.exams, student.tests);



            case 2:
                break;

            case 3:
                cout << "find student:"; nextLine();
                cout << "group: "; cin >> groupNum;
                cout << "id: "; cin >> id;
                student = findStudent(groupNum, id, studentsAmount, students);
                if ( student.fullName != "" ){
                    showStudentInfo(student);
                }else{
                    cout << "Студент не найден";
                }


                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                students[0] = Student("kirill", "m", 3372, 3);
                break;

            default:
                cout << "pu-pu-pu";
        }
    }
//    addStudent();
}
#include "iostream"
#include "string"
#include <fstream>
using namespace std;


const signed char examsAmount = 3;
const signed char testsAmount = 5;
int studentsAmount = 0;


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

void addStudentToArray(Student student, Student *students);
int countStudents(Student *students);



int countStudents(Student *students){
    studentsAmount = 0;
    for (int i = 0; i < 60; i++){
        if (!(students + i)->fullName.empty()){
            studentsAmount ++;
        }
    }
    return studentsAmount;
}


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


Student findStudent(int group, int id, Student *students){
    studentsAmount = countStudents(students);
    for (int i = 0; i < studentsAmount; i++ ){
        if ( (( students + i )->group == group) &&  (( students + i )->id == id) ) {
            return *( students + i );
        }
    }
    return Student();
}


void showStudentInfo(Student student){
    cout << "fullname: " << student.fullName; nextLine();
    cout << "group: " << student.group; nextLine();
    cout << "id: " << student.id; nextLine();
    cout << "gender: " << student.gender; nextLine();
    cout << "Exams: ";
    for ( int i = 0; i < examsAmount; i ++ ){
        cout << student.exams[i] << " ";
    }
    nextLine();
    cout << "tests: ";
    for ( int i = 0; i < testsAmount; i ++ ){
        cout << student.tests[i] << " ";
    }
    nextLine();
    cout << "avg Grade: " << student.averageGrade;
    nextLine();
}


void editStudent(int group, int id){



}


void addStudents2File(Student student){



}



void readFile(Student students[]){
    Student student;
    int studentsCounter = 0;
    ifstream fin("/Users/kirillbelaev/CLionProjects/laba1Struct/db.txt");
    if ( !fin.is_open() ){
        cout << "file's not open";
    }
    else{
        while (fin.peek() != EOF){
            getline(fin, student.fullName);
            getline(fin, student.gender);
            fin >> student.group;
            fin >> student.id;

            for (int i = 0; i < 3; i++) {
                fin >> student.exams[i];
            }
            for (int i = 0; i < 5; i++) {
                fin >> student.tests[i];
            }
            fin.get();
            student.averageGrade = avg(student.exams, student.tests);
            addStudentToArray(student, students);
        }
    }
    fin.close();


}

int showStudentsByGroup(int groupNum, Student *students, Student *group){
    studentsAmount = countStudents(students);
    int index = 0;
    for ( int i = 0; i < studentsAmount; i++ ){
       if( ((students + i)->group) == groupNum ){
           *(group + index) = *(students + i);
           index++;
       }
    }
    return index;
}


void showStudentsByID(int id, Student *students){

    for ( int i = 0 ; i < countStudents(students); i++ ) {
        if ((students + i)->id == id) {
            showStudentInfo(*(students + i));
        }
    }
}


void sortStudentsByGrades(Student *students){
    studentsAmount = countStudents(students);
    for (int i = 0; i < studentsAmount / 2; i++){
        for ( int j = i; j < studentsAmount - i - 1; j++ ){
            if ( (students + j)->averageGrade < (students + j + 1)->averageGrade){
                swap(*(students + j), *(students + j + 1) );
            }
        }
        for ( int j = studentsAmount - 2 - i; j > i + 1; j-- ){
            if ( (students + j)->averageGrade > (students + j + 1)->averageGrade){
                swap(*(students + j), *(students + j - 1) );
            }
        }
    }
}


void addStudentToArray(Student student, Student students[]){
   students[countStudents(students)] = student;
}


//----------------------------------------------------------------------------------------------------------------------

int main(){
    int index;
    int problem;
    int groupNum, id;
    Student students[60] = {};
    Student group[30];
    Student student;

    readFile(students);


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

                addStudentToArray(student, students);



            case 2:
                break;

            case 3:
                cout << "find student:"; nextLine();
                cout << "group: "; cin >> groupNum;
                cout << "id: "; cin >> id;
                student = findStudent(groupNum, id, students);
                if ( student.fullName != "" ){
                    nextLine();
                    showStudentInfo(student);
                }else {
                    cout << "Студент не найден";
                }
                break;

            case 4:
                cout << "find students in group: "; cin >> groupNum;
                index = showStudentsByGroup(groupNum, students, group);
                if ( !index ){
                    cout << "no such group";
                }else{
                    for ( int i = 0; i < index; i++ ){
                        showStudentInfo(group[i]);
                    }
                }
                break;

            case 5:
                sortStudentsByGrades(students);
                for ( int i = 0; i < 3; i++ ){
                    showStudentInfo(students[i]);
                    nextLine();

                }
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:

                break;

            case 9:
                break;

            default:
                for ( int i = 0; i < countStudents(students); i++ ){
                    showStudentInfo(*(students + i));
                    nextLine();
                }
        }
    }
//    addStudent();
}
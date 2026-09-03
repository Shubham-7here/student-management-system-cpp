#include <iostream>
#include <string>
#include  <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Student{
    int rollno,age,marks;
    string name,course;


};

void saveStudents(vector<Student>& students)
{
    ofstream file("students.txt");

    for(int i = 0; i < students.size(); i++)
    {
        file << students[i].rollno << endl;
        file << students[i].name << endl;
        file << students[i].age << endl;
        file << students[i].course << endl;
        file << students[i].marks << endl;
    }

    file.close();
}
void loadstudent(vector <Student>&students){
    ifstream file("students.txt");
    if(!file)
      return;

    Student s;
    while(file >> s.rollno){
        file.ignore();
        getline(file,s.name);

        file >> s.age;
        file.ignore();

        getline(file,s.course);

        file >> s.marks;

        students.push_back(s);
    }
    file.close();

}
int main(){
    int choice = 0;
    vector<Student> students;
    loadstudent(students); 
    Student s;

    cout << "=====Student Management System=====\n";


    cout << "1. Add Students \n";
    cout << "2. Display Students \n";
    cout << "3. Search Students \n";
    cout << "4 Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit \n";

     

    while(choice != 6){
        cout << "Enter your  choice\n";
        cin >> choice;


        switch(choice)
        {
            case 1:
            {
                cout  << "Enter Roll no:\n";
                cin >> s.rollno;
                bool exists = false;
                for(int i =0;i<students.size();i++){
                    if(students[i].rollno == s.rollno){
                        exists = true;
                        break;
                    }
                     
                }
                if(exists){
                    cout << "Roll number already exists!\n";
                }
                else{
                    cout  << "Enter Name:\n";
                    cin.ignore();
         
                    getline(cin,s.name);
                    cout  << "Enter age:\n";
                    cin >> s.age;
                    while(s.age <=0 || s.age >100){
                        cout << "Invalid age! Enter valid age :";
                        cin >> s.age;

                    }
                         
                    cout  << "Enter Course:\n";
                    cin.ignore();
                    getline(cin,s.course);
                    cout  << "Enter Marks:\n";
                    cin >> s.marks;
                    while(s.marks < 0 || s.marks >100){
                        cout << "Invalid marks! Enter marks between 0 and 100 :";
                        cin >> s.marks;
                    }
                         

                    students.push_back(s);

                    cout  << "Student added successfully\n";
                     
                    saveStudents(students);
         
                        
                }

            }
                 
                


         
                break;
            case 2:
                cout << "=====Student Details=====\n";

                if(students.empty()){
                    cout << "No students  found" << endl;
                }else{
                    for(int i = 0;i<students.size();i++){
                        cout <<  "Roll no = " << students[i].rollno << endl;
                        cout <<  "Name  = " << students[i].name << endl;
                        cout <<  "age  = " << students[i].age << endl;
                        cout <<  "Course = " << students[i].course << endl;
                        cout <<  "Marks = " << students[i].marks << endl;
          

                    }

                }
                break;
            case 3:
            {

            
                int  searchRoll;
                bool found = false;
                cout << "Enter roll no to search :";
                cin >> searchRoll;
                 
                for(int i=0;i<students.size();i++){
                    if(students[i].rollno ==  searchRoll){
                        cout << "\n=========STUDENT DEATAILS=========\n";

                        cout <<  "Roll no = " << students[i].rollno << endl;
                        cout <<  "Name  = " << students[i].name << endl;
                        cout <<  "age  = " << students[i].age << endl;
                        cout <<  "Course = " << students[i].course << endl;
                        cout <<  "Marks = " << students[i].marks << endl;
                        found = true;
                        break;
          
                        

                    } 

                }
                if(!found){
                    cout << "Student not found\n";
                }
                
                break;
            }
            case 4:
            {

            
            
                int updateRoll;
                bool found = false;

                cout << "Enter roll no to update: ";
                cin >> updateRoll;

                for(int i = 0; i < students.size(); i++)
                {
                if(students[i].rollno == updateRoll)
                {
                cin.ignore();

                cout << "Enter new name: ";
                getline(cin, students[i].name);

                cout << "Enter new age: ";
                cin >> students[i].age;
                while(students[i].age <=0 || students[i].age >100){
                    cout << "Invalid age! Enter valid age :";
                    cin >> students[i].age;
                             
                }
                        

                cin.ignore();

                cout << "Enter new course: ";
                getline(cin, students[i].course);

                cout << "Enter new marks: ";
                cin >> students[i].marks;
                while( students[i].marks < 0 || students[i].marks >100){
                    cout << "Invalid marks! Enter marks between 0 and 100 :";
                    cin >> students[i].marks;
                             
                }

                found = true;

                cout << "Student updated successfully!\n";
                saveStudents(students);

                break;
                }

            }
            if(!found)
            {
                cout << "Student not found!\n";
            }

              break;
            }
                 
            case 5:{
                int deleteRoll;
                bool found = false;
                cout << "Enter roll no to delete :";
                cin >> deleteRoll;
                for(int i = 0; i < students.size(); i++){
                    if(students[i].rollno == deleteRoll){
                        students.erase(students.begin() + i);
                        found = true;
                        cout << "Student deleted successfully!\n";

                         
                        saveStudents(students);
                        break;
                    }
                }
                if(!found){
                    cout << "Student not found\n";
                }




                break;
            }
                 
                
            case 6:
                cout <<"Thank you for using Student management system\n";
                break;
    
    
    
            default:
                cout <<"Invalid Choice!Please try again\n";
                break;
    }

}
     
    return 0; 
     
}
     





    
     



#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(char* nname, int nid, float ngpa){
  name = nname;
  id = nid;
  gpa = ngpa;
}
Student::~Student(){

}
int Student::getID(){
  return id;
}
float Student::getGPA(){
  return gpa;
}
char* Student::getName(){
  return name;
}
void Student::printS(){
  cout<<"Name: "<<name<<endl;
  cout<<"GPA: " <<gpa<<endl;
  cout<<"ID: " <<id<<endl;
}

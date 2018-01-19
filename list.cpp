/*
Student List allows a user to input and keep track of student information
Mihira Sogal
10/17/2017
Modified on 12/5/2017 to implement a Linked List for Linked List Part 1
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;
//this struct is used to store name ,gpa, and id for all students


void addStudent(Student* s, Node* &start);
void print(Node* start);
void deleteNode(Node* &start, int id);

Node* head; 

int main(){
  bool inuse = true;
  while(inuse){
    //get input on what the user wants to do
    char action[20];
    cout<<"Type in what you want to do"<<endl;
    cin.get(action, 20);
    cin.ignore(80, '\n');
    //if user wants to add a student, prompt and collect the information for that student, then add it to the linked list
    if(strcmp(action, "ADD")==0){
      char *name = new char[80];
      int id = 0;
      float gpa = 0.0;
      cout<<"Name of student: "<<endl;
      cin.get(name, 80);
      cin.ignore(100, '\n');
      cout<<"Student ID Number: "<<endl;
      cin>>id;
      cin.ignore(80,'\n');
      cout<<"GPA of Student: " <<endl;
      cin>>gpa;
      cin.ignore(80, '\n');
      cout<<"Adding student... "<<"Name: "<<name<<"ID: "<<id<<"GPA: "<<gpa <<endl;
      Student* s = new Student(name, id, gpa);
      addStudent(s, head);
    }
    //if user wants to print, go through the nodes, and print the info for each student
    if(strcmp(action,"PRINT")==0){
      if(head != NULL){
	print(head);
      }else{
	cout<<"List is empty"<<endl;
      }
    }
    if(strcmp(action, "AVG")==0){
      Node* current = head;
      if(current != NULL){
      int nodecount = 1;
      float agpa = current->getStudent()->getGPA();
      while(current->getNext() != NULL){
	current = current->getNext();
	agpa += current->getStudent()->getGPA();
	nodecount++;
      }
      cout<<fixed;
      setprecision(2);
      cout<<(agpa/nodecount)<<endl;;
    }else{
      cout<<"List is empty"<<endl;
    }
      
    }
    //exit the loop
    if(strcmp(action, "QUIT")==0){
      cout<<"Exiting..."<<endl;
      inuse = false;
    }
    //delete a student based in the ID that the user gives you
    if(strcmp(action, "DELETE")==0){
      //take in the id
      cout<<"Enter the id of the student you wish to delete"<<endl;
      int id = 0;
      cin>>id;
      cin.ignore(80, '\n');
      deleteNode(head, id);
    }  
  }
  cout<<"EXITED LOOP"<<endl;
  
  return 0;
}

void addStudent(Student* s, Node* &start){
  // cout<<"Entered addStudent"<<endl;
  // cout<<"Student* created"<<endl;
  Node* current = start;
  if(current == NULL){
    start =new Node();
    start->setStudent(s);
  }else{
    if(current->getNext()== NULL){
      current->setNext(new Node());
      current->getNext()->setStudent(s);
    }else{
      current = current->getNext();
      addStudent(s, current);
    }
  }

}
void print(Node* start){
  if(start != NULL){
    start->getStudent()->printS();
  }
  cout<<"Checking for next..."<<endl;
  if(start->getNext() != NULL){
    cout<<"Continuing..."<<endl;
    print(start->getNext());
  }
}
void deleteNode(Node* &start, int id){
  Node* current = start;
  if(current->getStudent()->getID()==id){
    Node* kill = start;
    start = start->getNext();
    delete kill;
  }else{
    if(current->getNext()->getStudent()->getID()==id){
      Node* target = current->getNext();
      current->setNext(target->getNext());
      delete target;
    }else{
      current = current->getNext();
      deleteNode(current, id);
    }
  }
  
}

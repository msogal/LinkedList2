#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node {
 public:
  //constructor, sets Student to NULL and next to NULL
  Node();
  //destructor deletes student and sets next to null
  ~Node();
  //sets the student on the Node
  void setStudent(Student* newS);
  //returns the student
  Student* getStudent();
  //sets the next Node
  void setNext(Node* newN);
  //returns the next Node
  Node* getNext();
 private:
  Student* student;
  Node* next;
};
#endif

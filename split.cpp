/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // no linked list to start with
  Node* temp = in;
  if (in == NULL){
    odds = NULL;
    evens = NULL;
  }
  else if(temp->value %2 ==0){
    in = NULL;
    evens = temp;
    split(temp->next, odds, evens->next);
  }
  else{
    in = NULL;
    odds = temp;
    split(temp->next, odds->next, evens);
  }
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE
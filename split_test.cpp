#include "split.h"
#include <iostream>
using namespace std;

void printLinkedList(Node*& list){
  if(!list){
    cout<<"empty"<<endl;
  }
  else{
    Node* item= list;
    cout<<item->value;
    while(item->next){
      item= item->next;
      cout<<item->value<<" ";
    }
    cout<<endl;
  }
}

int main(int argc, char* argv[])
{
  Node five = Node{-5, NULL};
  Node four = Node{4, &five};
  Node three = Node{3, &four};
  Node two = Node{-2, &three};
  Node one = Node{1, &two};
  Node* head = &one;
  Node* odds = NULL;
  Node* evens = NULL;
  cout<<"original list"<<endl;
  printLinkedList(head);
  split(head, odds, evens);
  cout<<"split ends"<<endl;
  // see odds
  cout<<"odds"<<endl;
  printLinkedList(odds);
  //see even
  cout<<"evens"<<endl;
  printLinkedList(evens);
  // check original empty
  cout<<"original list"<<endl;
  printLinkedList(head);
  return 0;
}


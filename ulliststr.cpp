#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val)
{
  //empty list
  if (empty())
  {
    Item* item1 = new Item;
    head_ = item1;
    tail_ = item1;
    size_ += 1;
    item1->val[0] = val;
    item1->last = 1;
  }
  // existing item 
  else{
    //no space in array in last item
    if (tail_->last == 10){
      // new item
      Item* itemNew = new Item;
      itemNew->val[0] = val;
      itemNew->last = 1;
      itemNew->prev = tail_;
			//update next of previous tail
			tail_->next = itemNew;
      // update the unrolled linked list
      size_ += 1;
      tail_ = itemNew;
    } 
    //still space
    else{
      tail_->val[tail_->last]=val;
      tail_->last +=1;
			size_ += 1;
    }
  }
}
// WRITE YOUR CODE HERE
void ULListStr::pop_back()
{
	// if it's empty, do nothing
	if(empty()){}
	// when the string is the first in the last item
  // need to deallocate item 
  else if(tail_->last == 1)
  {
    Item * prevTail = tail_;
    size_ -= 1;    
    // case of only one item in the linkedList, empty
    if(size_ == 0){
      head_ = NULL;
      tail_ = NULL;
    }
    // first string in last item but size >1
    else{
      prevTail->prev->next = NULL;
      tail_ = prevTail->prev;
    }
		delete prevTail; // deallocate memory
  }
	// regular remove from list of last tiem 
  else{
		tail_->last -= 1;
    tail_->val[tail_->last] =  "";
		size_ -= 1;  
  }
}

void ULListStr::push_front(const std::string& val)
{
	 //empty list put the string at last spot of the first item
  if (empty())
  {
    Item* item1 = new Item;
    head_ = item1;
    tail_ = item1;
    size_ += 1;
    item1->val[9] = val;
    item1->last = 10;
		item1->first = 9;
  }
  // existing item 
  else{
    //no space in array in last item
    if (head_->first == 0){
      // new item
      Item* itemNew = new Item;
      itemNew->val[9] = val;
      itemNew->last = 10;
			itemNew->first = 9;
      itemNew->next = head_;
			// update date pre of previous head
			head_->prev = itemNew;
      // update the unrolled linked list
      size_ += 1;
      head_ = itemNew;
    } 
    //still space
    else{
			head_->first -= 1;
      head_->val[head_->first]=val;
			size_ += 1;
    }
  }
}

void ULListStr::pop_front()
{
	// if it's empty, do nothing
	if(empty()){}
	// when the string is the last in the first item
  // need to deallocate item 
  else if(head_->first == 9)
  {
    Item * prevHead = head_;
    size_ -= 1;    
    // case of only one item in the linkedList, empty
    if(size_ == 0){
      head_ = NULL;
      tail_ = NULL;
    }
    // last string in first item but size >1
    else{
      prevHead->next->prev = NULL;
      head_ = prevHead->next;
    }
		delete prevHead; // deallocate memory
  }
	// regular remove from list of last tiem 
  else{
		head_->val[head_->first] = "";
		head_->first += 1;
		size_ -= 1; 
  }
}

std::string const & ULListStr::back() const
{
	return tail_->val[(tail_->last)-1];
}

std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
	if(head_ == NULL) {return NULL;}
	if(loc >=size_) {return NULL;} // out of bound
	Item* item = head_;
	size_t cnt = item->last - item->first;
	while (cnt < loc+1)
	{
		if(item->next)
		{
			item = item->next;
			cnt += item->last - item->first;
		}	
	}
	size_t index = item->last-item->first-cnt+loc;
	return &item->val[item->first+index];
}

void  ULListStr::printList() 
{
  if(empty()){
    std::cout<<"the list is empty";
  }
  else{
    Item * item = head_;
    while (item)
    {
      for (size_t i = 0; i<10; i++)
        {
          if(item->val[i] == "")
          {
            // no item on the spot print x
            std::cout<<"x"<<" ";
          }
          else
          {
            // print out item
             std::cout<<item->val[i]<<" ";
          }    
        }
      std::cout<<"/";
      item = item->next;
    }
  }
  std::cout<<std::endl;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

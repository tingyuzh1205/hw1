/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;
#include "ulliststr.h"

int main(int argc, char* argv[])
{
	// test add from beginning and end
	// expect two item created with 7 at end of
	// first one and 8 at beginning of second one
	// 8 \ 7  
	ULListStr dat;
	dat.push_back("7"); // push back on empty
	dat.push_front("8");
	cout<<"back "<<dat.back()<<endl;
	cout<<"front "<<dat.front()<<endl;
	cout<<"size "<<dat.size()<<endl;
  dat.printList();

	// test add more to the front and back
	// epxect tow items with 2 strings in each
	// 9 8 / 7 6
	dat.push_back("6");
	dat.push_front("9");
	dat.printList();

	// fill up the second item and add more after
	// expect 3 items with one in the last
	// 9 8 / 7 6 5 4 3 2 1 0 -1 -2 / -3
		dat.push_back("5");
		dat.push_back("4");
		dat.push_back("3");
		dat.push_back("2");
		dat.push_back("1");
		dat.push_back("0");
		dat.push_back("-1");
		dat.push_back("-2");
		dat.push_back("-3");
		dat.printList();

	// pop the first string of last item and some more 
	// 9 8 / 7 6 5 4 3 2 1 0
	dat.pop_back();  // remove -3
	dat.pop_back();  // remove -2
	dat.pop_back();  // remove -1
	dat.printList();

	// push front on existing list inclusing new cell
	//18 / 17 16 15 14 13 12 11 10 9 8 / 7 6 5 4 3 2 1 0
	dat.push_front("10");
	dat.push_front("11");
	dat.push_front("12");
	dat.push_front("13");
	dat.push_front("14");
	dat.push_front("15");
	dat.push_front("16");
	dat.push_front("17");
	dat.push_front("18");
	dat.printList();


	// pop the last string of first item and some more 
	// 15 14 13 12 11 10 9 8 / 7 6 5 4 3 2 1 0
	dat.pop_front();  // remove 18 and item 1
	dat.pop_front();  // remove 17
	dat.pop_front();  // remove -16
	dat.printList();

	// test set function
	dat.set(0,"150"); // change first element to 150
	dat.set(4, "110"); // change 5th item to 110
	dat.set(8, "70");
	dat.set(15, "000");
	// dat.set(17, "000"); // invalid value
	cout<<"first element "<<dat.get(0)<<endl; // 150
	cout<<"5th element "<<dat.get(4)<<endl;  // 110
	dat.printList();

	// test clear method
	dat.clear();
	//dat.set(2 , "000"); //test getValAtLoc with empty list
	cout<<"clear or not 1 = true , 0 = false  result = "<<dat.empty()<<endl; 

	// pop front and back from empty list
	// expect nothing happens
	dat.pop_back();
	dat.pop_back();
	dat.printList();

	// push fron on empty
	// 1/ new element at the end of first item
	dat.push_front("1");
	dat.printList();

	return 0;
}

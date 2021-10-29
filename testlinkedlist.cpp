#include "LinkedList.h"

void insertIntegerData()
{
   LinkedList<int> myList;
   myList.push_back(11);
   myList.push_front(22);
   myList.push_back(33);
   myList.push_front(44);
   myList.push_back(55);
   myList.push_front(66);
   myList.push_back(77);
   myList.push_front(88);
   myList.push_back(99);
   myList.printList();
}

void insertFloatData()
{
   LinkedList<float> myList;
   myList.push_back(11.12);
   myList.push_back(22.23);
   myList.push_back(33.34);
   myList.push_back(44.45);
   myList.push_back(55.56);
   myList.push_back(66.67);
   myList.printList();
}

void insertStringData()
{
   LinkedList<string> myList;
   myList.push_back("pankaj1");
   myList.push_back("pankaj2");
   myList.push_back("pankaj3");
   myList.push_back("pankaj4");
   myList.push_back("pankaj5");
   myList.push_back("pankaj6");
   myList.printList();
}

int main()
{
   insertIntegerData();
   insertFloatData();
   insertStringData();
   return 0;
}
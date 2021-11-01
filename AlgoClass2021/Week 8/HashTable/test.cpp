#include <iostream>
#include <vector>
#include "HashTable.h"

using namespace std;
 
void testFunc();
 
int main()
{
	// testFunc();
	return 0;
}
 
void testFunc()
{
	//testing default constructor
	cout << "\nCreating ht0 using default constructor...\n\n";
	HashTable ht0;

	// cout << "ht0.maxSize(): " << ht0.maxSize() << endl;
	// cout << "ht0.size(): " << ht0.size() << endl << endl;

	// //insert and one param constructor
	// cout << "Creating ht1 using one param constructor...\n\n";
	// HashTable ht1(9);

	// cout << "ht1.maxSize(): " << ht1.maxSize() << endl;
	// cout << "ht1.size(): " << ht1.size() << endl << endl;

	// cout << "Inserting elements to ht1 (test if return true on all inserts):\n";
	// cout << ht1.insert("bat") << endl;
	// cout << ht1.insert("cat") << endl;
	// cout << ht1.insert("rhinoceros") << endl;
	// cout << ht1.insert("ocelot") << endl;
	// cout << ht1.insert("elephant") << endl;
	// cout << ht1.insert("hippopotamus") << endl;
	// cout << ht1.insert("giraffe") << endl;
	// cout << ht1.insert("camel") << endl;
	// cout << ht1.insert("lion") << endl;
	// cout << ht1.insert("panther") << endl;
	// cout << ht1.insert("bear") << endl;
	// cout << ht1.insert("wolf") << endl;
	// cout << endl;

	// cout << "Inserting 'hippopotamus' again: " << ht1.insert("hippopotamus") << endl << endl;

	// //search
	// cout << "Testing search ht1...\n";
	// string _test1 = "frog";
	// string _test2 = "camel";
	// string _test3 = "wolf";
	// string _test4 = "oceano";
	// string _test5 = "bat";
	// cout << "search " << _test1 << "return val: " << ht1.search(_test1) << endl;
	// cout << "search " << _test2 << "return val: " << ht1.search(_test2) << endl;
	// cout << "search " << _test3 << "return val: " << ht1.search(_test3) << endl;
	// cout << "search " << _test4 << "return val: " << ht1.search(_test4) << endl;
	// cout << "search " << _test5 << "return val: " << ht1.search(_test5) << endl;

	cout<<endl;	
}
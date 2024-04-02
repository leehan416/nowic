//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//서명: 이한결 분반: ECE20010-03 학번: 22100594
#include <iostream>
#include <map>

using namespace std;

int main() {
	cout << "declare a map variable called table\n";
	map<string, int> table;
	cout << "initialize table using array[], insert(), pair<>, make_pair()\n";
	
	// your code here
	//---------------------------------
	table["Adam"] = 11;
	table["John"] = 21;
	table.insert(pair<string, int>("Paul", 15));
	table.insert(make_pair("Pete", 10));
	//---------------------------------

	cout << "print table using range-based for loop\n";

	// your code here
		//---------------------------------
		for (auto i : table){
			cout << "name : " << i.first << "\t";
			cout << "age : " << i.second << endl;	
		}
		//---------------------------------

	cout << "print table using iterator\n";

	// your code here
		//---------------------------------
		for (auto i = table.begin(); i != table.end(); i++) {
			cout << "name : " << i->first << "\t";
			cout << "age : " << i->second << endl;	
		}
		//---------------------------------

	cout << "define and initialize chart using pair<> and make_pair() only\n";

	// your code here
		//---------------------------------
		map<char, int> chart;
		chart.insert(pair<char, int>('a', 65));
		chart.insert(pair<char, int>('b', 66));
		chart.insert(make_pair('c', 67));
		chart.insert(make_pair('d', 68));
		//---------------------------------	

	cout << "print chart using range-based for loop\n";
	// your code here
		//---------------------------------
		for (auto i: chart) {
			cout << "ascii : " << i.first << "\t";
			cout << "code : " << i.second << endl;
		}
		//---------------------------------
	return 0;
}
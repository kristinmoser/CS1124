/*
rec01.cpp
Kristin Moser
*/
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
void printLines(ifstream& ifs) {
	string aLine;
	while (getline(ifs, aLine)) {
		cout << aLine << endl;
	}
}
int countWords(ifstream& ifs) { 
	string aWord;
	int counter;
	counter = 0;
		while (ifs >> aWord) {
			++counter;
		}
	return counter;
}

int main(){
	ifstream ifs("file.txt");
	if (!ifs) {
		cerr << "Failed to open file\n";
		exit(1);
	}
	printLines(ifs);
	ifs.clear();
	ifs.seekg(0);
	int count=countWords(ifs);
	cout << count;
	ifs.close();
	system("pause");
}




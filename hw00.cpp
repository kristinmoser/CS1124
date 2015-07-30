/*
hw00.cpp
programmer : Kristin Moser
this program reads a file and increments every lowercase letter by the counter given. it also
reverses the line order. 
*/
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void changeCharacter(vector<string>& lines, int& counter){
	for (int i = 0; i < lines.size(); ++i){
		for (char& letter : lines[i]){
			if (letter == ' ' || letter == '.' || letter == '\n') {
				letter = letter;
			}
			else if ('a' <= letter && letter <= 'z') {
				letter -= counter;
				if (letter < 'a' && letter >= 'a' - counter) {
					letter += 26;
				}
				else {
					letter = letter;
				}
			}
		}
	}
}
	
vector<string> getLinesAndMakeVector(ifstream& ifs){
	vector<string> lines;
	string line;
	while (getline(ifs, line)) {
		lines.push_back(line);
	}
	return lines;
}
void rearrangeLines(vector<string> lines){
	for (int i = lines.size() - 1; i > -1; --i){
		cout << lines[i] << endl;
	}
}
int main(){
	ifstream ifs("encrypted.txt");
	if (!ifs) {
		cerr << "Failed to open file\n";
		exit(1);
	}
	int counter;
	ifs >> counter;
	vector<string> lines = getLinesAndMakeVector(ifs);
	changeCharacter(lines, counter);
	rearrangeLines(lines);
	system("pause");
}
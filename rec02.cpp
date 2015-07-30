/*
rec02.cpp
Kristin Moser
*/
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
struct hydrocarbon{
	int carbonNo; 
	int hydrogenNo;
	vector<string> name;
};
size_t checkDuplicates(vector<hydrocarbon>& molecules, int& localCarbon, int& localHydrogen);

void readAndProcess(ifstream& ifs, vector<hydrocarbon>& molecules){
	string localName;
	int localCarbon;
	int localHydrogen;
	char uselessChar;
	while (ifs >> localName >> uselessChar >> localCarbon >> uselessChar >> localHydrogen){
		size_t index = checkDuplicates(molecules, localCarbon, localHydrogen);
		if (index == molecules.size()){
			hydrocarbon localhydrocarbon;
			localhydrocarbon.carbonNo = localCarbon;
			localhydrocarbon.hydrogenNo = localHydrogen;
			localhydrocarbon.name.push_back(localName);
			molecules.push_back(localhydrocarbon);
		}
		else{
			molecules[index].name.push_back(localName);
		}
	}
}
size_t checkDuplicates(vector<hydrocarbon>& molecules, int& localCarbon, int& localHydrogen){
	for (size_t i = 0; i < molecules.size(); ++i){
		if ((molecules[i].carbonNo == localCarbon) && (molecules[i].hydrogenNo == localHydrogen)){
			return i;
		}
	}
	return molecules.size();
}

void printVector(vector<hydrocarbon>& molecules){
	for (size_t i = 0; i < molecules.size(); ++i){
		cout << "C" << molecules[i].carbonNo <<"H" << molecules[i].hydrogenNo << endl;
		for (size_t j = 0; j < molecules[i].name.size(); ++j){
			cout << molecules[i].name[j] << endl;
		}
	}
}

int main(){
	ifstream ifs("chemicals.txt");
	if (!ifs) {
		cerr << "Failed to open file\n";
		exit(1);
	}
	vector<hydrocarbon> molecules;
	readAndProcess(ifs, molecules);
	printVector(molecules);
	system("pause");
}
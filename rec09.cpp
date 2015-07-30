/*
  Recitation 09
  CS1124
 
  Focus: Copy Control.  Uses dynamic array of pointers.
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
    Position(const string& aTitle, double aSalary)
	: title(aTitle), salary(aSalary) {}
    string getTitle() const {return title;}
    double getSalary() const {return salary;}
    void changeSalaryTo(double d) {salary = d;}
private:
    string title;
    double salary;
}; 

class Entry {
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone,
	  Position& aPosition) 
	: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
    }
    friend ostream& operator<<( ostream& os, const Entry& e ) {

		os << e.name << ' ' << e.room << ' ' << e.phone;
        return os;
    } 

	string getName() const{
		return name;
	}

	unsigned getPhone(){
		return phone;
	}
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; 

class Directory {
public:
    Directory(): capacity(2), size(0), entries(new Entry*[2] )
    {
        for (size_t i = 0; i < capacity; i++) {
            entries[i] = nullptr;
        } 
    }
	~Directory(){
		for (size_t i = 0; i < size ; ++i){
			delete entries[i];
		}
		delete[] entries;
	}

	Directory(const Directory& rhs){
		capacity = rhs.capacity;
		size = rhs.size;
		entries = new Entry*[capacity];
		for (size_t i = 0; i < rhs.size; ++i){
			entries[i] = new Entry(*rhs.entries[i]);
		}
	}
	Directory& operator=(const Directory& rhs){
		if (this != &rhs){
			for (size_t i = 0; i < size; ++i){
				delete entries[i];
			}
			delete[] entries;
			entries = new Entry*[rhs.capacity];
			for (size_t i = 0; i < rhs.size; ++i)
				entries[i] = new Entry(*rhs.entries[i]);
			size = rhs.size;
			capacity = rhs.capacity;

		}
		return *this;
	}

	unsigned operator[](const string& name)const{
		for (size_t i = 0; i < size; ++i){
			if (entries[i]->getName() == name){
				return entries[i]->getPhone();
			}
		}
		return 0;
	}

    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if (size == capacity)	{
			Entry** old = entries;
			entries = new Entry*[capacity *= 2];
			for (size_t i = 0; i < size; ++i){
				entries[i] = old[i];
			}
			delete[] old;
		}
		cout << "Size" << size << "capacity" << capacity <<  endl;
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } 

	friend ostream& operator<<(ostream& os, const Directory& d) {
		cout << "size" << d.size << endl;
		for (size_t i = 0; i < d.size; ++i){
			os << *d.entries[i];
		}
		return os;
	}
private:	
    Entry** entries;
    size_t size;
    size_t capacity;
}; 

void doNothing(Directory dir) { cout << dir << endl; }

int main() {
	
    // Model as if there are these four kinds 
    // of position in the problem:
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
	
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2 = d;	// What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d2 << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    Directory d3;
    d3 = d2;
	system("pause");
} // main

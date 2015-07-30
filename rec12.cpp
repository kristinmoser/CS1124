#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* link;
	Node(int data = 0, Node* link = nullptr) : data(data), link(link){}
};

class Sequence{
public:
	Sequence() : head(nullptr), current(nullptr){}
	void reset(){
		current = head;
		//cout << "reset" << endl;
	}

	void add(int data){
		Node* newNode = new Node(data);

		if (valid()){
			newNode->link = current->link;
			current->link = newNode;
			//cout << current->data << " now links to " << newNode->data << endl;
		}
		else{
			head = newNode;
			//cout << "head = " << newNode->data << endl;
		}
		current = newNode;
		//make current and headptr as new node
	}
	void remove(){
		if (!valid()) { return; }
		Node* temp = head;
		while (temp->link != current){
			temp = temp->link;
		}
		temp->link = current->link;
		delete current;
	

	}

	int data() const{
		if (valid()){ return current->data; }
		else{ return -1; }
	}
	void next(){
		if (valid()){
			current = current->link;
		}
		else{
			reset();
		}
	}
	bool valid() const{
		return current != nullptr;
	}
	void clear(){
		reset();
		while (current != nullptr){
			Node* temp = current->link;
			delete current;
			current = temp;
		}
		head = nullptr;
	}
	void display()const{
		Node* temp = head;
		while (temp != nullptr){
			cout << temp->data << ", ";
			temp = temp->link;
		}
		cout << endl;
	}
private:
	Node* head;
	Node* current;
};

int main() {
	Sequence s;
	for (int i = 0; i < 6; ++i) s.add(i);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 3; ++i) s.next();
	s.add(42);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 2; ++i) s.next();
	s.remove();
	s.display();
	cout << "==========\n";
	s.clear();
	s.display();
	cout << "==========\n";
	system("pause");
}
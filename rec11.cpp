#include <cstdlib> // To allow NULL if no other includes
#include <iostream>
struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void spliceLists(Node*& headPtr, Node*& headPtr2){
	Node* temp = headPtr->link;
	headPtr->link = headPtr2;
	while (headPtr2->link != nullptr){
		headPtr2 = headPtr2->link;
	}
	headPtr2->link = temp;
}

Node* findNode(Node* headPtr, int data){
	//if (headPtr == nullptr){ return nullptr; }
	while (headPtr != nullptr){
		if (headPtr->data == data){
			return headPtr;
		}
		headPtr = headPtr->link;
	}
	return nullptr;
}


void display(Node* headPtr){
	while (headPtr != nullptr){
		std::cout << headPtr->data << " ";
		headPtr = headPtr->link;
	}
	std::cout << std::endl;
}

Node* isSublist(Node* headPtr, Node*& headPtr2){
	if (headPtr == nullptr){ return nullptr; }
	if (headPtr2 == nullptr){ return nullptr; }
	Node* ptr = findNode(headPtr, headPtr2->data);
	std::cout << "Attempt match: ";
	display(headPtr2);
	while (ptr != NULL){
		Node* temp = ptr;
		Node* temp2 = headPtr2;
		while (temp && temp2 && temp->data == temp2->data){
			temp = temp->link;
			temp2 = temp2->link;
			if (temp2 == nullptr){
				return ptr;
			}
			if (temp == nullptr){
				return nullptr;
			}
			
		}
		headPtr = ptr->link;
		ptr = findNode(headPtr, headPtr2->data);
	} 
	return nullptr;
}

int main(){
	Node* list = NULL;
	listInsertHead(1, list);
	listInsertHead(9, list);
	listInsertHead(7, list);
	listInsertHead(5, list);
	Node* list2 = NULL;
	listInsertHead(2, list2);
	listInsertHead(3, list2);
	listInsertHead(6, list2);
	std::cout << "L1: ";
	display(list);
	std::cout << "L2: ";
	display(list2);
	Node* ptr = findNode(list, 7);
	Node* aPtr = findNode(list2, 6);
	spliceLists(ptr, aPtr);
	std::cout << "L1: ";
	display(list);
	std::cout << "L2: ";
	display(list2);
	std::cout << "============" << std::endl;
	Node* target = NULL;
	listInsertHead(6, target);
	listInsertHead(5, target);
	listInsertHead(4, target);
	listInsertHead(2, target);
	listInsertHead(3, target);
	listInsertHead(2, target);
	listInsertHead(3, target);
	listInsertHead(2, target);
	listInsertHead(1, target);
	std::cout << "Target: ";
	display(target);
	Node* match1 = NULL;
	listInsertHead(1, match1);
	Node* p = isSublist(target, match1);
	if (p){ display(p); }
	else{ std::cout << "Failed to match" << std::endl; }
	Node* match2 = NULL;
	listInsertHead(9, match2);
	listInsertHead(3, match2);
	Node* q = isSublist(target, match2);
	if (q){ display(q); }
	else{ std::cout << "Failed to match" << std::endl; }
	Node* match3 = NULL;
	listInsertHead(3, match3);
	listInsertHead(2, match3);
	Node* r = isSublist(target, match3);
	if (r){ display(r); }
	else{ std::cout << "Failed to match" << std::endl; }
	Node* match4 = NULL;
	listInsertHead(6, match4);
	listInsertHead(5, match4);
	listInsertHead(4, match4);
	listInsertHead(2, match4);
	Node* s = isSublist(target, match4);
	if (s){ display(s); }
	else{ std::cout << "Failed to match" << std::endl; }
	Node* match5 = NULL;
	listInsertHead(4, match5);
	listInsertHead(2, match5);
	listInsertHead(3, match5);
	listInsertHead(2, match5);
	Node* t = isSublist(target, match5);
	if (t){ display(t); }
	else{ std::cout << "Failed to match" << std::endl; }
	Node* match6 = NULL;
	listInsertHead(7, match6);
	listInsertHead(6, match6);
	listInsertHead(5, match6);
	Node* u = isSublist(target, match6);
	if (u){ display(u); }
	else{ std::cout << "Failed to match" << std::endl; }
	system("pause");
}
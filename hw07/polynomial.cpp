/*
Kristin Moser
cs1124
last and final hw : hw07
rip object oriented ^__^
*/

#include "polynomial.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
Node::Node(const int& data) : data(data), next(nullptr){}

Polynomial::Polynomial(const vector<int>& coefficients) : degree(coefficients.size() - 1), headptr(nullptr){
	headptr = new Node(coefficients[0]);
	Node* temp = headptr;
	for (size_t i = 1; i < coefficients.size(); ++i){
		temp->next = new Node(coefficients[i]);
		temp = temp->next;
	}
}
Polynomial::Polynomial(){}


Polynomial Polynomial::operator=(Polynomial& poly){
	if (this != &poly) {
		Node* temp = headptr;
		while (temp != nullptr) {
			headptr = headptr->next;
			delete temp;
			temp = headptr;
		}
	}
	degree = poly.degree;
	Node* iter = poly.headptr;
	while (iter != nullptr){
		if (headptr == nullptr) {
			headptr = new Node(iter->data);
		}
		else {
			if (headptr == nullptr) {
				return *this;
			}
			Node* tempPtr = headptr;
			while (tempPtr->next != nullptr) {
				tempPtr = tempPtr->next;

				Node* last = tempPtr;
				last->next = new Node(iter->data);
			}
			iter = iter->next;
		}
		return *this;
	}
}
Polynomial::~Polynomial() {
	Node* temp = headptr;
	while (temp != nullptr) {
		headptr = headptr->next;
		delete temp;
		temp = headptr;
	}
}




Polynomial& Polynomial::operator+=(Polynomial& poly){
	Node* current1 = headptr;
	Node* current2 = poly.headptr;
	if (current2 == nullptr) { return *this; }
	if (current1 == nullptr) { current1 = current2; return *this; }
	for (int i = 0; i < poly.degree + 1; ++i) {
		if ( current1 != nullptr && current2 != nullptr) {
			current1->data += current2->data;
			current1 = current1->next;
			current2 = current2->next;
		}
		else {
			if (current1 == nullptr){  
				current1 = new Node(current2->data); 
				current2 = current2->next;
			}
			current1 = current1->next;
		}
	}
	return *this;
}



Polynomial::Polynomial(const Polynomial& poly) : headptr(nullptr) {
	this->degree = poly.degree;
	Node* temp = poly.headptr;
	while (temp != nullptr){
		if (headptr == nullptr) {
			headptr = new Node(temp->data);
		}
		else {
			headptr->next = new Node(temp->data);
			temp = headptr->next;
		}
		temp = temp->next;
	}
}

Polynomial operator+(Polynomial& lhs, Polynomial& rhs) {
	Polynomial result(lhs);
	return (result += rhs);
}
bool Polynomial::operator==(Polynomial& poly){
	Node* temp = headptr;
	Node* temp2 = poly.headptr;
	if (degree != poly.degree) {
		return false;
	}
	for (int i = 0; i < degree; ++i) {
		if (!temp || !temp2){ return true; }
		if (temp->data == temp2->data) {
			temp = temp2->next;
			temp2 = temp2->next;
		}
	}
	return (temp->next == nullptr && temp2->next == nullptr && temp->data == temp2->data);
}

bool Polynomial::operator!=(Polynomial& poly){
	Node* temp = headptr;
	Node* temp2 = poly.headptr;
	if (degree != poly.degree) {
		return true;
	}
	for (int i = 0; i < degree; ++i) {
		if (temp->data == temp2->data) {
			temp = temp->next;
			temp2 = temp2->next;
		}
	}
	return (temp->next != nullptr || temp2->next != nullptr || temp->data != temp2->data);
}

int Polynomial::evaluate(int x){
	Node* temp = headptr;
	int result = 0;
	for (int i = 0; i <= degree; i++) {
		result += (temp->data * pow(x, i));
		temp = temp->next;
	}
	return result;



}

void printReverse(Node* headptr, int degree){
	if (headptr == nullptr) {
		return;
	}
	++degree;
	printReverse(headptr->next, degree);
	if (headptr != nullptr) {
		if (degree != 0) {
			cout << headptr->data << "x^" << degree << " + ";
		}
		else {
			cout << headptr->data;
		}
		
	}
	
}

std::ostream& operator<<(std::ostream& cout, Polynomial& poly){
	printReverse(poly.headptr, -1);
	return cout;
}
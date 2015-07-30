#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<string>
#include<vector>
#include<iostream>

struct Node{
	Node(const int& data);
	Node(Node* n);
	int data;
	Node* next;
	void display()const;
};

class Polynomial{
public:
	Polynomial(const std::vector<int>& coeffecients);
	Polynomial(const Polynomial& rhs);
	Polynomial();
	Polynomial operator=(Polynomial& poly);
	~Polynomial();
	Polynomial& operator+=(Polynomial& poly);
	bool operator==(Polynomial& poly);
	bool operator!=(Polynomial& poly);
	int evaluate(int x);
	void display();
	friend std::ostream& operator<<(std::ostream& cout, Polynomial& poly);
private:
	unsigned degree;
	Node* headptr;
};

std::ostream& operator<<(std::ostream& cout, Polynomial& poly);
Polynomial operator+(Polynomial& lhs, Polynomial& rhs);
#endif
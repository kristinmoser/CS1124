/*
Kristin Moser
cs1124
rec13
*/
#include <climits>
#include <vector>
#include<iostream>
using namespace std;
struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void display(Node* headPtr){
	while (headPtr != nullptr){
		std::cout << headPtr->data << " ";
		headPtr = headPtr->link;
	}
	std::cout << std::endl;
}

struct TNode {
	TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
		: data(data), left(left), right(right) {}
	int data;
	TNode *left, *right;
};

void intToBinary(int num){
	if (num < 1){return;}
	intToBinary(num / 2);
	cout << num % 2;
}

Node* sum(Node* list1, Node* list2){
	if (!list1){ return nullptr; }
	Node* newNode = new Node(list1->data + list2->data);
	newNode->link = sum(list1->link, list2->link);
	return newNode;
}

int maxOfTree(TNode* node){
	if (!node){ return INT_MIN; }
	int max = node->data;
	int leftMax = maxOfTree(node->left);
	int rightMax = maxOfTree(node->right);
	if (rightMax > leftMax){
		if (rightMax > max){
			return rightMax;
		}
		else{ return max; }
	}
	else{
		if (leftMax > max){
			return leftMax;
		}
		else{ return max; }
	}
}

int sumOfCString(char* array){
	if (array[0] == '\0'){ return 0; }
	return(int(array[0]) + sumOfCString(array + 1));
}

int binSearch(char* array, char target, int left, int right){
	if (left > right) return -1;
	int mid = left + (right - left) / 2;
	if (target == array[mid]) return mid;
	else if (target < array[mid]) {
		return binSearch(array, target, left, mid - 1);
	}
	else { 
		return binSearch(array, target, mid + 1, right);
	}

}
void f(int n) {
	if (n > 1) {
		cout << 'a';
		f(n / 2);
		cout << 'b';
		f(n / 2);
	}
	cout << 'c';
}
int main(){
	//cout << "bin: ";
	//intToBinary(13);
	//cout << endl;
	//Node* p = new Node(12);
	//p->link = new Node(2);
	//Node* h = new Node(3);
	//h->link = new Node(1);
	//Node* newL = sum(p, h);
	//cout << "sum list: ";
	//display(newL);
	//f(5);
	//cout << endl;
	//TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	//cout << "max of tree: " << maxOfTree(&f) << endl;
	//char anArray[] = "hello world";
	//int summ = sumOfCString(anArray);
	//cout << "string sum: " << summ << endl;
	//int where = binSearch(anArray, 'o', 0,4);
	//cout << "where: " << where << endl;

	cout << endl;
	f(7);
	
	system("pause");

}
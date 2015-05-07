#ifndef NODE_HEADER
#define NODE_HEADER

#include <stddef.h>
#include <string>

using namespace std;

class Node{
private:
	Node* right;
	Node* left;
	int value;
public:
	Node(int value);
	int getValue();
	Node* getLeft();
	Node* getRight();
	void setRight(Node* node);
	void setLeft(Node* node);
	void setValue(int value);
};

#endif
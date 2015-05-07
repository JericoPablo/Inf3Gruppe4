#include "Node.h"
#include <stddef.h>

/*Individual constructor for Node with value as parameter*/
Node::Node(int value){
	this->left = NULL;
	this->right = NULL;
	this->setValue(value);
}

/*Getter for class Node*/
int Node::getValue(){
	return this->value;
}
/*Getter for class Node*/
Node* Node::getLeft(){
	return this->left;
}
/*Getter for class Node*/
Node* Node::getRight(){
	return this->right;
}
/*Setter for class Node*/
void Node::setRight(Node* a){
	this->right = a;
}
/*Setter for class Node*/
void Node::setLeft(Node* a){
	this->left = a;
}
/*Setter for class Node*/
void Node::setValue(int value){
	this->value = value;
}
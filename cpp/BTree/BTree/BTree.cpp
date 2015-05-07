#include "BTree.h"
#include "Node.h"
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

/*Constructor of the Binary Tree */
BTree::BTree(int value){
	assert(value >= 0 || value <= 0);
	root = new Node(value);
}
/*Returns the root*/
Node* BTree::Root(){
	return root;
}


/*Returns the smallest int value*/
int BTree::getSmallest(){
	Node *node = getSmallest(root);		
	assert(node == NULL || node != NULL);
	if (node == NULL){
		return NULL;						
	}
	else{
		return node->getValue();	
	}
}
/*Returns the node with the smallest value*/
Node* BTree::getSmallest(Node* s){
	assert(s!=NULL);
	if (s!=NULL){
		while (s->getLeft()!=NULL){
			s = s->getLeft();
		}
	}
	return s;
}

/*Calls getHeightRec with current height of 0 and root*/
int BTree::getHeight(){
	return getHeightRec(0, root);
}

/*Returns the height of the binary tree*/
int BTree::getHeightRec(int cHeight, Node* node){
	assert(cHeight >= 0);
	if (node != NULL){
		return max(getHeightRec(cHeight + 1, node->getLeft()), getHeightRec(cHeight + 1, node->getRight()));
		/*Counting recursive the maximum depth of the left and right subtree. Methode max(); returns the bigger value.*/
	}
	assert(cHeight >= 0);
	return cHeight;
}
/*Returns the biggest value,but only when the binary tree exist.*/
int BTree::getBiggest(){
	Node* node = getBiggest(root);			
	assert(node==NULL || node!=NULL);
	if (node==NULL){
		return NULL;
	}else{
		return node->getValue();
	}
}

/*Return the node with the biggest value, basically the very right + bottom node.*/
Node* BTree::getBiggest(Node* s){
	assert(s==NULL || s!=NULL);
	if (s != NULL){
		while (s->getRight() != NULL){
			s = s->getRight();
		}
	}
	return s;
}

/*Prints root,left,right recursive*/
void BTree::preOrder(Node* node){
	assert(node == NULL || node != NULL);
	if (node != NULL){
		cout << node->getValue() << "   ";			//root node
		preOrder(node->getLeft());					//left node
		preOrder(node->getRight());					//right node
	}
}
/*Prints left,root,right recursive*/
void BTree::inOrder(Node* node){
	assert(node==NULL || node!=NULL);
	if (node!=NULL){
		inOrder(node->getLeft());					//left node
		cout << node->getValue() << "   ";			//root node
		inOrder(node->getRight());					//right node
	}
}
/*Prints left,right,root recursive*/
void BTree::postOrder(Node* node){
	assert(node==NULL || node!=NULL);
	if (node != NULL){
		postOrder(node->getLeft());					//left node
		postOrder(node->getRight());				//right node
		cout << node->getValue() << "   ";			//root node
	}
}

void BTree::insert(int value){
	assert(value <= 0 || value >= 0);
	if (root == NULL){
		root = new Node(value);					
		/*Creates a new binary tree if no exists*/
	}
	this->insert(root, value);		
		/*Calls the recursive function insert with the root and the value of the next node to be created*/
}

/*Creates and inserts the new node into the tree starting at root*/
void BTree::insert(Node* node, int value){
	assert(value<=0 || value>=0);
	if (node==NULL){
		node = new Node(value);
		if (root==NULL){
			root = node;
		}
	}else{ 
		if (value<(node->getValue())){				//Visit left subtree if value smaller than parent
			if (node->getLeft()!=NULL){
				/*If there is an left subtree function goes through the left subtree till it finds 
				the place for the new node with new value to be inserted*/
				insert(node->getRight(),value);
			} else{
				node->setLeft(new Node(value));
				//If there is no left node it creates a new one 
			}
		}
		if (value>(node->getValue())){				//Visit right subtree if value smaller than parent
			if (node->getRight() != NULL){
				insert(node->getRight(), value);
				/*If there is an right subtree function goes through the left subtree till it finds
				the place for the new node with new value to be inserted*/
			}
			else{
				node->setRight(new Node(value));
				//If there is no right node it creates a new one 
			}
		}
	}
}

/*Calls delRec with root , value to delete, parent is NULL because starting at root, false*/
bool BTree::delNode(int value){
	assert(value <= 0 || value>=0);
	return delRec(root, value, NULL,false);
}

bool BTree::delRec(Node* node, int data, Node* parent, bool leftFromParent){
	assert(data <= 0 || data >= 0);
	if (node == NULL){
		return false;									
	}
	if ((data == (node->getValue()))){
		if ((node->getLeft() == NULL) && (node->getRight() == NULL)){		//Parent has noch children  (root)
			if (parent == NULL){											//If Parent doesnt exist
				root = NULL;												//Root gets deletet
			}else{
				hangUnderParent(parent, leftFromParent, NULL);				//Calls hangUnderParent to order node at right or left side of parent, in this case not.
			}														
			return true;
		}
		if ((node->getLeft() == NULL) && (node->getRight() != NULL)){		//Parent has child on right side
			if (parent == NULL){
				root = node->getRight();									//Root becomes right child of Node
			}
			else{
				hangUnderParent(parent, leftFromParent, node->getRight());	//Calls hangingUnderParent and deletes right side because it is NULL
			}
			return true;
		}
		if ((node->getLeft() != NULL) && (node->getRight() == NULL))		//If Parent has child only on the left side
		{
			if (parent == NULL){
				root = node->getLeft();										//Root becomes left child of Node
			}
			else{
				hangUnderParent(parent, leftFromParent, node->getLeft());	//Calls hangUnderParent and deletes left side
			}
			return true;
}

		Node* newNode = getSmallest(node->getRight());						//Gets the child with smallest value
		delNode(newNode->getValue());										//Deletes the Node
		if (parent == NULL){
			newNode->setLeft(root->getLeft());								//Sets the children from the old parent to the new
			newNode->setRight(root->getRight());							
			root = newNode;													//Smallest child becomes new parent(root)
		}
		else{
			newNode->setLeft(node->getLeft());								//Gets left Node from deleted Parent
			newNode->setRight(node->getRight());							//Gets right Node from deleted Parent
			hangUnderParent(parent, leftFromParent, newNode);				//Delets the Node
		}
	}

	if ((data < (node->getValue()))){										//Left side
		if (node->getLeft() == NULL){
			return false;
		}
		return delRec(node->getLeft(), data, node, true);					//Recursion till node gets found on the left side
	}
	if ((data >(node->getValue()))){										//Right side
		if (node->getRight() == NULL){
			return false;
		}
		return delRec(node->getRight(), data, node, false);					//Recursion till node gets found on the right side
	}
	return false;
}

void BTree::hangUnderParent(Node* parent, bool left,Node* node){
	assert(left == true || left == false);
	if (left){
		parent->setLeft(node);												//Deletes left side
	}
	else{
		parent->setRight(node);												//Deletes right side
	}
}

string BTree::Search(Node* node, int value){
	assert(value <= 0 || value >= 0);
	if (node == NULL){
		return "\nNot Found";												//Returns "Not Found" if value dies not exist
	}else if (node->getValue() == value){
		return "\nFound";													//Return "Found" if value gets found
	}else if (value <= node->getValue()){
		return Search(node->getLeft(), value);								//Recursive call to search the left subtree for the value
	}
	else{
		return Search(node->getRight(), value);								//Recursive call to search the right subtree for the value
	}
}

double BTree::Sum(Node* node){
		assert(node == NULL || node != NULL);
		double mySum, lSum, rSum;
		if (node == NULL){
			mySum = 0;        
		
		}
		else{
			lSum = Sum(node->getLeft());									//Recursive call with left side of parent node
			rSum = Sum(node->getRight());									//Recursive call with right side of parent node
			mySum = node->getValue() + lSum + rSum;
		}
	return mySum;
}
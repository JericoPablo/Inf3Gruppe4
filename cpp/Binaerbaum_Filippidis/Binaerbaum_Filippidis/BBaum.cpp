
#include <stdio.h>
#include<iostream>
#include <conio.h>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

Node* GetNewNode(int value){
	Node* newNode = new Node();
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, int value){
		if (root==NULL){
			root = GetNewNode(value);
		}
		else if (value <= root->value){
			root->left = Insert(root->left,value);
		}
		else{
			root->right = Insert(root->right,value);
		}

	return root;
}

Node* FindMin(Node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

struct Node* Delete(struct Node *root, int value) {
	if (root == NULL) return root;
	else if (value < root->value) root->left = Delete(root->left, value);
	else if (value > root->value) root->right = Delete(root->right, value);
	else {

		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		else {
			struct Node *temp = FindMin(root->right);
			root->value = temp->value;
			root->right = Delete(root->right, temp->value);
		}
	}
	return root;
}

bool Search(Node* root,int value){
	if (root == NULL) return false;
	else if (root->value == value) return true;
	else if (value <= root->value) return Search(root->left, value);
	else return Search(root->right, value);
}


void Inorder(Node *root) {
	if (root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%d ", root->value);  //Print data
	Inorder(root->right);      // Visit right subtree
}

int main() {
	/*Code To Test the logic
	Creating an example tree
	5
	/ \
	3   10
	/ \   \
	1   4   11
	*/
	Node* root = NULL;
	root = Insert(root, 5); root = Insert(root, 10);
	root = Insert(root, 3); root = Insert(root, 4);
	root = Insert(root, 1); root = Insert(root, 11);

	// Deleting node with value 5, change this value to test other cases
	root = Delete(root, 5);

	//Print Nodes in Inorder
	cout << "Inorder: ";
	Inorder(root);
	cout << "\n";

	int a;
	cin >> a;
}
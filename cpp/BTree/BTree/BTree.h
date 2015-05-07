#ifndef BTREE_HEADER
#define BTREE_HEADER

#include <stddef.h>
#include "Node.h"
#include <string>
using namespace std;

class BTree{
private:
	Node* root=NULL;
public:
	BTree(int root);
	Node* Root();
	int getHeight();
	int getHeightRec(int cHeight, Node* node);
	int getSmallest();
	Node* getSmallest(Node* s);
	int	getBiggest();
	Node* getBiggest(Node* s);
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	void insert(int value);
	void insert(Node* n, int value);
	bool delNode(int value);
	bool delRec(Node* node, int data, Node* parent, bool leftFromParent);
	void hangUnderParent(Node* parent, bool left, Node* node);
	string BTree::Search(Node* node, int value);
	double Sum(Node* node);
};

#endif
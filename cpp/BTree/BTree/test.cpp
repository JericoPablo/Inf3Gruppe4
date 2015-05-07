#include "BTree.h"
#include "Node.h"

using namespace std;

int main(int argc, const char* argv[])
{
	BTree b(5);
	b.insert(2);
	b.insert(3);
	b.insert(6);
	b.insert(7);
	b.insert(8);

	printf("inOrder : ");
	b.inOrder(b.Root());

	printf("\npreOrder : ");
	b.preOrder(b.Root());

	printf("\npostOrder : ");
	b.postOrder(b.Root());

	printf("\nHeight is : %i", b.getHeight());

}

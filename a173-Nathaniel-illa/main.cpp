#include "DLL.hpp"
#include "DLLNode.hpp"
#include <iostream>
using namespace std;

template <class T>
void printDLL(DLL<T> &dll);

int main()
{
	DLL<int> dll;
	dll.addtoTail(4);		// test: add to tail
	dll.addtoTail(5);		// test: add to tail
	dll.addtoTail(6);		// test: add to tail
	printDLL(dll);			//  1 2 3 4 5 6
	dll.deleteNode(4);		// test: delete middle
	printDLL(dll);			//  1 2 4 5 6
	dll.deleteNode(6);		// test: delete tail
	printDLL(dll);			//  1 2 4 5
	dll.deleteNode(5);		// test: delete tail
	printDLL(dll);			//  1 2 4


	DLL<string> dll2;
	dll2.addtoTail("Hello");
	dll2.addtoTail("World");
	printDLL(dll2);
	dll2.deleteNode("Hello");
	printDLL(dll2);
	dll2.deleteNode("World");
	printDLL(dll2);
}
template <class T>
void printDLL(DLL<T> &dll){
	DLLNode<T> *ptr;
	if (dll.isEmpty()) return;
	ptr = dll.getHead();
	while (ptr != nullptr){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
	}
	cout << endl;
}
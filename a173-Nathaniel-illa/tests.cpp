#define CATCH_CONFIG_MAIN // defines main() automatically
#include "catch.hpp"
#include "DLL.hpp"
#include "DLLNode.hpp"
// tests for exercise 1

TEST_CASE("Ex1 ", "[Test 1]")
{
	DLL<int> dll;
	dll.addtoTail(4);
	dll.addtoTail(5);
	dll.addtoTail(6);
	DLLNode<int> *ptr = dll.getHead();
	while(ptr != nullptr){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
	}
	cout << endl;
	REQUIRE(dll.getTail()->getData() == 6);
	REQUIRE(dll.getTail()->getPrev()->getData() == 5);
	REQUIRE(dll.getTail()->getPrev()->getPrev()->getData() == 4);
}

TEST_CASE("Ex2 ", "[Test 2 string data]")
{
	DLL<string> dll2;
	dll2.addtoTail("Hello");
	dll2.addtoTail("World");
	DLLNode<string> *ptr = dll2.getHead();
	while(ptr != nullptr){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
	}
	REQUIRE(dll2.getHead()->getData() == "Hello");
	REQUIRE(dll2.getTail()->getData() == "World");
	dll2.deleteNode("Hello");
	REQUIRE(dll2.getHead()->getData() == "World");
	dll2.deleteNode("World");
	REQUIRE(dll2.isEmpty() == 1);
}

TEST_CASE("Ex3 ", "[Test 2 int data]")
{
	DLL<int> dll;
	dll.addtoTail(1);
	dll.addtoTail(2);
	dll.addtoTail(3);
	REQUIRE(dll.getHead()->getData() == 1);
	REQUIRE(dll.getTail()->getData() == 3);
	REQUIRE(dll.getTail()->getPrev()->getData() == 2);
	REQUIRE(dll.getHead()->getNext()->getData() == 2);
	dll.deleteNode(2);
	REQUIRE(dll.getHead()->getNext()->getData() == 3);
	dll.deleteNode(1);
	REQUIRE(dll.getHead()->getData() == 3);
	dll.deleteNode(3);
	REQUIRE(dll.isEmpty() == 1);
}
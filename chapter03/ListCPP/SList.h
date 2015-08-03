#ifndef __S_LIST_H__
#define __S_LIST_H__

#include <stdlib.h>

typedef int ElementType;
typedef unsigned int SIZE;

struct Node
{
	ElementType value;
	Node* next;

	Node() : value(0), next(NULL) {}

	Node(ElementType element) : value(element), next(NULL) {}
};

class SList
{
public:
	SList();
	~SList();

	bool isEmpty();
	bool AddElement(Node* node);
	bool InsertElement(Node* node, Node* position);
	bool DeleteElement(Node* node);

	Node* GetElement(ElementType element);

	int GetListSize();

	void PrintList();

private:
	Node* CreateNewNode(Node* node);
	Node* GetNode(Node* node);
	Node* GetPreviousNode(Node* node);
	bool DeleteList();

private:
	Node* pHead;
	Node* pLast;

	SIZE nSize;
};
#endif
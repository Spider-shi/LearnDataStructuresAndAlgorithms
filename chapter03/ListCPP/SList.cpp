#include <iostream>
#include "SList.h"

using std::cout;
using std::endl;

SList::SList()
: pHead(NULL)
, pLast(NULL)
, nSize(0)
{

}

SList::~SList()
{
	DeleteList();

	pHead = NULL;
	pLast = NULL;
}

Node* SList::CreateNewNode( Node* node )
{
	Node* pNewNode = new Node;
	pNewNode->value = node->value;
	pNewNode->next = NULL;

	return pNewNode;
}

Node* SList::GetNode( Node* node )
{
	if(!pHead)
		return NULL;

	Node* pTmpNode = pHead;
	while (pTmpNode)
	{
		if (pTmpNode->value == node->value)
			return pTmpNode;

		pTmpNode = pTmpNode->next;
	}

	return NULL;
}

Node* SList::GetPreviousNode( Node* node )
{
	if (!pHead || !pHead->next)
		return NULL;

	Node* pNode = pHead;
	while (pNode && pNode->next)
	{
		if(pNode->next->value == node->value)
			return pNode;

		pNode = pNode->next;
	}

	return NULL;
}

bool SList::DeleteList()
{
	if(!pHead)
		return true;

	Node* pTmpNode = pHead;
	while (pTmpNode)
	{
		Node* pDelNode = pTmpNode;

		pTmpNode = pTmpNode->next;

		delete pDelNode;
		pDelNode = NULL;

		nSize--;
	}

	if (nSize != 0)
	{
		return false;
	}

	return true;
}

bool SList::isEmpty()
{
	return pHead == NULL;
}

bool SList::AddElement( Node* node )
{
	Node* pNewNode = CreateNewNode(node);
	if(!pNewNode)
		return false;

	if(pHead == NULL)
	{
		pHead = pNewNode;
		pLast = pNewNode;

		nSize++;

		return true;
	}

	pLast->next = pNewNode;
	pLast = pNewNode;

	nSize++;

	return true;
}

bool SList::InsertElement( Node* node, Node* position )
{
	Node* pos = GetNode(position);
	if(!pos)
		return false;

	Node* pNewNode = CreateNewNode(node);
	if(!pNewNode)
		return false;

	pNewNode->next = pos->next;
	pos->next = pNewNode;

	nSize++;

	return true;
}

bool SList::DeleteElement( Node* node )
{
	Node* pNode = GetNode(node);
	if(!pNode)
		return false;

	Node* pPreviousNode = GetPreviousNode(node);
	if(!pPreviousNode)
		return false;

	pPreviousNode->next = pNode->next;

	delete pNode;
	pNode = NULL;

	nSize--;

	return true;
}

int SList::GetListSize()
{
	return nSize;
}

Node* SList::GetElement( ElementType element )
{
	if(!pHead)
		return NULL;

	Node* pTmpNode = pHead;
	while (pTmpNode)
	{
		if (pTmpNode->value == element)
			return pTmpNode;

		pTmpNode = pTmpNode->next;
	}

	return NULL;
}

void SList::PrintList()
{
	if(!pHead)
	{
		std::cout << "Empty List !\n" ;
		return;
	}

	Node* node = pHead;
	while (node)
	{
		std::cout << node->value << "  ";

		node = node->next;
	}
}



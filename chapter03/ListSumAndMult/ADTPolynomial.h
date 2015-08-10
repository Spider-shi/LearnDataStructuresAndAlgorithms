#ifndef __ADT_POLYNOMIAL_H__
#define __ADT_POLYNOMIAL_H__

#include <iostream>

using std::cout;
using std::endl;

/*
* 单链表形式 多项式 操作例程
*/

typedef struct Node* PtrToNode;

struct Node
{
	int Coefficient;
	int Exponent;
	PtrToNode Next;

	Node(int coef, int exponent) : Next(NULL)
	{
		Coefficient = coef;
		Exponent = exponent;
	}
};

typedef Node* Polynomial;
/*
* 输出链表
*/
inline void PrintList(Polynomial head)
{
	if(!head)
		std::cout << "empty List!\n";

	Polynomial pTmpNode = head;
	while(pTmpNode)
	{
		std::cout << "Coef : " << pTmpNode->Coefficient << "\tExponent : " << pTmpNode->Exponent << std::endl;

		pTmpNode = pTmpNode->Next;
	}
}
/*
* 创建链表
*/
inline Polynomial CreateList(int coef, int exponent)
{
	Polynomial head = new Node(coef, exponent);
	if(head)
		return head;

	return NULL;
}

/*
* 添加节点
*/
inline bool AddNode(int coef, int exponent, Polynomial head)
{
	if(!head)
		return false;

	Polynomial newNode = new Node(coef, exponent);
	if(!newNode)
		return false;

	Polynomial lastNode = head;
	while(lastNode->Next)
	{
		lastNode = lastNode->Next;
	}

	lastNode->Next = newNode;
	return true;
}

inline bool DeleteList(Polynomial head)
{
	if(!head)
		return true;
	
	Polynomial pDelNode = head;
	head = head->Next;

	delete pDelNode;
	pDelNode = NULL;

	while (head)
	{
		pDelNode = head;
		head = head->Next;

		delete pDelNode;
		pDelNode = NULL;
	}

	return true;
}
/*
*	两个多项式求和
*/
inline void Sum(Polynomial Poly1, Polynomial Poly2)
{
	if(!Poly1 || !Poly2)
		return;

	Polynomial polyTmp1 = Poly1;
	Polynomial polyTmp2 = Poly2;

	while (polyTmp1)
	{
		while (polyTmp2)
		{
			if (polyTmp1->Exponent == polyTmp2->Exponent)
			{
				polyTmp1->Coefficient += polyTmp2->Coefficient;
				break;
			}
			if (!polyTmp2->Next)
			{
				AddNode(polyTmp2->Coefficient, polyTmp2->Exponent, Poly1);
			}
			polyTmp2 = polyTmp2->Next;
		}

		polyTmp1 = polyTmp1->Next;
	}

}

/*
*	两个多项式求积
*/
inline Polynomial Power(Polynomial Poly1, Polynomial Poly2)
{
	if(!Poly1 || !Poly2)
		return NULL;

	Polynomial pPoly1Head = Poly1;
	Polynomial pPoly2Head = Poly2;

	Polynomial pNewList = NULL;

	while (Poly1)
	{
		while (Poly2)
		{
			int nCoefficient = Poly1->Coefficient * Poly2->Coefficient;
			int nExponent = Poly1->Exponent * Poly2->Exponent;

			if (!pNewList)
			{
				pNewList = CreateList(nCoefficient, nExponent);
			}
			else
			{
				AddNode(nCoefficient, nExponent, pNewList);
			}

			Poly2 = Poly2->Next;
		}

		Poly1 = Poly1->Next;
		Poly2 = pPoly2Head;
	}

	return pNewList;
}
#endif
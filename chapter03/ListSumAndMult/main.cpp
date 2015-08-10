#include <iostream>
#include "ADTPolynomial.h"

int main()
{
	Polynomial pHead = CreateList(0,0);

	AddNode(1, 1, pHead);
	AddNode(1, 2, pHead);
	PrintList(pHead);


	Polynomial pHead2 = CreateList(0,0);

	AddNode(1, 1, pHead2);
	AddNode(1, 2, pHead2);
	PrintList(pHead2);


	std::cout << "-----------------------\n\n";
	PrintList(Power(pHead, pHead2));


	//DeleteList(pHead);
	return 0;
}
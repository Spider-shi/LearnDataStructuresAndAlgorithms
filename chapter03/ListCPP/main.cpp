#include <iostream>
#include "SList.h"

void AddElement(SList& slist)
{
	static int value = 0;

	Node node(value++);
	slist.AddElement(&node);
}

int main()
{
	SList sList;

	sList.PrintList();

	int count = 10;
	while(count--)
	{
		AddElement(sList);
	}

	std::cout << "insert a elelment at pos 8" << std::endl;
	Node pos(8);
	Node node(101);

	sList.InsertElement(&node, &pos);
	sList.PrintList();
	std::cout << std::endl << "The Size : " << sList.GetListSize() << std::endl;

	std::cout << std::endl;
	std::cout << "delete a element node 8" << std::endl;
	Node del(8);
	sList.DeleteElement(&node);

	sList.PrintList();
	std::cout << std::endl << "The Size : " << sList.GetListSize() << std::endl;
	return 0;
}


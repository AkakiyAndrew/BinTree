#include <iostream>
#include <conio.h>
#include "Tree.h"

int main()
{
	Tree base(5);
	Tree* ptr_base = &base;

	int nums[] = {1,4,6,7};

	for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
	{
		ptr_base->addElement(nums[i]);
	}

	int option = 0;

	while (option !=4)
	{
		system("cls");
		ptr_base->showElements();

		std::cout << " Choose option:\n 1 - Add new element\n 2 - Remove item\n 3 - Find item\n 4 - Exit from program\n";
		int num;
		Tree* element;
		bool res = false;
		std::cin >> option;

		switch (option)
		{
		case 1:
			std::cout << " Enter number: ";
			std::cin >> num;
			if (ptr_base->addElement(num) != nullptr) std::cout << " Item created!\n";
			else std::cout << " Element already exist!\n";
			_getch();
			break;
		case 2:
			std::cout << " Enter number: ";
			std::cin >> num;
			res = ptr_base->removeElement(num, ptr_base);
			if (res) std::cout << " Element removed succesfully!";
			else std::cout << " Element doesn`t exist!\n";
			_getch();
			break;
		case 3: 
			std::cout << " Enter number: ";
			std::cin >> num;
			element = ptr_base->seekElement(num);
			if (element != nullptr) std::cout << " Here address of your element: "<< element <<"\n";
			else std::cout << " Element doesn`t exist!\n";
			_getch();
			break;
		case 4:
			break;
		}
	}

	return 0;
}
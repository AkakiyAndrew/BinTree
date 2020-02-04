#include "Tree.h"
#include <iostream>

Tree::Tree(int num)
{
	data = num;
	leftTree = nullptr;
	rightTree = nullptr;
}

Tree::Tree(Tree& object)
{
	data = object.data;
	leftTree = object.leftTree;
	rightTree = object.rightTree;
}

Tree::Tree::~Tree()
{
}

Tree* Tree::addElement(int num)
{	//���������� ������ ����� num, nullptr ���� ����� ��� �������
	Tree* result = nullptr;		//������ �� ����������� ������� ������������. ����� ��?

	if (this->data < num)
	{
		if (this->rightTree == nullptr)
		{
			result = new Tree(num);
			this->rightTree = result;
		}
		else result = this->rightTree->addElement(num);
	}
	if(this->data > num)
	{
		if (this->leftTree == nullptr)
		{
			result = new Tree(num);
			this->leftTree = result;
		}
		else result = this->leftTree->addElement(num);
	}

	return result;
}

Tree* Tree::seekElement(int num)
{
	//����� ������ �� � ������
	Tree* result = nullptr;
	if (this->data < num && this->rightTree !=nullptr) result = this->rightTree->seekElement(num);
	if (this->data > num && this->leftTree !=nullptr) result = this->leftTree->seekElement(num);
	if (this->data == num) result = this;
	return result; //���� ������ �� ������� - ������� �������� ���������
}

bool Tree::removeElement(int num, Tree*& parent)
{
	bool result = false;
	
	//�������� ������, ��������� - ����� ������ � ������ �� � ��������
	if (this->data < num && this->rightTree != nullptr) result = this->rightTree->removeElement(num, this->rightTree);
	if (this->data > num && this->leftTree != nullptr) result = this->leftTree->removeElement(num, this->leftTree);
	if (this->data == num)
	{
		if (this->leftTree == nullptr && this->rightTree == nullptr) //���� ��� ����� ������ ����� ��� ���������, ������ �������� �� �� ����������
		{
			parent = nullptr;
			return true;
		}
		if (this->leftTree == nullptr)	//���� ������ ����� ����� ����� - ������ "�������" �� ��������� ��������
		{
			parent = this->rightTree;
			return true;
		}
		if(this->rightTree == nullptr)	//���� ������ ������ - "�������" ����� ��������
		{
			parent = this->leftTree;
			return true;
		}
		//���� ��� ����� ���������:
		if (this->rightTree->leftTree == nullptr)	//���� ����� ����� ������ ����� ������:
		{
			//������ ������ ����� ������ ������� �� ����� ���������
			parent = this->rightTree;
			this->rightTree->leftTree = this->leftTree;
			return true;
		}
		else										//���� �� ��� - ���� ����� ����� ������ ������ �����
		{
			Tree* mostLeft = this->rightTree;
			Tree* leftParent = nullptr;
			while (mostLeft->leftTree != nullptr)
			{
				leftParent = mostLeft;
				mostLeft = mostLeft->leftTree; //��������� ������ ����� ����� ������ � � ��������
			}
			this->data = mostLeft->data;
			leftParent->removeElement(mostLeft->data, leftParent);
			return true;
		}
	}
	return result;
}

void Tree::showElements()
{
	static int level = 0;
	std::cout << "\t" << data << ":\n";
	if (leftTree == nullptr)
	{
		for (int i = 0; i <= level; i++) std::cout << "\t";
		std::cout << "left: " << "Empty\n";

	}
	else
	{
		++level;
		for(int i = 0; i < level; i++) std::cout << "\t";
		std::cout << "left: ";
		leftTree->showElements();
	}

	if (rightTree == nullptr) 
	{
		for (int i = 0; i <= level; i++) std::cout << "\t";
		std::cout << "right: " << "Empty\n";

	}
	else 
	{
		++level;
		for (int i = 0; i < level; i++) std::cout << "\t";
		std::cout << "right: ";
		rightTree->showElements();
	}
	if(level>0) --level; 
}
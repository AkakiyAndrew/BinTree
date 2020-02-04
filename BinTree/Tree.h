#pragma once

class Tree
{
private:
	int data;
	Tree* leftTree, * rightTree;
public:

	Tree(int num);
	Tree(Tree &object);
	~Tree();

	Tree* addElement(int num);
	Tree* seekElement(int num);
	bool removeElement(int num, Tree*& parent);
	void showElements();

	//днаюбхрэ бшбнд б онрнй!
};


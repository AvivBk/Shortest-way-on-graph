#include "Menu.h"


namespace Huffman
{
	Menu::Menu() 
	{
		int bits = 0;
		_t = new BS_Tree();
		string s = "";
		int idx = 0;
		_t->buildTreeFromFile();
		if (checkIfOnlyOne())
			s = "0";
		TreeNode* arr = new TreeNode[_t->getTreeSize()];
		LoadIntoArray(arr,_t->getRoot(), idx);
		_arr.HeapAlloction(_t->getTreeSize());
		_arr.BuildHeap(arr, _t->getTreeSize());
		HuffmanCode(_t->getTreeSize());
		_arr.DeleteMin()->PrintHuffmanNode(s,arr, _t->getTreeSize());
		ClacWieght(arr, _t->getTreeSize());
	}

	bool Menu::checkIfOnlyOne()
	{
		if (_t->getTreeSize() == 1) //checks if there is only one char
		{
			return true;
		}
		return false;
	}

	Menu:: ~Menu()
	{
		if (_t != nullptr)
			delete _t;
	
	}

	void Menu::ClacWieght(TreeNode* arr, int size) const 
	{

		int Wieghtcount = 0;
		for (int i = 0; i < size; ++i)
			Wieghtcount += arr[i].getNodeCount();

		cout << "\n Encoded file weight : " << Wieghtcount << endl;
	} 

	void Menu::LoadIntoArray(TreeNode* arr,TreeNode* tnode, int& idx)
	{
		if (tnode == nullptr)
			return;

		if (tnode->leftNode() != nullptr)
			LoadIntoArray(arr,tnode->leftNode(), idx);

		arr[idx++].setItem(tnode->getNodeChar(), tnode->getNodeCount());

		if (tnode->rightNode() != nullptr)
			LoadIntoArray(arr,tnode->rightNode(), idx);

	}

	void Menu::HuffmanCode(int size)
	{
		TreeNode* tnode = nullptr;
		for (int i = 1; i < size; ++i)
		{	
			tnode = new TreeNode();
			tnode->setLeft(_arr.DeleteMin());
			tnode->setRight(_arr.DeleteMin());
			int count = tnode->leftNode()->getNodeCount() + tnode->rightNode()->getNodeCount();
			tnode->setCountHuffman(count);
			_arr.Insert(*tnode);
		}
	}

}
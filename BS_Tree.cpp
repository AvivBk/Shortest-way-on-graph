#include "BS_Tree.h"

namespace Huffman {

	void BS_Tree::buildTreeFromFile()
	{
		char curr_c;
		ifstream file = getFile();
		while (file >> std::noskipws >> curr_c) //read including spaces
		{
			Insert(curr_c);
		}
		file.close();
	}

	ifstream BS_Tree::getFile()
	{
		ifstream file;
		string fname;
		cout << "enter file's name: " << endl;
		cin >> fname;
		fname += ".txt"; //adds a txt, change at will
		file.open(fname);
		if (!file)
		{
			cout << "no such file was found" << endl;
			exit(1);
		}
		return file;
	}

	BS_Tree::~BS_Tree()
	{
		deleteTree(_root); //calls a recursive function to delete the tree
		_root = nullptr;
	}

	//deletes a tree recursivly
	void BS_Tree::deleteTree(TreeNode* node)
	{
		if (node == nullptr)
			return;

		deleteTree(node->leftNode());
		deleteTree(node->rightNode());

		delete node;
	}

	void BS_Tree::Insert(const char c)
	{
		TreeNode** curr = &_root; //starting at root
		while (*curr != nullptr)
		{
			if ((*curr)->getNodeChar() == c)
			{
				(*curr)->apendCount(1); //if char already found, count to frequncy + 1
				return;
			}
			if (c > (*curr)->getNodeChar())
				curr = &(*curr)->rightNodeRef();
			else
				curr = &(*curr)->leftNodeRef();
		}
		TreeNode* new_pair = new TreeNode(c);
		*curr = new_pair; //if not found, creates a new Node and insert it to currect spot
		++_size;
	}

	TreeNode* BS_Tree::find(const char c) const
	{
		TreeNode* curr = _root;
		while (curr != nullptr)
		{
			if (curr->getNodeChar() == c)
			{
				return curr;
			}
			if (c > curr->getNodeChar())
				curr = curr->rightNodeRef();
			else
				curr = curr->leftNodeRef();
		}
		cout << "no such char was found" << endl;
		return nullptr;
	}

	TreeNode* BS_Tree::findParent(const char c) const
	{
		TreeNode* curr = _root;
		while (curr != nullptr)
		{
			if (_root->getNodeChar() == c)
			{
				return nullptr;
			}
			if (curr->rightNodeRef() != nullptr)
			{
				if (curr->rightNodeRef()->getNodeChar() == c)
					return curr;
			}
			if (curr->leftNodeRef() != nullptr)
			{
				if (curr->leftNodeRef()->getNodeChar() == c)
					return curr;
			}
			if (c > curr->getNodeChar())
				curr = curr->rightNodeRef();
			else
				curr = curr->leftNodeRef();
		}
		cout << "no such parent found" << endl;
		exit(1);
	}

	bool BS_Tree::DeleteRoot()
	{
		int numberOfChildren = _root->getNumOfChildren();
		TreeNode* right = _root->rightNodeRef();
		TreeNode* left = _root->leftNodeRef();
		if (right != nullptr)
		{
			Swap(_root, right);
			return false; //right
		}
		else if (left != nullptr)
		{
			Swap(_root, left);
			return true; //left;
		}
		cout << "not a possible rout" << endl;
		exit(1);
	}

	//this function splits into 3 different cases just like learned in class
	void BS_Tree::Delete(const char c)
	{
		TreeNode* curr = _root;
		TreeNode* parent = findParent(c);

		TreeNode* toDelete = find(c);
		TreeNode* maximum;
		if (parent == nullptr) //we are deleting the root
		{
			if (_root->rightNode() == nullptr && _root->leftNode() == nullptr)
			{
				delete _root;
				return;
			}
			if (DeleteRoot())
			{
				parent = toDelete;
				toDelete = toDelete->leftNodeRef();
			}
			else
			{
				parent = toDelete;
				toDelete = toDelete->rightNodeRef();
			}
		}
		int numberOfChildren = toDelete->getNumOfChildren();
		if (numberOfChildren == 0) //deleting a leaf
		{
			if (parent->rightNodeRef() != nullptr)
			{
				if (parent->rightNodeRef() == toDelete)
				{
					parent->setRight(nullptr);
				}
			}
			else
				parent->setLeft(nullptr);
		}
		if (numberOfChildren == 1) //deleting a node with one child
		{
			if (parent->rightNodeRef() == toDelete)
			{
				if (toDelete->leftNodeRef() != nullptr)
					parent->setRight(toDelete->leftNodeRef());
				else if (toDelete->rightNodeRef() != nullptr)
					parent->setRight(toDelete->rightNodeRef());
			}
			else if (parent->leftNodeRef() == toDelete)
			{
				if (toDelete->leftNodeRef() != nullptr)
					parent->setLeft(toDelete->leftNodeRef());
				else if (toDelete->rightNodeRef() != nullptr)
					parent->setLeft(toDelete->rightNodeRef());
			}
		}
		else if (numberOfChildren == 2) //deleting a node with 2 children
		{
			maximum = toDelete->leftNodeRef();
			while (maximum->leftNodeRef() != nullptr)
			{
				maximum = maximum->rightNodeRef();
			}
			swap(toDelete, maximum);
			toDelete->setLeft(maximum->leftNodeRef());
			delete maximum;
		}

		delete toDelete;
		--_size;
	}

	//recive two tree nodes and swap their items
	void BS_Tree::Swap(TreeNode*& a, TreeNode*& b)
	{
		Item item_a = a->getNodeData();
		Item item_b = b->getNodeData();
		a->setItem(item_b);
		b->setItem(item_a);
	}
	void BS_Tree::printBS_Tree()
	{
		if (_root != nullptr)
			_root->InOrder();
	}

}
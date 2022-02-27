#pragma once
#include "TreeNode.h"
#include <fstream>

namespace Huffman
{
	class BS_Tree
	{
	private:
		TreeNode* _root;
		int _size = 0;
	public:
		//CTOR  DTOR
		BS_Tree() : _root(nullptr) {}
		~BS_Tree();
		void deleteTree(TreeNode* node);
		//returns the root
		TreeNode* getRoot() const { return _root; }
		//returns the tree size
		int getTreeSize() const { return _size; }
		//grabs a file by name. the function adds txt as defult, change at will
		ifstream getFile();
		//builds a search tree from a file with "char" as key and "frequency" as value
		void buildTreeFromFile();
		//finds a specific TreeNode by char
		TreeNode* find(const char) const;
		//finds a node's parents by char(nullptr if root)
		TreeNode* findParent(const char c) const;

		//inserts a char to the search tree
		void Insert(const char);
		//delete a char from the node tree
		void Delete(const char);
		//deletes the root
		bool DeleteRoot();
		//swapping two treeNodes items
		static void Swap(TreeNode*& a, TreeNode*& b);
		//printing a search tree
		void printBS_Tree();


	};


}

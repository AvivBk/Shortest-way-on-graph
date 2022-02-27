#pragma once
#include <iostream>
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

namespace Huffman {
	class TreeNode
	{
	private:
		Item _data;
		TreeNode* _left = nullptr;
		TreeNode* _right = nullptr;

	public:

		//Ctors and Dtors
		TreeNode();
		TreeNode(int, const char, TreeNode*, TreeNode*);
		TreeNode(int count, TreeNode* left, TreeNode* right);
		TreeNode(Item&);
		TreeNode(const char ch);
		TreeNode(const TreeNode&);
		~TreeNode() {}

		//setting left and right ptrs of a treeNode
		void setNodePtrs(TreeNode* left, TreeNode* right);
		//set the left of a tree node
		void setLeft(TreeNode* node) { _left = node; }
		//set the right of a tree node
		void setRight(TreeNode* node) { _right = node; }

		//adds x to a count 
		void apendCount(int x) { _data.append(x); }
		//returns a refrence to the left of a tree node
		TreeNode*& leftNodeRef() { return _left; }
		//returns a refrence to the right of a tree node
		TreeNode*& rightNodeRef() { return _right; }

		//returns the left of a tree node
		TreeNode* leftNode() const { return _left; }
		//returns the right of a tree node
		TreeNode* rightNode() const { return _right; }

		//sets a char and a frequency of an item
		void setItem(const char m, int num) { _data.set(m, num); }
		//set an item by another item
		void setItem(Item& other) { _data.cpy(other); }
		//set the char of an item
		void setChar(const char m) { _data.setChar(m); }
		//sets the frequency of an item
		void setCount(int num) { _data.setCount(num); }
		//sets the frequency of a connecting node to the sum of two frequencies
		void setCountHuffman(int num) { _data.setCountHuffman(num); }
		//sets the variables of a huffman tree node
		void setHuffman( int , TreeNode*, TreeNode*);
		//returns the char of an item
		char getNodeChar() const { return (_data.getChar()); }
		//returns a refrence to an item
		Item& getNodeData()  { return _data; }
		//returns the frequency of an item
		int getNodeCount() const { return (_data._count); }
		//returns the number of children a tree node has
		int getNumOfChildren() const;
		//prints in order as learned in class
		void InOrder();

		//returns the type of a node from a huffman tree
		bool isHuffmanNode();
		//prints all the chars by huffman code
		void PrintHuffmanNode(string s, TreeNode*, int  );
		//calculates the weigh of a huffman code 
		void Clac(TreeNode* arr, const char key, int , int);
		friend class B_Tree;
	};
}

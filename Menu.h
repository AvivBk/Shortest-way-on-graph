#pragma once
#include "Heap.h"
#include "BS_Tree.h"
#include <string>

namespace Huffman {

	class Menu
	{
	private:
		BS_Tree* _t;
		Heap _arr;
	public:
		Menu();
		~Menu();
		
		// makes an hoffman code
		void HuffmanCode(int size);
		// loads to array from search tree
		void LoadIntoArray(TreeNode*, TreeNode* tnode, int& idx); 
		// calculate the weight in bits of the hoffman code
		void ClacWieght(TreeNode* arr, int size) const; 
		//checks if there is only one char in the input
		bool checkIfOnlyOne();

	};

}

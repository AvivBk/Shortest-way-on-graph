#pragma once
#include <stdlib.h>
#include "TreeNode.h"

namespace Huffman
{


	class Heap
	{
	private:
		TreeNode* _heap;
		int _maxSize;
		int _heapSize;
		bool _allocated;

		static int Left(int node) { return (2 * node + 1); } //returns index to left
		static int Right(int node) { return (2 * node + 2); } //returns index to right
		static int Parent(int node) { return (node - 1) / 2; } //returns index to parent	
		void FixHeap(int node); //the algorithem fix heap as learned in class
	public:

		//CTOR
		Heap();
		//allocates memory for heap
		void HeapAlloction(int maxSize);
		//DTOR
		~Heap();

		//a method that prepears the forest before huffman code
		void BuildHeap(TreeNode* arr, int size);
		//inserts to a huffman tree
		void Insert(TreeNode& toAdd);
		//swaps between two items from an array by indexes a and b
		void Swap(int  a, int b);
		//returns the minimum from the heap
		TreeNode* Min() const { return &_heap[0]; }
		//deletes the minimum from the heap and deletes it
		TreeNode* DeleteMin();
		//prints the heap
		void PrintHeap() const;

	};

}

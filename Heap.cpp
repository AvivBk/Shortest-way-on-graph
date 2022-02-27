#include "Heap.h"

namespace Huffman
{

	Heap::Heap() : _heap(nullptr), _maxSize(0), _heapSize(0), _allocated(false)
	{
	}


	void Heap::BuildHeap(TreeNode* arr, int size)
	{
		_heapSize = _maxSize = size;
		_allocated = false;
		for (int i = 0; i < size; ++i) {
			_heap[i] = arr[i];
			_heap[i].setItem(arr[i].getNodeChar(), arr[i].getNodeCount());
		}
		_allocated = false;
		for (int j = size / 2 - 1; j >= 0; --j)
			FixHeap(j);
	}

	void Heap::HeapAlloction(int maxSize) 
	{ 
		if (_heap == nullptr)
			delete _heap;
		_heap = new TreeNode[maxSize];
		_maxSize = maxSize;
		_heapSize = 0;
		_allocated = true;
	}

	Heap::~Heap()
	{
		if (_allocated)
			delete[] _heap;
		_heap = nullptr;
	}

	void Heap::FixHeap(int node)
	{
		int min;
		int left = Left(node);
		int right = Right(node);
		if ((left < _heapSize) && (_heap[left].getNodeCount() < _heap[node].getNodeCount()))
			min = left;
		else  min = node;
		if ((right < _heapSize) && (_heap[right].getNodeCount() < _heap[min].getNodeCount()))
			min = right;

		if (min != node) {
			Swap(node, min);
			FixHeap(min);
		}
	}
	
	
	void Heap:: Swap(int  a, int b)
	{
		TreeNode temp = _heap[a];
		_heap[a] = _heap[b];
		_heap[b] = temp;
		temp.setNodePtrs(nullptr, nullptr);

	}

	TreeNode* Heap::DeleteMin()
	{
		if (_heapSize < 1)
			return nullptr;

		TreeNode* min = new TreeNode(_heap[0]);


		_heapSize--;
		_heap[0].setItem(_heap[_heapSize].getNodeChar(), _heap[_heapSize].getNodeCount());
		_heap[0].setNodePtrs(_heap[_heapSize].leftNode(), _heap[_heapSize].rightNode());
		FixHeap(0);
		return(min);
	}

	//inserts to a huffman tree just like learned in class
	void Heap::Insert(TreeNode& toAdd)
	{
		if (_heapSize == _maxSize) {
			exit(1);
		}
		int idx = _heapSize;
		_heapSize++;
		while ((idx > 0) && (_heap[Parent(idx)].getNodeCount() > toAdd.getNodeCount())) {
			_heap[idx].setItem(_heap[Parent(idx)].getNodeChar(), _heap[Parent(idx)].getNodeCount());
			_heap[idx].setNodePtrs(_heap[Parent(idx)].leftNode(), _heap[Parent(idx)].rightNode());
			idx = Parent(idx);
		}
		_heap[idx].setItem(toAdd.getNodeChar(), toAdd.getNodeCount());
		_heap[idx].setNodePtrs(toAdd.leftNode(), toAdd.rightNode());
	}
	
	void Heap::PrintHeap() const
	{
		for (int i = 0; i < _heapSize; ++i) {
			cout << "Char :  " << _heap[i].getNodeChar() << "  Frequency :  " << _heap[i].getNodeCount() << endl;
		}

	}



}

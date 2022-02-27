#include "TreeNode.h"


namespace Huffman {


	TreeNode::TreeNode() : _data(), _left(nullptr), _right(nullptr)
	{
	}

	TreeNode::TreeNode(const char ch) : _data(ch), _left(nullptr), _right(nullptr)
	{
	}

	TreeNode::TreeNode(int count, TreeNode* left, TreeNode* right)
		: _data(count), _left(nullptr), _right(nullptr)
	{
	}

	TreeNode::TreeNode(int count, const char type, TreeNode* left, TreeNode* right)
		: _data(count, type), _left(left), _right(right)
	{
	}

	TreeNode::TreeNode(Item& data) : TreeNode(data.getCount(), data.getChar(), nullptr, nullptr)
	{
	}

	TreeNode::TreeNode(const TreeNode& other)
		: TreeNode(other.getNodeCount(), other.getNodeChar(), other.leftNode(), other.rightNode())
	{
	}

	void TreeNode::setNodePtrs(TreeNode* left, TreeNode* right)
	{
		_left = left;
		_right = right;
	}

	int TreeNode::getNumOfChildren() const
	{
		int count = 0;
		if (_left != nullptr)
			count++;
		if (_right != nullptr)
			count++;
		return count;
	}

	void TreeNode::InOrder()
	{
		if (_left != nullptr)
			_left->InOrder();
		cout << _data.getChar() << endl;
		if (_right != nullptr)
			_right->InOrder();
	}

	void TreeNode::PrintHuffmanNode(string s, TreeNode* arr, int size)
	{
		if (_left != nullptr) {
			_left->PrintHuffmanNode(s.append("0"), arr, size);
			if(!s.empty())
				s.pop_back();
		}

		if (isHuffmanNode()) {
			cout << getNodeChar() << "   means :   " << s << endl;
			Clac(arr, getNodeChar(), size, s.length());
		}
		if (_right != nullptr) {
			_right->PrintHuffmanNode(s.append("1"), arr, size);
			if (!s.empty())
				s.pop_back();
		}
		
	}

	void TreeNode::Clac(TreeNode* arr, const char key, int size, int bits) {

		for (int i = 0; i < size; ++i) {
			if (arr[i].getNodeChar() == key)
				arr[i].setCount(arr[i].getNodeCount() * bits);
		}

	}
	void TreeNode::setHuffman(int count, TreeNode* left, TreeNode* right) 
	{
		_left = left;
		_right = right;
		_data.setCountHuffman(count);
	}

	bool TreeNode::isHuffmanNode()
	{
		if (_left == nullptr && _right == nullptr && !_data.isSigned()) return true;
		else return false;
	}
}
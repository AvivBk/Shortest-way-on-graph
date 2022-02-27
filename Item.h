#pragma once

struct Item
{
	//Variables
	int _count; //frequency of a char
	char _type = SEPARATOR; //the char
	static const char SEPARATOR = 31; //equal to no char

	Item() : _count(0), _type(SEPARATOR) {}
	Item(int key, char type) : _count(key), _type(type) {}
	Item(const char data) : _count(1), _type(data) {}
	Item(int num) : _count(num), _type(SEPARATOR) {}

	//sets the count of an item node that connects two char(leaves) nodes but doesnt contain a char
	void setCountHuffman(int num) { _count = num; _type = SEPARATOR; }
	//sets the count of an item to num
	void setCount(int num) { _count = num;  }
	//sets the char of an item to ch
	void setChar(const char ch) { _type = ch; }
	//adds to count by x
	void append(int x) { _count += x; }
	//returns the item's char
	const char getChar() const { return _type; }
	//returns the item's count
	const int  getCount() const  { return _count; }
	//sets a char and a num to an item
	void set(const char ch, int num) { _type = ch; _count = num; }
	//copys from one item to another
	void cpy(Item& other) { _type = other.getChar(); _count = other.getCount(); }
	//return if the item we are checking is a connector or a leaf
	bool isSigned() { return (_type == SEPARATOR); }

};
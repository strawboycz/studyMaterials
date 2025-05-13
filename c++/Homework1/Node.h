#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
template <typename T>
class Node
{
private:
	T value;
	Node<T>* left;
	Node<T>* right;
public:
	Node(T value) : value(value), left(nullptr), right(nullptr) {}

	void createNext(T value)
	{
		if (value < this->value)
		{
			if (left == nullptr)
			{
				left = new Node(value);
			}
			else
			{
				left->createNext(value);
			}
		}
		else
		{
			if (right == nullptr)
			{
				right = new Node<T>(value);
			}
			else
			{
				right->createNext(value);
			}
		}
	}
	string toString()
	{
		ostringstream ss;
		ss << "[" << this->value;
		ss << ":";
		ss << (this->left != nullptr ? left->toString() : "X");
		ss << ";";
		ss << (this->right != nullptr ? right->toString() : "X");
		ss << "]";
		return ss.str();
	}

};

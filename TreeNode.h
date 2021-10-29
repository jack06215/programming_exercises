#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T> 
class Tree;

template <typename T>
class TreeNode
{
	friend class Tree<T>;

public:
	TreeNode(T); 
	T getData(); //returns data stored in node

private:
	T data;
	TreeNode* leftPtr; //pointer to left child node of node
	TreeNode* rightPtr; //pointer to right child node of node
};

template <typename T>
TreeNode<T>::TreeNode(T dataIn)
{
	data = dataIn;
	leftPtr = 0; //pointer to left and right child nodes are initilized to NULL
	rightPtr = 0;
}

template <typename T>
T TreeNode<T>::getData()
{
	return data;
}

#endif

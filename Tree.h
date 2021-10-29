#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

#include "TreeNode.h"

template <typename T>
class Tree
{
public:
	Tree();
	void insertNewNode(T); //inserts new node in the tree
	void preOrderPrint(); //prints out tree in the order in which it was entered
	void inOrderPrint(); //prints out tree in accending order
	void postOrderPrint(); //prints out the tree after the order
	TreeNode<T>* search(T); //search for node thats data equals the search key and returns the pointer to that node

private:
	TreeNode<T> *rootPtr;
	bool isEmpty();

	//utility functions to make the insert, print, and search functions more understandable
	void insertNewNodeUtility(TreeNode<T>**,T);
	void preOrderPrintUtility(TreeNode<T>*);
	void inOrderPrintUtility(TreeNode<T>*);
	void postOrderPrintUtility(TreeNode<T>*);
	TreeNode<T>* searchUtility(TreeNode<T>*,T);
};

template <typename T>
Tree<T>::Tree()
{
	rootPtr = 0;
}

template <typename T>
void Tree<T>::insertNewNode(T dataIn)
{
	insertNewNodeUtility(&rootPtr, dataIn); //calls insert new node function passing refernce of the root node and the data to be inserted in the new node
}

template <typename T>
void Tree<T>::insertNewNodeUtility(TreeNode<T>** temp, T dataIn)
{
	if(*temp == 0) //if node is null create a new node with input data
		*temp = new TreeNode<T>(dataIn);
	else
	{
		if(dataIn < (*temp)->data) //if input data is less than data in current node
			insertNewNodeUtility(&((*temp)->leftPtr),dataIn); //recursive function call with current node's left child as input leaf
		else 
		{
			if(dataIn > (*temp)->data) //if input data is greater than data in current node
				insertNewNodeUtility(&((*temp)->rightPtr),dataIn); //recursive function call with current node's right child as input leaf
			else //if input data is equal to data in current node
				cout << dataIn << " is a duplicate value " << endl; //duplicate values ignored
		}
	}
}

template <typename T>
void Tree<T>::preOrderPrint()
{
	preOrderPrintUtility(rootPtr); 
}

template <typename T>
void Tree<T>::preOrderPrintUtility(TreeNode<T>* temp)
{
	if(temp != 0)
	{
		cout << temp->data << ' '; //process node
		preOrderPrintUtility(temp->leftPtr); //recursive traversal of left subtree
		preOrderPrintUtility(temp->rightPtr); //recursive traversal of right subtree
	}
}


template <typename T>
void Tree<T>::inOrderPrint()
{
	inOrderPrintUtility(rootPtr);
}

template <typename T>
void Tree<T>::inOrderPrintUtility(TreeNode<T>* temp)
{
	if(temp != 0)
	{
		inOrderPrintUtility(temp->leftPtr); //recursive traversal of left subtree
		cout << temp->data << ' '; //process node
		inOrderPrintUtility(temp->rightPtr); //recursive traversal of right subtree
	}
}


template <typename T>
void Tree<T>::postOrderPrint()
{
	postOrderPrintUtility(rootPtr);
}

template <typename T>
void Tree<T>::postOrderPrintUtility(TreeNode<T>* temp)
{
	if(temp != 0)
	{
		postOrderPrintUtility(temp->leftPtr); //recursive traversal of left subtree
		postOrderPrintUtility(temp->rightPtr); //recursive traversal of right subtree
		cout << temp->data << ' '; //process node
	}
}

template <typename T>
TreeNode<T>* Tree<T>::search(T key)
{
	return searchUtility(rootPtr, key);
}

template <typename T>
TreeNode<T>* Tree<T>::searchUtility(TreeNode<T>* leaf, T key)
{
	if(leaf != NULL)
	{
		if(key == leaf->data)
			return leaf;
		if(key < leaf->data)
			return searchUtility(leaf->leftPtr, key);
		else
			return searchUtility(leaf->rightPtr, key);
	}
	else
		return NULL;
}
#endif 

#pragma once
#include <iostream>

template <class T>
class AVLNode {
public:
	AVLNode(const T elem);
	~AVLNode();
	T _data;
	AVLNode<T>* _left;
	AVLNode<T>* _right;
};
template <class T>
class AVLTree {
public:
	AVLTree();
	AVLTree(AVLTree<T>&&);
	AVLTree(std::initializer_list<T>);
	AVLTree(AVLNode<T>*);
	~AVLTree();
	void ListHelper(AVLNode<T>*&);
	void insert(const T);
	void clear();
	int getHeight()const;
	void erase(const T);
	void printPreorder()const;
	void printInorder()const;
	void printPostorder()const;
	void printLevelorder()const;
	void printLevelorderIterative()const;
	bool isContain(const T)const;
	void find(T)const;
	bool isEmpty()const;
	int getRootData()const;
	int getBalance()const;
	int returnMax(T, T)const;
	T findMin()const;
	T findMax()const;
	size_t getNumOfNodes()const;
	AVLTree<T> mergeTrees(AVLTree<T>&, AVLTree<T>&);
public:
	bool operator==(const AVLTree<T>&)const;
	bool operator!=(const AVLTree<T>&)const;
	AVLTree<T>& operator=(const AVLTree<T>&);
	AVLTree<T>& operator=(AVLTree<T>&&);
	AVLTree operator+(const AVLTree&);
	AVLTree& operator+=(const AVLTree&);
	friend std::ostream& operator<<(std::ostream& stream, const AVLTree<T>& tree)
	{
		tree.printInorder();
		return stream;
	};
private:
	unsigned count;
	AVLNode<T>* root;
	AVLNode<T>* insert(const T, AVLNode<T>*);
	AVLNode<T>* left_Rotate(AVLNode<T>*&);
	AVLNode<T>* right_Rotate(AVLNode<T>*&);
	AVLNode<T>* leftright_Rotate(AVLNode<T>*&);
	AVLNode<T>* rightleft_Rotate(AVLNode<T>*&);
	AVLNode<T>* erase(const T, AVLNode<T>*);
	AVLNode<T>* copy(AVLNode<T>*)const;
	int height(AVLNode<T>*) const;
	void clear(AVLNode<T>*&);
	void printPreorder(AVLNode<T>*)const;
	void printInorder(AVLNode<T>*)const;
	void printPostorder(AVLNode<T>*)const;
	void printLevelOrder(AVLNode<T>*, int)const;
	void mergeHelper(AVLNode<T>*&);
	void insertHelper(AVLNode<T>*);
	bool contain(const T, const AVLNode<T>*)const;
	bool compare(AVLNode<T>*, AVLNode<T>*)const;
	T findMin(const AVLNode<T>*)const;
	T findMax(const AVLNode<T>*)const;
};
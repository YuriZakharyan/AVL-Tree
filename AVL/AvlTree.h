// AVL.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#ifndef _AVLTREE_
#define _AVLTREE_

#include <iostream>

template <class T>
class AVLTree {
private:
	template <class T>
	struct AVLNode {
	public:
		AVLNode(const T value) : _data(value), _left(nullptr), _right(nullptr) {}
		~AVLNode() {};

	public:
		T _data;
		AVLNode<T>* _left;
		AVLNode<T>* _right;
	};

public:
	AVLTree() : count(0), root(nullptr) {}
	AVLTree(AVLTree<T>&&);
	AVLTree(std::initializer_list<T>);
	AVLTree(const AVLTree<T>&);
	AVLTree(AVLNode<T>* newRoot) : root(newRoot) {}
	~AVLTree();

public:
	void insert(const T&);
	void erase(const T&);
	void clear();
	bool is_empty()const;
	bool is_contain(const T&)const;
	int get_height()const;
	int get_root_data()const;
	int get_balance()const;
	size_t get_num_of_nodes()const;
	void print_preorder()const;
	void print_inorder()const;
	void print_postorder()const;
	void print_levelorder()const;
	void print_levelorder_iterative()const;
	void find(T)const;
	T find_min()const;
	T find_max()const;
	AVLTree<T> merge(AVLTree<T>&, AVLTree<T>&);

public:
	bool operator==(const AVLTree<T>&)const;
	bool operator!=(const AVLTree<T>&)const;
	AVLTree<T>& operator=(const AVLTree<T>&);
	AVLTree<T>& operator=(AVLTree<T>&&);
	AVLTree<T> operator+(const AVLTree&);
	AVLTree& operator+=(const AVLTree&);
	friend std::ostream& operator<<(std::ostream& stream, const AVLTree<T>& tree)
	{
		stream << "\n";
		tree.print_levelorder_iterative();
		return stream;
	};

private:
	unsigned count;
	AVLNode<T>* root;

private:
	AVLNode<T>* insert(const T&, AVLNode<T>*&);
	AVLNode<T>* erase(const T&, AVLNode<T>*&);
	AVLNode<T>* left_rotate(AVLNode<T>*&);
	AVLNode<T>* right_rotate(AVLNode<T>*&);
	AVLNode<T>* leftright_rotate(AVLNode<T>*&);
	AVLNode<T>* rightleft_rotate(AVLNode<T>*&);
	AVLNode<T>* copy(AVLNode<T>*)const;
	int height(AVLNode<T>*) const;
	void clear(AVLNode<T>*&);
	void print_preorder(AVLNode<T>*)const;
	void print_inorder(AVLNode<T>*)const;
	void print_postorder(AVLNode<T>*)const;
	void print_levelorder(AVLNode<T>*, int)const;
	void insert(AVLNode<T>*);
	bool contain(T, const AVLNode<T>*)const;
	bool compare(AVLNode<T>*, AVLNode<T>*)const;
	void balanced(AVLNode<T>*&, const T&);
	T min(const AVLNode<T>*)const;
	T max(const AVLNode<T>*)const;
	int return_max(int, int)const;
};
#endif

// TODO: Reference additional headers your program requires here.

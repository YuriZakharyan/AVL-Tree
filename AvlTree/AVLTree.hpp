#include "AVLTree.h"
#include <iostream>
#include <queue>

template <class T>
AVLTree<T>::AVLTree(const AVLTree<T>& ob) {
	root = copy(ob.root);
}

template <class T>
AVLTree<T>::~AVLTree() {
	clear();
}

template <class T>
AVLTree<T>::AVLTree(AVLTree<T>&& tree)
{
	root = tree.root;
	tree.root = nullptr;
}

template <class T>
AVLTree<T>::AVLTree(std::initializer_list<T> newList) : root(nullptr) {	
	for (auto i = newList.begin(); i < newList.end(); i++) {
		insert(*i, root);
	}
}

template <class T>
AVLTree<T>::AVLNode<T>* AVLTree<T>::left_rotate(AVLNode<T>*& node) {
	AVLNode<T>* ll = node->_left;
	node->_left = ll->_right;
	ll->_right = node;
	return ll;
}

template <class T>
AVLTree<T>::AVLNode<T>* AVLTree<T>::right_rotate(AVLNode<T>*& node) {
	AVLNode<T>* rr = node->_right;
	node->_right = rr->_left;
	rr->_left = node;
	return rr;
}

template <class T>
AVLTree<T>::AVLNode<T>* AVLTree<T>::leftright_rotate(AVLNode<T>*& node) {
	node->_left = right_rotate(node->_left);
	node = left_rotate(node);
	return node;
}

template <class T>
AVLTree<T>::AVLNode<T>* AVLTree<T>::rightleft_rotate(AVLNode<T>*& node) {
	node->_right = left_rotate(node->_right);
	node = right_rotate(node);
	return node;
}

template <class T>
int AVLTree<T>::height(AVLNode<T>* node) const {
	if (!node){
		return 0;
	}
	return return_max(height(node->_left), height(node->_right)) + 1;
}

template <class T>
int AVLTree<T>::return_max(int a, int b) const {
	return (a > b) ? a : b;
}

template <class T>
int AVLTree<T>::get_height() const {
	return height(root);
}

template <class T>
AVLTree<T>::AVLNode<T>* AVLTree<T>::insert(const T& value, AVLNode<T>* &node) {
	if (node == nullptr) {					
		node = new AVLNode<T>(value);
		count++;
	}
	else if (value < node->_data) {				
		node->_left = insert(value, node->_left);
	}
	else if (node->_data < value) {				
		node->_right = insert(value, node->_right);
	}	
	balanced(node, value);
	return node;
}

template <class T>
void AVLTree<T>::insert(const T& value) {
	root = insert(value, root);
	return;
}

template <class T>
AVLTree<T>::AVLNode<T>* AVLTree<T>::erase(const T& value, AVLNode<T>* &node) {
	if (node == nullptr) {			
		return node;
	}
	if (value < node->_data) {
		node->_left = erase(value, node->_left);
		balanced(node, value);
	}
	else if (node->_data < value) {
		node->_right = erase(value, node->_right);
		balanced(node, value);
	}
	else if (node->_left && node->_right) {
		node->_data = min(node->_right);
		node->_right = erase(node->_data, node->_right);
		balanced(node, value);
	}
	else {
		AVLNode<T>* old_node = node;
		node = node->_left ? node->_left : node->_right;
		delete old_node;
		old_node = nullptr;
		count--;
	}
	return node;
}

template <class T>
void AVLTree<T>::erase(const T& value) {
	root = erase(value, root);
}

template <class T>
T AVLTree<T>::find_min() const {
	if (root == nullptr) {
		std::cout << "Tree is Empty\n";
		return -1;
	}
	AVLNode<T>* node = root;
	while (node->_left != nullptr) {
		node = node->_left;
	}
	return node->_data;
}

template <class T>
T AVLTree<T>::find_max() const {
	if (root == nullptr) {
		std::cout << "Tree is Empty\n";
		return -1;
	}
	AVLNode<T>* node = root;
	while (node->_right != nullptr) {
		node = node->_right;
	}
	return node->_data;
}

template <class T>
size_t AVLTree<T>::get_num_of_nodes() const {
	return count;
}

template <class T>
void AVLTree<T>::find(T value) const {
	if (!is_contain(value)) {
		std::cout << "We cannot find " << value << "\n";
	}
	else {
		std::cout << "We find " << value << "\n";
	}
}

template <class T>
bool AVLTree<T>::is_empty() const {
	return count == 0;
}

template <class T>
int AVLTree<T>::get_balance() const {
	if (root == nullptr) {
		return 0;
	}
	if (root->_left == nullptr && root->_right == nullptr) {
		return 0;
	}
	if (root->_left == nullptr) {
		return (-1) * height(root->_right);
	}
	if (root->_right == nullptr) {
		return height(root->_left);
	}
	return height(root->_left) - height(root->_right);
}

template <class T>
bool AVLTree<T>::contain(const T value, const AVLNode<T>* node) const {
	if (node) {
		if (value < node->_data) {
			return contain(value, node->_left);
		}
		if (node->_data < value) {
			return contain(value, node->_right);
		}
		return true;
	}
	return false;
}

template <class T>
bool AVLTree<T>::is_contain(const T& value) const {
	return contain(value, root);
}

template <class T>
int AVLTree<T>::get_root_data() const {
	if (root != nullptr) {
		return root->_data;
	}
	std::cout << "Tree is empty\n";
	return -1;
}

template <class T>
void AVLTree<T>::clear(AVLNode<T>*& node) {
	if (node != nullptr) {
		clear(node->_left);
		clear(node->_right);
		delete node;
		node = nullptr;
		count--;
	}
}

template <class T>
void AVLTree<T>::clear() {
	clear(root);
	root = nullptr;
}

template <class T>
void AVLTree<T>::print_preorder() const {
	if (root) {
		print_preorder(root);
	}
}

template <class T>
void AVLTree<T>::print_preorder(AVLNode<T>* node) const {
	std::cout << node->_data << " ";
	if (node->_left) {
		print_preorder(node->_left);
	}
	if (node->_right) {
		print_preorder(node->_right);
	}
}

template <class T>
void AVLTree<T>::print_inorder() const {
	if (root) {
		print_inorder(root);
	}
}

template <class T>
void AVLTree<T>::print_inorder(AVLNode<T>* node) const {
	if (node == nullptr) {
		return;
	}
	print_inorder(node->_left);
	std::cout << node->_data << " ";
	print_inorder(node->_right);
}

template <class T>
void AVLTree<T>::print_postorder() const {
	if (root) {
		print_postorder(root);
	}
}

template <class T>
void AVLTree<T>::print_postorder(AVLNode<T>* node) const {
	if (node == nullptr) { 
		return;
	}
	print_postorder(node->_left);
	print_postorder(node->_right);
	std::cout << node->_data << " ";
}

template <class T>
void AVLTree<T>::print_levelorder_iterative() const {
	if (root == nullptr) {
		return;
	}
	std::queue<AVLNode<T>*> q;
	AVLNode<T>* current;
	q.push(root);
	q.push(nullptr);
	while (q.size() > 1) {
		current = q.front();
		q.pop();
		if (current == nullptr) {
			q.push(nullptr);
			std::cout << "\n";
		}
		else {
			if (current->_left) {
				q.push(current->_left);
			}
			if (current->_right) {
				q.push(current->_right);
			}
			std::cout << current->_data << " ";
		}
	}
}

template <class T>
void AVLTree<T>::print_levelorder() const {
	AVLNode<T>* r = root;
	int h = height(r);
	for (int i = 1; i <= h; i++) {
		print_levelorder(root, i);
	}
}

template <class T>
void AVLTree<T>::print_levelorder(AVLNode<T>* root, int level) const {
	if (root == nullptr) {
		return;
	}
	if (level == 1) {
		std::cout << root->_data << " ";
	}
	else if (level > 1) {
		print_levelorder(root->_left, level - 1);
		print_levelorder(root->_right, level - 1);
	}
}

template <class T>
AVLTree<T> AVLTree<T>::merge(AVLTree<T>& t1, AVLTree<T>& t2) {
	AVLTree<T> t;
	t = t1 + t2;
	return t;
}

template <class T>
bool AVLTree<T>::compare(AVLNode<T>* root1, AVLNode<T>* root2) const {
	if (root1 == nullptr && root2 == nullptr) {
		return true;
	}
	if (root1 != nullptr && root2 != nullptr && root1->_data == root2->_data)
	{
		return compare(root1->_left, root2->_left) && compare(root1->_right, root2->_right);
	}
	return false;
}

template <class T>
bool AVLTree<T>::operator==(const AVLTree<T>& other) const {
	if (height(root) != height(other.root)) {
		return false;
	}
	else {
		return compare(root, other.root);
	}
}

template <class T>
bool AVLTree<T>::operator!=(const AVLTree<T>& other) const {
	return !(root == other.root);
}

template <class T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T>& tree) {
	if (this == &tree) {
		return *this;
	}
	if (root != nullptr) {
		clear(root);
		root = nullptr;
	}
	root = copy(tree.root);
	return *this;
}

template <class T>
AVLTree<T>::AVLNode<T>* AVLTree<T>::copy(AVLNode<T>* original) const {
	if (original == nullptr) {
		return nullptr;
	}
	else {
		AVLNode<T>* node = new AVLNode<T>(original->_data);
		node->_left = copy(original->_left);
		node->_right = copy(original->_right);
		return node;
	}
}

template <class T>
AVLTree<T>& AVLTree<T>::operator=(AVLTree<T>&& tree) {
	if (root != nullptr) {
		clear(root);
		root = nullptr;
	}
	root = tree.root;
	tree.root = nullptr;
	return *this;
}

template <class T>
AVLTree<T> AVLTree<T>::operator+(const AVLTree<T>& tree) {
		AVLTree<T> t = *this;
		t += tree;
		return t;
}

template <class T>
AVLTree<T>& AVLTree<T>::operator+=(const AVLTree<T>& tree) {
	if (*this == tree) {
		insert(tree.root);
	}
	else {
		insert(tree.root);
	}
	return *this;
}

template<class T>
void AVLTree<T>::insert(AVLNode<T>* node) {
	if (node != nullptr) {
		insert(node->_data);
		insert(node->_left);
		insert(node->_right);
	}
}

template <class T>
void AVLTree<T>::balanced(AVLNode<T>*& node, const T& value) {
	if (height(node->_left) - height(node->_right) == 2) {
		if (value < node->_left->_data) {
			node = left_rotate(node);
		}
		else {
			node = leftright_rotate(node);
		}
	}
	if (height(node->_left) - height(node->_right) == -2) {
		if (node->_right->_data < value) {
			node = right_rotate(node);
		}
		else {
			node = rightleft_rotate(node);
		}
	}
}


template <class T>
T AVLTree<T>::min(const AVLNode<T>* node) const {
	if (node->_left != nullptr) {
		return min(node->_left);
	}
	return node->_data;
}

template <class T>
T AVLTree<T>::max(const AVLNode<T>* node) const {
	if (node->_right != nullptr) {
		return max(node->_right);
	}
	return node->_data;
}
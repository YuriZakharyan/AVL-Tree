#include "AVLTree.h"
#include <iostream>
#include <queue>
template <class T>
AVLNode<T> ::AVLNode(const T value) : _data(value),	_left(nullptr),	_right(nullptr) {}
template <class T>
AVLNode<T>::~AVLNode() {}
template <class T>
AVLTree<T>::AVLTree() :	count(0), root(nullptr) {}
template<class T>
AVLTree<T>::AVLTree(AVLNode<T>* newRoot) : root(newRoot) {}
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
AVLTree<T>::AVLTree(std::initializer_list<T> newList) :root(nullptr) {	//not fully implemented
	for (auto i = newList.begin; i != newList.end; i++) {
		insert(i, root);
		ListHelper(root);
	}
}
template <class T>
void AVLTree<T> ::ListHelper(AVLNode<T>*&) {
	if (root) {
		ListHelper(root->_left);
		ListHelper(root->_right);
	}
}
template <class T>
AVLNode<T>* AVLTree<T>::left_Rotate(AVLNode<T>*& node) {
	AVLNode<T>* ll = node->_left;
	node->_left = ll->_right;
	ll->_right = node;
	return ll;
}
template <class T>
AVLNode<T>* AVLTree<T>::right_Rotate(AVLNode<T>*& node) {
	AVLNode<T>* rr = node->_right;
	node->_right = rr->_left;
	rr->_left = node;
	return rr;
}
template <class T>
AVLNode<T>* AVLTree<T>::leftright_Rotate(AVLNode<T>*& node) {
	node->_left = right_Rotate(node->_left);
	node = left_Rotate(node);
	return node;
}
template <class T>
AVLNode<T>* AVLTree<T>::rightleft_Rotate(AVLNode<T>*& node) {
	node->_right = left_Rotate(node->_right);
	node = right_Rotate(node);
	return node;
}
template <class T>
int AVLTree<T>::height(AVLNode<T>* node) const {
	if (!node)	return 0;
	return returnMax(height(node->_left), height(node->_right)) + 1;
}
template <class T>
int AVLTree<T>::returnMax(T a, T b) const {
	return (a > b) ? a : b;
}
template <class T>
int AVLTree<T>::getHeight() const {
	return height(root);
}
template <class T>
AVLNode<T>* AVLTree<T>::insert(const T value, AVLNode<T>* node) {
	if (node == nullptr) {						//find place to add a new node.
		node = new AVLNode<T>(value);
		count++;
	}
	else if (value < node->_data) {				//Go to the left Subtree
		node->_left = insert(value, node->_left);
		if (height(node->_left) - height(node->_right) == 2) {		//Balancing
			if (value < node->_left->_data)
				node = left_Rotate(node);
			else
				node = leftright_Rotate(node);
		}
	}
	else if (node->_data < value) {				//Go to the right Subtree
		node->_right = insert(value, node->_right);
		if (height(node->_left) - height(node->_right) == -2) {		//Balancing
			if (node->_right->_data < value)
				node = right_Rotate(node);
			else
				node = rightleft_Rotate(node);
		}
	}
	return node;
}
template <class T>
void AVLTree<T>::insert(const T value) {
	root = insert(value, root);
	return;
}
template <class T>
AVLNode<T>* AVLTree<T>::erase(const T value, AVLNode<T>* node) {
	if (node == nullptr) {			//If Tree is empty, return.
		return node;
	}
	if (value < node->_data) {
		node->_left = erase(value, node->_left);
		if (height(node->_left) - height(node->_right) == -2) {
			if (height(node->_right->_left) <= height(node->_right->_right))
				node = right_Rotate(node);
			else
				node = rightleft_Rotate(node);
		}
	}
	else if (node->_data < value) {
		node->_right = erase(value, node->_right);
		if (height(node->_left) - height(node->_right) == 2) {
			if (height(node->_left->_right) <= height(node->_left->_left))
				node = left_Rotate(node);
			else
				node = leftright_Rotate(node);
		}
	}
	else if (node->_left && node->_right) {
		node->_data = findMin(node->_right);
		node->_right = erase(node->_data, node->_right);
		if (height(node->_left) - height(node->_right) == 2) {
			if (height(node->_left->_right) <= height(node->_left->_left))
				node = left_Rotate(node);
			else
				node = leftright_Rotate(node);
		}
	}
	else {
		AVLNode* old_node = node;
		node = node->_left ? node->_left : node->_right;
		delete old_node;
		old_node = nullptr;
		count--;
	}
	return node;
}
template <class T>
void AVLTree<T>::erase(const T value) {
	root = erase(value, root);
}
template <class T>
T AVLTree<T>::findMin(const AVLNode<T>* node) const {
	if (node->_left) {
		return findMin(node->_left);
	}
	return node->_data;
}
template <class T>
T AVLTree<T>::findMin() const {
	if (root) {
		return findMin(root);
	}
	else {
		std :: cout << "Your Tree is Empty\n";
		return -1;
	}
}
template <class T>
T AVLTree<T>::findMax(const AVLNode<T>* node) const {
	if (node->_right) {
		return findMax(node->_right);
	}
	return node->_data;
}
template <class T>
T AVLTree<T>::findMax() const {
	if (root) {
		return findMax(root);
	}
	else {
		std :: cout << "Tree is empty\n";
		return -1;
	}
}
template <class T>
size_t AVLTree<T>::getNumOfNodes() const {
	return count;
}
template <class T>
void AVLTree<T>::find(T value) const {
	if (!isContain(value)) {
		std::cout << "We cannot find " << value << "\n";
	}
	else {
		std::cout << "We find " << value << "\n";
	}
}
template <class T>
bool AVLTree<T>::isEmpty() const {
	return count == 0;
}
template <class T>
int AVLTree<T>::getBalance() const {
	if (root->_left == nullptr && root->_right == nullptr)
		return 0;
	if (root->_left == nullptr)
		return (-1) * height(root->_right);
	if (root->_right == nullptr)
		return height(root->_left);
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
bool AVLTree<T>::isContain(const T value) const {
	return contain(value, root);
}
template <class T>
int AVLTree<T>::getRootData() const {
	return root->_data;
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
void AVLTree<T>::printPreorder() const {
	if (root) {
		printPreorder(root);
	}
}
template <class T>
void AVLTree<T>::printPreorder(AVLNode<T>* node) const {
	std::cout << node->_data << " ";
	if (node->_left) {
		printPreorder(node->_left);
	}
	if (node->_right) {
		printPreorder(node->_right);
	}
}
template <class T>
void AVLTree<T>::printInorder() const {
	if (root) {
		printInorder(root);
	}
}
template <class T>
void AVLTree<T>::printInorder(AVLNode<T>* node) const {
	if (node == nullptr) return;
	printInorder(node->_left);
	std::cout << node->_data << " ";
	printInorder(node->_right);
}
template <class T>
void AVLTree<T>::printPostorder() const {
	if (root) {
		printPostorder(root);
	}
}
template <class T>
void AVLTree<T>::printPostorder(AVLNode<T>* node) const {
	if (node == nullptr) return;
	printPostorder(node->_left);
	printPostorder(node->_right);
	std::cout << node->_data << " ";
}
template <class T>
void AVLTree<T>::printLevelorderIterative() const {
	if (root == nullptr) return;
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
void AVLTree<T>::printLevelorder() const {
	AVLNode<T>* r = root;
	int h = height(r);
	for (int i = 1; i <= h; i++) {
		printLevelOrder(root, i);
	}
}
template <class T>
void AVLTree<T>::printLevelOrder(AVLNode<T>* root, int level) const {
	if (root == nullptr)
		return;
	if (level == 1)
		std::cout << root->_data << " ";
	else if (level > 1) {
		printLevelOrder(root->_left, level - 1);
		printLevelOrder(root->_right, level - 1);
	}
}
///template <class T>
///void AVLTree<T>::mergeHelper(AVLNode<T>*& node) {
///	if (node != nullptr) {
///		mergeHelper(node->_left);
///		insert(node->_data, root);
///		mergeHelper(node->_right);
///	}
///}
///template <class T>
///AVLTree<T> AVLTree<T>::mergeTrees(AVLTree<T>& t1, AVLTree<T>& t2) {
///	t1.mergeHelper(t2.root);
///	return t1;
///}
template <class T>
AVLTree<T> AVLTree<T> ::merge(AVLTree<T>& t1, AVLTree<T>& t2) {
	AVLTree<T> t;
	t = t1 + t2;
	return t;
}
template <class T>
bool AVLTree<T>::compare(AVLNode<T>* root1, AVLNode<T>* root2) const {
	if (root1 == nullptr && root2 == nullptr)
		return true;
	if (root1 != nullptr && root2 != nullptr && root1->_data == root2->_data)
	{
		return compare(root1->_left, root2->_left) && compare(root1->_right, root2->_right);
	}
	return false;
}
template <class T>
bool AVLTree<T>::operator==(const AVLTree<T>& other) const {
	if (height(root) != height(other.root))
		return false;
	else
		return compare(root, other.root);
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
AVLNode<T>* AVLTree<T>::copy(AVLNode<T>* original)const {
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
		AVLTree<T> t = root;	//*this
		t += tree;
		return t;
}
template <class T>
AVLTree<T>& AVLTree<T>::operator+=(const AVLTree<T>& tree) {
	if (*this == tree) {
		insertHelper(tree.root);
	}
	else {
		insertHelper(tree.root);
	}
	return *this;
}
template<class T>
void AVLTree<T>::insertHelper(AVLNode<T>* node) {
	if (node != nullptr) {
		insert(node->_data);
		insertHelper(node->_left);
		insertHelper(node->_right);
	}
}

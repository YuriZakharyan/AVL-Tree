#include <iostream>
#include "AVLTree.hpp"
int main() {
	/*
	AVLTree<int> avl;	//Create AVL tree which nodes values is intager
	avl.insert(14);		//Add new node
	avl.insert(17);
	avl.insert(11);
	avl.insert(7);
	avl.insert(53);
	avl.insert(4);
	avl.insert(13);
	avl.insert(12);
	avl.insert(8);
	avl.insert(60);
	avl.insert(19);
	avl.insert(16);
	avl.insert(20);
	*/
	/*
								  14
							 /    	    \
						 11                19
					  /      \          /      \
					 7       12       17        53
				   /   \       \      /        /  \
				  4     8      13   16        20  60

	*/
	/*
	std::cout << "Stream out operator: ";
	std::cout << avl << "\n";
	//avl.clear();
	std::cout << "\nAVL tree (preorder traversal): ";
	avl.printPreorder();
	std::cout << "\n\nAVL tree (inorder traversal): ";
	avl.printInorder();
	std::cout << "\n\nAVL tree (postorder traversal): ";
	avl.printPostorder();
	std::cout << "\n\nAVL tree (levelorder traversal): ";
	avl.printLevelorder();
	std::cout << "\n----------------------------------------------------------------------------------------";
	std::cout << "\nRoot Data: " << avl.getRootData() << "\n";
	std::cout << "\n";
	std::cout << "Height of Tree : " << avl.getHeight() << "\n";
	std::cout << "\nNumber of Nodes : " << avl.getNumOfNodes() << "\n";
	std::cout << "\nMinimum value in AVL Tree : " << avl.findMin() << "\n";
	std::cout << "\nMaximum value in AVL Tree : " << avl.findMax() << "\n";
	std::cout << "\nisContain(13) : " << (avl.isContain(13) == true ? "Yes" : "No") << "\n";
	std::cout << "\nisContain(40) : " << (avl.isContain(40) == true ? "Yes" : "No") << "\n";
	std::cout << "\nIsEmpty() : " << (avl.isEmpty() == true ? "Yes" : "No") << "\n";
	std::cout << "\nfind(150) : ";
	avl.find(150);
	std::cout << "\nfind(8) : ";
	avl.find(8);
	std::cout << "\nTree Balance Factor is : " << avl.getBalance();
	std::cout << "\n\nLevelOrder Traversal(Iterative): \n";
	avl.printLevelorderIterative();
	std::cout << "\n";
	*/
	/*
	AVLTree<char> t1;
	AVLTree<char> t2;
	if (t1 == t2) {														//== operator, whan trees is empty
		std::cout << "\nt1 == t2";
	}
	else {
		std::cout << "\nt1 != t2";
	}
	if (t1 != t2) {														//!= operator, whan trees is empty
		std::cout << "\nt1 != t2";
	}
	else {
		std::cout << "\nt1 == t2";
	}
	*/
	/*
	t1.insert('H');
	t1.insert('A');
	t2.insert('B');
	std::cout << "\nt1 -> ";
	std::cout << t1;
	std::cout << "\nt2 -> " << t2 << "\n";
	t1 = t2;															//assignment
	std::cout << "\nt1 -> " << t1 << "\n";
	AVLTree<int> a;
	std::cout << "Maximum: " << a.findMax();
	std::cout << "\n--------------------------------\n";
	std::cout << "avl -> ";
	std::cout << avl << "\n";
	AVLTree<int> k;
	k.insert(1000);
	std::cout << "k -> " << k << "\n";									// k -> 1000  /  avl -> 4,7,8,11,12,13,14,16,17,19,20,53,60
	k += avl;															// k -> k + avl
	std::cout << "\n";
	std::cout << "k -> " << k;											// k ->  4 7 8 11 12 13 14 16 17 19 20 53 60 1000
	std::cout << "\n--------------------------------\n";
	AVLTree<int>n;
	AVLTree<int>o;
	//o = avl + k;
	//std::cout << o;
	//std :: cout << "\n--------------------------------\n";
	//AVLTree<int> ee{ 4, 5 };											//only can declare tree, using initializer_list.
	//std :: cout << ee;												//error(...)
	*/
    /*
	AVLTree<char>r,r1;
	r.insert('a');
	r.insert('b');
	r.insert('v');
	r1.insert('5');
	r1.insert('6');
	r1.printInorder();													//r1-> 5,6
	std :: cout << "\n";		
	r1 += r;					
	r1.printInorder();													//r1->5,6,a,b,v
	*/
	/*
	AVLTree<int> a, b;
	a.insert(5);
	a.insert(6);
	a.insert(1);
	//b.insert(3);
	//AVLTree<int>c;
	//c = a + b;											
	//c.printInorder();
	AVLTree<int> k = k.merge(a, b);						
	k.printInorder();
	std::cout << "\n";
	k.printLevelorderIterative();
	*/
}
# AVL Tree Data Structure
### AVL tree is a self-balancing Binary Search Tree where the difference between heights of left and right subtrees cannot be more than one for all nodes. 

### In this project you can see:

## **Methods**
 >- **Insert()** - Insert element in tree (after that balansing the tree). 
 >- **Erase()** - Insert element in tree (after that balansing the tree).
 >- **RightRotate()**
 >- **LeftRotate()** 
 >- **RightLeftRotate()**
 >- **LeftRightRotate()**
 >- **Clear()** - Delete tree.
 >- **GetBalance()** - Dalculate balance factor //   -1 <= (left.height - right.height) <= 1
 >- **GetHeight()** - Return height of tree.
 >- **GetNumberOfNodes()** - Return number of nodes in tree.
 >- **InorderTraversal()** - Left->Root->Right
 >- **PreorderTraversal()** - Root->Left->Right
 >- **PostorderTraversal()** - Left->Right->Root
 >- **LevelOrderTraversal()** - From top to down.
 >- **LevelOrderTraversalIterative()** - This is iterative solution, where I used Queue data structure.
 >- **GetRootData()** - Return value of root.
 >- **Merge()** - Merging two AVL tree.
 >- **Find()** - Find node in tree.
 >- **FindMin()** - Return node, which value is minimum.
 >- **FindMax()** - Return node, which value is minimum.
 >- **IsEmpty()** - Return true, if tree is empty.
 >- **IsContain()** - Return true, if tree is containing the node.
 >- **Compare()** - Comparing trees(this is a helper method).

## Operators
 >- **Copy operator assignment =**
 >- **Move operator assignment =**
 >- **Operator stream out(cout) <<**
 >- **Operator is Equal to ==**
 >- **Operator is not Equal to !=**
 >- **Operator +**
 >- **Operator +=**

### **Insertion**
>**_Steps to follow for insertion_**
>>- Perform standard BST insert for w. 
>>Starting from w, travel up and find the first unbalanced node. Let z be the first unbalanced node, y be the child of z that comes on the path from w to z and x be the grandchild of z that comes on the path from w to z. 
>>- Starting from w, travel up and find the first unbalanced node. Let z be the first unbalanced node, y be the child of z that comes on the path from w to z and x be >>the grandchild of z that comes on the path from w to z. 
>>- Following are the possible 4 arrangements:
>>>- y is the left child of z and x is the left child of y (Left Left Case)  
>>>- y is the left child of z and x is the right child of y (Left Right Case) 
>>>- y is the right child of z and x is the right child of y (Right Right Case) 
>>>- y is the right child of z and x is the left child of y (Right Left Case)

>>>>![Alt](https://miro.medium.com/max/1400/0*35JZHDSkODkDbeoP.gif)

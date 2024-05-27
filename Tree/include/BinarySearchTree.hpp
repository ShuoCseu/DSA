#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

template <class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *leftChild, *rightChild;
    binaryTreeNode(){leftChild = rightChild = nullptr;}
    binaryTreeNode(const T& theElement)
    {
        element = theElement;
        leftChild = rightChild = nullptr;
    }
    binaryTreeNode(const T& theElement, binaryTreeNode *theLeftChild, binaryTreeNode *theRightChild)
    {
        element = theElement;
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};

template<class E>
class linkedBinaryTree
{
private:
    binaryTreeNode<E> *root;
    int treeSize;
public:
    linkedBinaryTree();
    ~linkedBinaryTree();
};


#endif

#include <iostream>
using std::cout;
using std::endl;

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

template <class T>
void visit(binaryTreeNode<T> *x)
{
    cout << x->element << ' ';
}

// 1. preorder traversal
template <class T>
void preOrder(binaryTreeNode<T> *t)
{
    if (t != nullptr)
    {
        visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

// 2. inorder traversal
template <class T>
void inOrder(binaryTreeNode<T> *t)
{
    if (t != nullptr)
    {
        inOrder(t->leftChild);
        visit(t);
        inOrder(t->rightChild);
    }
}

// 3. postorder traversal
template <class T>
void postOrder(binaryTreeNode<T> *t)
{
    if (t != nullptr)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        visit(t);
    }
}

template <class T>
class binaryTree
{
public:
    virtual ~binaryTree(){};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void preOrder(void (*)(T*)) = 0;
    virtual void inOrder(void (*)(T*)) = 0;
    virtual void postOrder(void (*)(T*)) = 0;
};

template <class E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>>
{
    private:
        binaryTreeNode<E> *root;
        int treeSize;
        static void dispose(binaryTreeNode<E> *t) {delete t;}
        static void inOrder(binaryTreeNode<E> *t);
        static void postOrder(binaryTreeNode<E> *t);
    public:
        linkedBinaryTree(){root = nullptr; treeSize = 0;}
        ~linkedBinaryTree(){erase();}
        bool empty() const{return treeSize == 0;}
        int size() const{return treeSize;}
        void inOrder(void (*theVisit)(binaryTreeNode<E>*))
            {visit = theVisit; inOrder(root);}
        void postOrder(void (*theVisit)(binaryTreeNode<E>*))
            {visit = theVisit; postOrder(root);}
        void erase()
        {
            postOrder(dispose);
            root = nullptr;
            treeSize = 0;
        }
};

int main()
{
    
    return 0;
}

#include "bst.cpp"

#ifndef __BST_HPP
#define __BST_HPP


template <class T, class S>
struct node{
    T key;
    S value; 
    node *left;
    node *right;
    int height;
    node *parent;
    
    node (T key, S value){
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        parent = NULL;
        height = 1;
    }
};


template <class T, class S>
class BST {
    node<T,S> *root;

    
public:
    ~BST();
    void treeDestruct(node<T,S>*);
    void insertNode(node<T,S>*);
    void deleteNode(T k);    
    node<T,S>* searchNode(T k);
    node<T,S>* getRoot();
    int height (node<T,S>* p);
    void inOrderTraversal(node<T,S>* p);
    void postOrderTraversal(node<T,S>* p);
    void preOrderTraversal(node<T,S>* p);
    void insertNodeTrav(node<T,S>* a, node<T,S>* b);
    node<T,S>* searchNodeT(node<T,S>* p, T k);
    void deleter(T k, node<T,S>* x);
    node<T,S>* forMerging(node<T,S> *x);
    int heightFinder (node<T,S>* p);
    void ender(node<T,S>* p);
};


#endif
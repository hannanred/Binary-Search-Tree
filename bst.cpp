#ifndef __BST_CPP
#define __BST_CPP

#include <iostream>
#include "bst.hpp"
using namespace std;

template <class T, class S>
BST<T,S>:: ~BST(){


	if(root==NULL)
	{
		return;
	}
	else if(root->left != NULL and root->right!=NULL)
	{
		treeDestruct(root);
	}
	


}
template <class T, class S>
void BST<T,S> :: treeDestruct (node<T,S>* r)
{
	if (r==NULL)
	{
		return;
	}
	treeDestruct(r->left);
	treeDestruct(r->right);
	delete r;

}

template <class T, class S>
int BST<T,S> :: heightFinder (node<T,S>* p){
 if(p != NULL and p->left == NULL and p->right == NULL)
	{

		return 1;
	}
	else{
		if(p==NULL)
		{
			return 0;
		}
		else{
			int l = heightFinder(p->left);
			int r = heightFinder(p->right);
			
		if (r<l)
			{
				
					
				  return l+1;
			}
			else 
			{
			
					return r+1;
			}
		}}

}

template <class T, class S>
int BST<T,S> :: height (node<T,S>* p){
	
	
	return heightFinder(p);

		}
	

  
    


template <class T, class S>
void BST<T,S> :: insertNode(node<T,S>* newNode){
	
	node<T,S> *trav = root;

if(trav == NULL)
	{
		root = newNode;
		root->left = NULL;
		root->right=NULL;
		root->parent = NULL;
	}
else {
		insertNodeTrav(newNode, trav);
	 }
}

template <class T, class S>
void BST<T,S> :: insertNodeTrav(node<T,S>* a, node<T,S>* b){
	
	if(b->key < a->key)
	{
		if(b->right ==NULL)
		{
			b->right = a;
			a->left = NULL;
			a->right = NULL;
			a->parent = b;

		}
		else{
			insertNodeTrav(a, b->right);
		}
	}
	else if(b->key > a->key)
	{
		if(b->left ==NULL)
		{
			b->left = a;
			a->right = NULL;
			a->left = NULL;
			a->parent = b;
		}
		else{
			insertNodeTrav(a, b->left);
		}
	}

}

template <class T, class S>
node<T,S>* BST<T,S> :: searchNode(T key){
	if (root ==NULL)
	{
		return NULL;
	}
	if(root->key == key)
	{
		return root;
	}
	else 
	{
		searchNodeT(root,key);
	}
	

}
template <class T, class S>
node<T,S>* BST<T,S> :: searchNodeT(node<T,S>* p, T k){
	if(p==NULL)
	{ 
		return NULL;
	}
	else if(p->key == k)
	{
		return p;
	}
	else if(p->key < k)
	{
		searchNodeT(p->right, k);
	}
	else if(p->key > k)
	{
		searchNodeT(p->left, k);
	}
	
}

template <class T, class S>
void BST<T,S>::preOrderTraversal(node<T,S>* p){

if(p==NULL)
	{
		return;
	}
	else{
		cout << p->key<<":"<<p->value << " ";
		preOrderTraversal(p->left);
		preOrderTraversal(p->right);
	}

}

template <class T, class S>
void BST<T,S>::inOrderTraversal(node<T,S>* p){
if(p==NULL)
	{
		return;
	}
	else{
		inOrderTraversal(p->left);
		cout << p->key<<":"<<p->value << " ";
		inOrderTraversal(p->right);
	}

}
template <class T, class S>
void BST<T,S>::ender(node<T,S>* p){
if(p==NULL)
	{
		return;
	}
	else{
		ender(p->left);
		ender(p->right);
		p->value= 0;
	}

}

template <class T, class S>
void BST<T,S>::postOrderTraversal(node<T,S>* p){
	if(p==NULL)
	{
		return;
	}
	else{
		postOrderTraversal(p->left);
		postOrderTraversal(p->right);
		cout << p->key<<":"<<p->value << " ";
	}
}

template <class T, class S>
void BST<T,S>::deleteNode(T k){
	if(root == NULL)
	{
		return;
	}
	else if(root->key == k and root->left==NULL and root->right == NULL)
	{
		root->left = NULL;
		root->right = NULL;
		root = NULL;
		delete root;
	}
	else 
	{
		deleter(k, root);
	}
 //case1

}
template <class T, class S>
void BST<T,S>::deleter(T k,node<T,S>* x)
{
	node<T,S>* temp;
	if(k>x->key)
	{
		deleter(k,x->right);
	}
	else if(k<x->key)
	{
		deleter(k,x->left);
	}
	else if(x->key == k)
	{
		if(x->left == NULL and x->right == NULL)
		{
			if(x->parent->right == x)
			{
				x->parent->right = nullptr;
			}
			else if(x->parent->left==x)
			{
				x->parent->left=nullptr;
			}
			delete x;
			x= nullptr;
			
		
			// cout << "no key"<<endl;
		}
		else if(x->left != NULL and x->right == NULL)
		{

				temp=x->left;
				if(x->parent->right == x)
			{
				x->parent->right = temp;
			}
			else if(x->parent->left==x)
			{
				x->parent->left=temp;
			}
				
				delete x;
				x = nullptr;

		}
			else if(x->right != NULL and x->left == NULL)
			{
				temp=x->right;
				if(x->parent->right == x)
			{
				x->parent->right = temp;
			}
			else if(x->parent->left==x)
			{
				x->parent->left=temp;
			}
				
				delete x;
				x = nullptr;
			}
		else if(x->right != NULL and x->left!=NULL)
		{
			temp = forMerging(x->right);
			x->key = temp->key;
			x->value = temp->value;
			if(temp->right != NULL)
			{
				temp->parent->right = temp->right;
			}
			else {
				temp->parent->right = NULL;
		}
			
			
		
		}

		}
	}

template <class T,class S>
node<T,S>* BST<T,S>::forMerging(node<T,S> *x){
	while(x->left != NULL)
	{
		x= x->left;

	}
	return x;
}
template <class T, class S>
node<T,S>* BST<T,S>::getRoot(){
    return root;
}


#endif
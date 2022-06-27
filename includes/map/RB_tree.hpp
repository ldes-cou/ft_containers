/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:31:50 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/27 11:26:32 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

// #define BLACK 0
// #define RED 1
#define B = "\x1b[30m"
#define R = "\x1b[31m"
# define END "\033[0m"
#include <cstddef>
#include <iostream>
// #ifndef VALUE_TYPE 
// #define VALUE_TYPE int

#define out(x) std::cout << x << std::endl;

//set a T.nil sentinel to deal with iterators

//template<typename T>
// struct Node 
// {
//     int data;
//     Node *parent;
//     Node *left;
//     Node *right;
//     bool color;

//     Node(int data)
//     {
//         this->data = data;
//         left = right = parent = NULL;
//         this->color = RED;
//     }
//     ~Node()
//     {;}
    

#include <iostream>
#include <queue>
//#include "RB_tree_iterator.hpp"

//using namespace std;

#define BLACK 0
#define RED 1

template <typename T>
	struct RB_Node
	{
		typedef T 							value_type;
		typedef RB_Node<T>					Node;
		typedef RB_Node<T>*     			Node_ptr;
		typedef const RB_Node*				_Const_Base_ptr;
		typedef	std::allocator<Node>		allocator_type;
		typedef typename allocator_type::template rebind<Node>::other			_alloc;
		
	/******************************** MEMBER VARIABLES**********************************/
			Node_ptr		left;
			Node_ptr		right;
			Node_ptr		parent;
			value_type		data;
			int 			color;

	/********************************** CONSTRUCTOR **********************************/

	RB_Node(void): data(T())
	{
		this->color = BLACK;
		left = right = parent = NULL;
	}
	RB_Node(value_type data)
    {
        this->data = data;
        left = right = parent = NULL;
        this->color = RED;
    }
	// Node(_Base_ptr parent  = 0 _Base_ptr left = 0, _Base_ptr right = 0, color = RED) : data(T())
	// {;
	// }
	
	// Node(const &Node cpy) : 
	// 	parent(cpy.parent), 
	// 	left(cpy.left), 
	// 	right(cpy.right), 
	// 	data(cpy.data),
	// 	color(cpy.color) // not sure for the color
	// {}
	// returns pointer to uncle
	RB_Node *uncle()
	{
		// If no parent or grandparent, then no uncle
		if (parent == NULL or parent->parent == NULL)
			return NULL;
		if (parent->isOnLeft())
			return parent->parent->right;
		else
			return parent->parent->left;
	}
	/****************************** INCREMENT ************************************/
	static Node* Rb_tree_increment(Node* __x) throw ()
		{
			if (__x->_M_right != 0)
			{
				__x = __x->_M_right;
				while (__x->_M_left != 0)
					__x = __x->_M_left;
			}
			else
			{
				Node* __y = __x->_M_parent;
				while (__x == __y->_M_right)
				{
					__x = __y;
					__y = __y->_M_parent;
				}
				if (__x->_M_right != __y)
				__x = __y;
			}
			return __x;
		}

		static Node* Rb_tree_decrement(Node* __x) throw ()
		{
			if (__x->_M_color == RED
				&& __x->_M_parent->_M_parent == __x)
			__x = __x->_M_right;
			else if (__x->_M_left != 0)
			{
				Node* __y = __x->_M_left;
				while (__y->_M_right != 0)
				__y = __y->_M_right;
				__x = __y;
			}
			else
			{
				Node* __y = __x->_M_parent;
				while (__x == __y->_M_left)
				{
					__x = __y;
					__y = __y->_M_parent;
				}
				__x = __y;
			}
			return __x;
		}
		
// check if node is left child of parent
		bool isOnLeft() { return this == parent->left; }

		// returns pointer to sibling
		Node *sibling() {
			// sibling null if no parent
			if (parent == NULL)
			return NULL;

			if (isOnLeft())
			return parent->right;

			return parent->left;
		}

		// moves node down and moves given node in its place
		void moveDown(Node *nParent) {
			if (parent != NULL) {
			if (isOnLeft()) {
				parent->left = nParent;
			} else {
				parent->right = nParent;
			}
			}
			nParent->parent = parent;
			parent = nParent;
		}

		bool hasRedChild()
		{
			return (left != NULL and left->color == RED) or
				(right != NULL and right->color == RED);
		}
	};

template <typename T>
// 	template < class Key,                                     // map::key_type
// 			class T,                                       		// map::mapped_type
// 			class Compare = std::less<Key>,                     // map::key_compare
// 			class Alloc = std::allocator<std::pair<const Key,T> > >    // map::allocator_type
class RBTree : public RB_Node<T>//, public _Rb_tree_iterator
{
	typedef T 																value_type;
	typedef RB_Node<T>														Node;
	typedef RB_Node<T>*     												Node_ptr;
	typedef	std::allocator<Node>											allocator_type;
	//typedef typename allocator_type::template rebind<Node>::other			_alloc;
	
	Node *root;
	Node *nullptr_left;
	Node *nullptr_right;

	public:
	// constructor
	Node *getRoot() { return root; }
	// initialize root
	RBTree()
	{

		root = NULL;
		nullptr_left = NULL;
		nullptr_right = NULL;
		//setLeafs();
	}
	// bool _comp(value_type a, value_type b, Compare u = Compare())
	// {
	// 	return u(a.first, b.first);
	// }
	void	setLeafs()
	{
		Node *min = minimum(root);
		Node *max = maximum(root);

		nullptr_left->parent = min;
		min->left->parent->left = nullptr_left;
		nullptr_right->parent = max;
		max->right->parent->right = nullptr_right;
	}
	void	unsetLeafs()
	{
		if (nullptr_left->parent)
			nullptr_left->parent->left = NULL;
		if (nullptr_right->parent)
			nullptr_right->parent->right = NULL;
		
		
		//delete (nullptr_left);
		// min->left = NULL;
		// //delete (nullptr_right);
		// max->right = NULL;
	}
	Node *minimum(Node *node)
	{
		if (node == NULL)
			return (node);
    	while (node->left != NULL)
      		node = node->left;
    	return node;
  	}

  	Node *maximum(Node *node)
	{
		if (node == NULL)
			return (node);
		while (node->right != NULL)
			node = node->right;
    	return node;
	}
	// left rotates the given node
	void leftRotate(Node *x)
	{
		// new parent will be node's right child
		Node *nParent = x->right;

		// update root if current node is root
		if (x == root)
		root = nParent;
		x->moveDown(nParent);

		// connect x with new parent's left element
		x->right = nParent->left;
		// connect new parent's left element with node
		// if it is not null
		if (nParent->left != NULL)
		nParent->left->parent = x;

		// connect new parent with x
		nParent->left = x;
	}

	void rightRotate(Node *x) {
		// new parent will be node's left child
		Node *nParent = x->left;

		// update root if current node is root
		if (x == root)
		root = nParent;

		x->moveDown(nParent);

		// connect x with new parent's right element
		x->left = nParent->right;
		// connect new parent's right element with node
		// if it is not null
		if (nParent->right != NULL)
		nParent->right->parent = x;

		// connect new parent with x
		nParent->right = x;
	}
	
	void swapColors(Node *x1, Node *x2) {
		int temp;
		temp = x1->color;
		x1->color = x2->color;
		x2->color = temp;
	}

	void swapValues(Node *u, Node *v) {
		int temp;
		temp = u->data;
		u->data = v->data;
		v->data = temp;
	}

	// fix red red at given node
	void fixRedRed(Node *x) {
		// if x is root color it black and return
		if (x == root) {
		x->color = BLACK;
		return;
		}

		// initialize parent, grandparent, uncle
		Node *parent = x->parent, *grandparent = parent->parent,
			*uncle = x->uncle();

		if (parent->color != BLACK) {
		if (uncle != NULL && uncle->color == RED) {
			// uncle red, perform recoloring and recurse
			parent->color = BLACK;
			uncle->color = BLACK;
			grandparent->color = RED;
			fixRedRed(grandparent);
		} else {
			// Else perform LR, LL, RL, RR
			if (parent->isOnLeft()) {
			if (x->isOnLeft()) {
				// for left right
				swapColors(parent, grandparent);
			} else {
				leftRotate(parent);
				swapColors(x, grandparent);
			}
			// for left left and left right
			rightRotate(grandparent);
			} else {
			if (x->isOnLeft()) {
				// for right left
				rightRotate(parent);
				swapColors(x, grandparent);
			} else {
				swapColors(parent, grandparent);
			}

			// for right right and right left
			leftRotate(grandparent);
			}
		}
		}
	}
	
	// find node that do not have a left child
	// in the subtree of the given node
	Node *successor(Node *x) {
		Node *temp = x;

		while (temp->left != NULL)
			temp = temp->left;
		return temp;
	}

	// find node that replaces a deleted node in BST
	Node *BSTreplace(Node *x) {
		// when node have 2 children
		if (x->left != NULL and x->right != NULL)
		return successor(x->right);

		// when leaf
		if (x->left == NULL and x->right == NULL)
		return NULL;

		// when single child
		if (x->left != NULL)
		return x->left;
		else
		return x->right;
	}

	// deletes the given node
	void deleteNode(Node *v) {
		Node *u = BSTreplace(v);

		//unsetLeafs();
		// True when u and v are both black
		bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
		Node *parent = v->parent;

		if (u == NULL) {
		// u is NULL therefore v is leaf
		if (v == root) {
			// v is root, making root null
			root = NULL;
		} else {
			if (uvBlack) {
			// u and v both black
			// v is leaf, fix double black at v
			fixDoubleBlack(v);
			} else {
			// u or v is red
			if (v->sibling() != NULL)
				// sibling is not null, make it red"
				v->sibling()->color = RED;
			}

			// delete v from the tree
			if (v->isOnLeft()) {
			parent->left = NULL;
			} else {
			parent->right = NULL;
			}
		}
		delete v;
		//setLeafs();
		return;
		}

		if (v->left == NULL or v->right == NULL) {
		// v has 1 child
		if (v == root) {
			// v is root, assign the value of u to v, and delete u
			v->data = u->data;
			v->left = v->right = NULL;
			delete u;
		} else {
			// Detach v from tree and move u up
			if (v->isOnLeft()) {
			parent->left = u;
			} else {
			parent->right = u;
			}
			delete v;
			u->parent = parent;
			if (uvBlack) {
			// u and v both black, fix double black at u
			fixDoubleBlack(u);
			} else {
			// u or v red, color u black
			u->color = BLACK;
			}
		}
		return;
		}

		// v has 2 children, swap values with successor and recurse
		swapValues(u, v);
		deleteNode(u);
	}

	void fixDoubleBlack(Node *x) {
		if (x == root)
		// Reached root
		return;

		Node *sibling = x->sibling(), *parent = x->parent;
		if (sibling == NULL) {
		// No sibiling, double black pushed up
		fixDoubleBlack(parent);
		} else {
		if (sibling->color == RED) {
			// Sibling red
			parent->color = RED;
			sibling->color = BLACK;
			if (sibling->isOnLeft()) {
			// left case
			rightRotate(parent);
			} else {
			// right case
			leftRotate(parent);
			}
			fixDoubleBlack(x);
		} else {
			// Sibling black
			if (sibling->hasRedChild()) {
			// at least 1 red children
			if (sibling->left != NULL and sibling->left->color == RED) {
				if (sibling->isOnLeft()) {
				// left left
				sibling->left->color = sibling->color;
				sibling->color = parent->color;
				rightRotate(parent);
				} else {
				// right left
				sibling->left->color = parent->color;
				rightRotate(sibling);
				leftRotate(parent);
				}
			} else {
				if (sibling->isOnLeft()) {
				// left right
				sibling->right->color = parent->color;
				leftRotate(sibling);
				rightRotate(parent);
				} else {
				// right right
				sibling->right->color = sibling->color;
				sibling->color = parent->color;
				leftRotate(parent);
				}
			}
			parent->color = BLACK;
			} else {
			// 2 black children
			sibling->color = RED;
			if (parent->color == BLACK)
				fixDoubleBlack(parent);
			else
				parent->color = BLACK;
			}
		}
		}
	}


	// searches for given value
	// if found returns the node (used for delete)
	// else returns the last node while traversing (used in insert)
	Node *search(int n) {
		Node *temp = root;
		while (temp != NULL) {
		if (n < temp->data) {
			if (temp->left == NULL)
			break;
			else
			temp = temp->left;
		} else if (n == temp->data) {
			break;
		} else {
			if (temp->right == NULL)
			break;
			else
			temp = temp->right;
		}
		}

		return temp;
	}

	// inserts the given value to tree
	void insert(value_type n) {
		Node *newNode = new Node(n);
		if (root == NULL) {
		// when root is null
		// simply insert value at root
		newNode->color = BLACK;
		root = newNode;
		} else {
		Node *temp = search(n);

		if (temp->data == n) {
			// return if value already exists
			return;
		}

		// if value is not found, search returns the node
		// where the value is to be inserted

		// connect new node to correct node
		newNode->parent = temp;

		if (n < temp->data)
			temp->left = newNode;
		else
			temp->right = newNode;

		// fix red red voilaton if exists
		fixRedRed(newNode);
		}
	}

	// utility function that deletes the node with given value
	void deleteByVal(value_type n) {
		if (root == NULL)
		// Tree is empty
		return;

		Node *v = search(n);

		if (v->data != n) {
		std::cout << "No node found to delete with value:" << n << std::endl;
		return;
		}

		deleteNode(v);
	}
	void print(Node *root, std::string indent, bool last)
	{
		if (root != NULL)
		{
			std::cout << indent;
			if (last)
			{
				std::cout << "R----";
				indent += "    ";
			}
			else
			{
				std::cout << "L----";
				indent += "|   ";
			}
			std::string sColor;
			if (root->color == RED)
			{
				sColor = "\x1b[31m";
				//out("ICI");
			}
			else
			{
				sColor = "\x1b[30m";
				//out("LA");
			}
			std::cout << sColor << "(" << root->data  << ")" << END << std::endl;
			print(root->left, indent,false);
			print(root->right, indent, true);
		}
	}
	void printTree()
			{
				//out("THERE");
				if (root)
				{
					print(this->root, "", true);
					//out(this->root->key);
				}
			}
	};

#endif
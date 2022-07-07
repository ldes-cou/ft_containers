/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:31:50 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/07 15:22:37 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP
#define B = "\x1b[30m"
#define R = "\x1b[31m"
# define END "\033[0m"
#include <cstddef>
#include <iostream>
#include "utils.hpp"
// #include "map_display.hpp"
// #ifndef VALUE_TYPE 
// #define VALUE_TYPE int

#define out(x) std::cout << x << std::endl;

#include <iostream>
#include <queue>
#define BLACK 0
#define RED 1
#include "Node.hpp"
#include "RB_tree_iterator.hpp"

namespace ft
{
	template <typename Key, typename T, typename T2, typename Compare = std::less<Key> >              		
		class RBTree//: public RB_Node<T>
		{
			typedef T																value_type;
			typedef RB_Node<T>														Node;
			typedef RB_Node<T>*     												Node_ptr;
			typedef	std::allocator<Node>											allocator_type; // regarder alloc map
			typedef typename allocator_type::template rebind<Node>::other			node_alloc;
			typedef	ft::_Rb_tree_iterator<T>										iterator;

			/******************************** MEMBER VARIABLES**********************************/

			private:
			Node 		*root;
			Node 		*root_parent;
			Node 		*Rnil;
			node_alloc	_alloc;

			public:

			size_t		t_size;
			Node *getRoot() { return root; }
			Node *geRnil() {return Rnil;}


			bool comp(value_type a, value_type b, Compare u = Compare())
			{
				return u(a.first, b.first);
			}

			/********************************** CONSTRUCTOR **********************************/

			RBTree()
			{
				Node tmp;

				root = NULL;
				
				this->Rnil = _alloc.allocate(1);
				_alloc.construct(this->Rnil, tmp);
				this->root_parent = _alloc.allocate(1);
				_alloc.construct(this->root_parent, tmp);
				
				this->t_size = 0;
			}

			// RBTree(const value_type &x)
			// {

			// }
			RBTree(const RBTree& x)
			{
				Node tmp;
				if (x != *this)
				{
					this->_alloc = x._alloc;
					Rnil = _alloc.allocate(1);
					_alloc.construct(this->Rnil, tmp);
					this->root_parent = _alloc.allocate(1);
					_alloc.construct(this->root_parent, tmp);
					
					root_parent = 0;
					this->t_size = x.t_size;
					root = NULL;
				}
			}
			void delete_nodes(Node *node)
			{
				if (node->right != Rnil && node != Rnil && node != NULL)
				{
					Node *right = node->right;
					Node *left = node->left;
					destroyNode(node);
					delete_nodes(left);
					delete_nodes(right);
				}
			}

			~RBTree ()
			{
				//delete_nodes(root);
				destroyNode(Rnil);
			}
			void	destroyNode(Node *node)
			{
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				t_size--;

			}
			
			/********************** SETTING AND UNSETTING NIL_LEAFS ***************/
			void	setRnilLeaf()
			{
				Node *max = maximum(root);
				//Node *min = minimum(root);

				Rnil->parent = max;
				max->right = this->Rnil;
				Rnil->parent->right = this->Rnil;

				root->parent = root_parent;
			}
			void	unsetRnilLeaf()
			{

				// if (Rnil->parent)
				// 	this->Rnil->parent->right = root_parent;
				// Rnil->parent = this->Rnil;
				// max->right = NULL;
				// Rnil->right = this->Rnil;
				// root->parent = NULL;
				// if (min->left == Rnil)
				// {
				// 	min->left = NULL;
				// }

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
				while (node->right != Rnil && node->right != NULL)
					node = node->right;
				return node;
			}
			// left rotates the given node
			


			/************************** SEARCH AND FIND *******************************/
			
			Node *search(value_type n) {
				Node *temp = root;
				while (temp != NULL)
				{
					if (comp(n, temp->data))
					{
						if (temp->left == NULL)
							break;
						else
							temp = temp->left;
					} 
					else if (n.first == temp->data.first)
						break;
					 else 
					 {
						if (temp->right == NULL)
							break;
						else
							temp = temp->right;
					}
				}
				return (temp);
			}
			Node *find(value_type n)
			{
				Node *toFind = search(n);
				if (toFind == NULL)
					return (Rnil);
				if (toFind->data == n)
					return (toFind);
				return (Rnil);
			}
			
	/*********************************** INSERT **********************************/
			void insert(value_type n) {

				Node tmp(n, Rnil);
				Node *newNode;
				//Node *newNode(n);
				newNode = _alloc.allocate(1);
				_alloc.construct(newNode, tmp);
				if (root == NULL)
				{
					newNode->color = BLACK;
					root = newNode;
				}
				else
				{
					unsetRnilLeaf();
					Node *temp = search(n);
					if (temp->data.first == n.first)
						return;
					newNode->parent = temp;
					if (comp(n, temp->data))
						temp->left = newNode;
					else
						temp->right = newNode;
					fixRedRed(newNode);
				}
				setRnilLeaf();
				newNode->T_nil = Rnil;
				this->t_size += 1;
			}
			
	/*********************************** DELETE FUNCTIONS **********************************/
			void deleteNode(Node *v)
			{
				Node *u = BSTreplace(v);
				bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
				Node *parent = v->parent;
				if (u == NULL) {
					if (v == root) {
						// v is root, making root null
						root = NULL;
					}
					else
					{
						if (uvBlack) {
							// u and v both black
							// v is leaf, fix double black at v
							fixDoubleBlack(v);
						}
						else
						{
							// u or v is red
							if (v->sibling() != NULL)
								// sibling is not null, make it red"
								v->sibling()->color = RED;
						}
						// delete v from the tree
						if (v->isOnLeft())
						{
							parent->left = NULL;
						}
						else
						{
							parent->right = NULL;
						}
					}
					destroyNode(v);
					return;
				}

				if (v->left == NULL or v->right == NULL) {
					// v has 1 child
					if (v == root) {
						// v is root, assign the value of u to v, and delete u
						swapValues(u, v);//v->data = u->data;
						v->left = v->right = NULL;
						//delete u;
						destroyNode(u);
					}
					else
					{
						// Detach v from tree and move u up
						if (v->isOnLeft()) {
							parent->left = u;
						} else {
							parent->right = u;
						}
						destroyNode(v);
						//delete v;
						u->parent = parent;
						if (uvBlack) {
							// u and v both black, fix double black at u
							fixDoubleBlack(u);
						} else {
							// u or v red, color u black
							u->color = BLACK;
						}
					}
					this->t_size -= 1;
					return;
				}
				// v has 2 children, swap values with successor and recurse
				swapValues(u, v);
				deleteNode(u);
			}
			
			bool deleteByVal(value_type n)
			{
				if (root == NULL)
					// Tree is empty
					return(false);
				Node *v = search(n);
				if (v->data.first != n.first)
				{
					return (false);
				}
				unsetRnilLeaf();
				deleteNode(v);
				setRnilLeaf();
				return (true);
			}
			
		/******************************* FIXING FUNCTIONS *****************************/
			
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
			
				void rightRotate(Node *x)
				{
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

			void swapColors(Node *x1, Node *x2)
			{
				int temp;

				temp = x1->color;
				x1->color = x2->color;
				x2->color = temp;
			}

			void swapValues(Node *u, Node *v)
			{
				 T2 temp;

				std::swap(const_cast<Key &>(u->data.first), const_cast<Key &>(v->data.first));
				temp = u->data.second;
				u->data.second = v->data.second;
				v->data.second = temp;
			}

			// fix red red at given node
			void fixRedRed(Node *x)
			{
				// if x is root color it black and return
				if (x == root) {
					x->color = BLACK;
					return;
				}
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

			void fixDoubleBlack(Node *x)
			{
				if (x == root)
					// Reached root
					return;
				Node *sibling = x->sibling(), *parent = x->parent;
				if (sibling == NULL)
				{
					// No sibiling, double black pushed up
					fixDoubleBlack(parent);
				} else
				{
					if (sibling->color == RED)
					{
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
					}
					else
					{
						// Sibling black
						if (sibling->hasRedChild())
						{
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
							}
							else
							{
								if (sibling->isOnLeft())
								{
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
						}
						else
						{
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
		/*********************************** PRINT **********************************/
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
};



#endif

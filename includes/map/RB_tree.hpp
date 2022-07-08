/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:52:33 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/08 17:52:06 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define B = "\x1b[30m"
#define R = "\x1b[31m"
# define END "\033[0m"
#include <cstddef>
#include <iostream>
#include "Node.hpp"
#include "utils.hpp"

// Implementing Red-Black Tree in C++

#include <iostream>
//using namespace std;

// struct Node {
// 	int data;
// 	Node *parent;
// 	Node *left;
// 	Node *right;
// 	int color;
// };

// typedef Node *Node_ptr;
struct RB_Node;
// using namespace  ft
namespace ft
{
	
	template <typename Key, typename T, typename T2, typename Compare = std::less<Key> >              		
	class RedBlackTree
	{
				typedef T																value_type;
				typedef RB_Node<T>														Node;
				typedef RB_Node<T>*     												Node_ptr;
				typedef	std::allocator<Node>											allocator_type; // regarder alloc map
				typedef typename allocator_type::template rebind<Node>::other			node_alloc;
				//typedef	ft::_Rb_tree_iterator<T>										iterator;
		private:
			Node_ptr root;
			Node_ptr TNULL;

			void initializeNULLNode(Node_ptr node, Node_ptr parent) {
				node->data = 0;
				node->parent = parent;
				node->left =  NULL;
				node->right = NULL;
				node->color = 0;
			}

			// Preorder
			void preOrderHelper(Node_ptr node) {
				if (node != TNULL) {
					std::cout << node->data << " ";
					preOrderHelper(node->left);
					preOrderHelper(node->right);
				}
			}

			// Inorder
			void inOrderHelper(Node_ptr node) {
				if (node != TNULL) {
					inOrderHelper(node->left);
					std::cout << node->data << " ";
					inOrderHelper(node->right);
				}
			}

			// Post order
			void postOrderHelper(Node_ptr node) {
				if (node != TNULL) {
					postOrderHelper(node->left);
					postOrderHelper(node->right);
					std::cout << node->data << " ";
				}
			}

			Node_ptr searchTreeHelper(Node_ptr node, value_type key) {
				if (node == TNULL || key == node->data) {
					return node;
				}

				if (key < node->data) {
					return searchTreeHelper(node->left, key);
				}
				return searchTreeHelper(node->right, key);
			}

			// For balancing the tree after deletion
			void deleteFix(Node_ptr x)
			{
				Node_ptr s;
				while (x != root && x->color == 0)
		{
					if (x == x->parent->left) {
						s = x->parent->right;
						if (s->color == 1) {
							s->color = 0;
							x->parent->color = 1;
							leftRotate(x->parent);
							s = x->parent->right;
						}

						if (s->left->color == 0 && s->right->color == 0) {
							s->color = 1;
							x = x->parent;
						} else {
							if (s->right->color == 0) {
								s->left->color = 0;
								s->color = 1;
								rightRotate(s);
								s = x->parent->right;
							}

							s->color = x->parent->color;
							x->parent->color = 0;
							s->right->color = 0;
							leftRotate(x->parent);
							x = root;
						}
					} else {
						s = x->parent->left;
						if (s->color == 1) {
							s->color = 0;
							x->parent->color = 1;
							rightRotate(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == 0 && s->right->color == 0) {
							s->color = 1;
							x = x->parent;
						} else {
							if (s->left->color == 0) {
								s->right->color = 0;
								s->color = 1;
								leftRotate(s);
								s = x->parent->left;
							}

							s->color = x->parent->color;
							x->parent->color = 0;
							s->left->color = 0;
							rightRotate(x->parent);
							x = root;
						}
					}
				}
				x->color = 0;
			}

			void rbTransplant(Node_ptr u, Node_ptr v)
		{
				if (u->parent == NULL)
		{
					root = v;
				}
		else if
		(u == u->parent->left)
		{
					u->parent->left = v;
				} else {
					u->parent->right = v;
				}
				v->parent = u->parent;
			}

			void deleteNodeHelper(Node_ptr node, value_type key)
		{
				Node_ptr z = TNULL;
				Node_ptr x, y;
				while (node != TNULL)
		{
					if (node->data == key)
			{
						z = node;
					}
					if (node->data <= key)
			{
						node = node->right;
					} 
			else
			{
						node = node->left;
					}
				}

				if (z == TNULL) {
					std::cout << "Key not found in the tree" << std::endl;
					return;
				}
				y = z;
				int y_original_color = y->color;
				if (z->left == TNULL) {
					x = z->right;
					rbTransplant(z, z->right);
				} else if (z->right == TNULL) {
					x = z->left;
					rbTransplant(z, z->left);
				} else {
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z) {
						x->parent = y;
					} else {
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}

					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				delete z;
				if (y_original_color == 0) {
					deleteFix(x);
				}
			}

			// For balancing the tree after insertion
			void insertFix(Node_ptr k) {
				Node_ptr u;
				while (k->parent->color == 1) {
					if (k->parent == k->parent->parent->right) {
						u = k->parent->parent->left;
						if (u->color == 1) {
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						} else {
							if (k == k->parent->left) {
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							leftRotate(k->parent->parent);
						}
					} else {
						u = k->parent->parent->right;

						if (u->color == 1) {
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						} else {
							if (k == k->parent->right) {
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							rightRotate(k->parent->parent);
						}
					}
					if (k == root) {
						break;
					}
				}
				root->color = 0;
			}

			void printHelper(Node_ptr root, std::string indent, bool last) {
				if (root != TNULL) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "   ";
					} else {
						std::cout << "L----";
						indent += "|  ";
					}

					std::string sColor = root->color ? "RED" : "BLACK";
					std::cout << root->data << "(" << sColor << ")" << std::endl;
					printHelper(root->left, indent, false);
					printHelper(root->right, indent, true);
				}
			}

		public:
			RedBlackTree() {
				TNULL = new Node;
				TNULL->color = 0;
				TNULL->left = NULL;
				TNULL->right = NULL;
				root = TNULL;
			}

			void preorder() {
				preOrderHelper(this->root);
			}

			void inorder() {
				inOrderHelper(this->root);
			}

			void postorder() {
				postOrderHelper(this->root);
			}

			Node_ptr searchTree(value_type k) {
				return searchTreeHelper(this->root, k);
			}

			Node_ptr minimum(Node_ptr node) {
				while (node->left != TNULL) {
					node = node->left;
				}
				return node;
			}

			Node_ptr maximum(Node_ptr node) {
				while (node->right != TNULL) {
					node = node->right;
				}
				return node;
			}

			Node_ptr successor(Node_ptr x) {
				if (x->right != TNULL) {
					return minimum(x->right);
				}

				Node_ptr y = x->parent;
				while (y != TNULL && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			Node_ptr predecessor(Node_ptr x) {
				if (x->left != TNULL) {
					return maximum(x->left);
				}

				Node_ptr y = x->parent;
				while (y != TNULL && x == y->left) {
					x = y;
					y = y->parent;
				}

				return y;
			}

			void leftRotate(Node_ptr x) {
				Node_ptr y = x->right;
				x->right = y->left;
				if (y->left != TNULL) {
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL) {
					this->root = y;
				} else if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}

			void rightRotate(Node_ptr x) {
				Node_ptr y = x->left;
				x->left = y->right;
				if (y->right != TNULL) {
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL) {
					this->root = y;
				} else if (x == x->parent->right) {
					x->parent->right = y;
				} else {
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}

			// Inserting a node
			void insert(value_type key)
		{
				Node_ptr node = new Node;
				node->parent = NULL;
				node->data = key;
				node->left = TNULL;
				node->right = TNULL;
				node->color = 1;

				Node_ptr y = NULL;
				Node_ptr x = this->root;

				while (x != TNULL)
		{
					y = x;
					if (node->data < x->data)
			{
						x = x->left;
					} else {
						x = x->right;
					}
				}

				node->parent = y;
				if (y == NULL)
		{
					root = node;
				}
		else if (node->data < y->data)
		{
					y->left = node;
				} else {
					y->right = node;
				}

				if (node->parent == NULL)
		{
					node->color = 0;
					return;
				}

				if (node->parent->parent == NULL)
		{
					return;
				}
				insertFix(node);
			}

			Node_ptr getRoot() {
				return this->root;
			}

			void deleteNode(value_type data) {
				deleteNodeHelper(this->root, data);
			}

			void printTree() {
				if (root) {
					printHelper(this->root, "", true);
				}
			}
		

	};
} // namespace ft



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:52:33 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/19 12:54:47 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#define B = "\x1b[30m"
#define R = "\x1b[31m"
# define END "\033[0m"
#include <cstddef>
#include <iostream>
#include "Node.hpp"
#include "utils.hpp"
#include "RB_tree_iterator.hpp"


struct RB_Node;

namespace ft
{
	
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<T> >              		
	class RBTree
	{
				typedef T																value_type;
				typedef RB_Node<T>														Node;
				typedef RB_Node<T>*     												Node_ptr;
				typedef	std::allocator<Node>											allocator_type;
				typedef typename allocator_type::template rebind<Node>::other			node_alloc;
				typedef	_Rb_tree_iterator<T>											iterator;
				typedef typename allocator_type::size_type								size_type;
				typedef	Compare															value_compare;
		private:
			Node_ptr 	_root;
			Node_ptr 	_TNULL;
			node_alloc	_alloc;
			size_type 	_size;
			

		bool _comp(value_type a, value_type b, value_compare u = value_compare()) const
		{
			return u(a.first, b.first);
		}
		

		Node_ptr searchTreeHelper(Node_ptr node, value_type key) const
		{
			if (node == _TNULL || key.first == node->data.first)
			{
				return node;
			}
			if (_comp(key, node->data))
			{
				return searchTreeHelper(node->left, key);
			}
			return searchTreeHelper(node->right, key);
		}

		
		void deleteFix(Node_ptr x)
		{
			Node_ptr s;
			while (x != _root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						leftRotate(x->parent);
						s = x->parent->right;
					}
					if (s->left->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->right->color == BLACK)
						{
							s->left->color = BLACK;
							s->color = RED;
							rightRotate(s);
							s = x->parent->right;
						}

						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						leftRotate(x->parent);
						x = _root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						rightRotate(x->parent);
						s = x->parent->left;
					}

					if (s->right->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->left->color == BLACK)
						{
							s->right->color = BLACK;
							s->color = RED;
							leftRotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						rightRotate(x->parent);
						x = _root;
					}
				}
			}
			x->color = BLACK;
		}

		void rbTransplant(Node_ptr u, Node_ptr v)
		{
			if (u->parent == NULL)
			{
				_root = v;
			}
			else if (u == u->parent->left)
			{
				u->parent->left = v;
			}
			else
			{
				u->parent->right = v;
			}
			v->parent = u->parent;
		}

		size_type deleteNodeHelper(Node_ptr node, value_type key)
		{
			Node_ptr z = _TNULL;
			Node_ptr x, y;
			while (node != _TNULL)
			{
				if (node->data.first == key.first)
				{
					z = node;
				}
				if (node->data.first <= key.first)
				{
					node = node->right;
				} 
				else
				{
					node = node->left;
				}
			}
			if (z == _TNULL)	
				return (0);
			y = z;
			int y_original_color = y->color;
			if (z->left == _TNULL)
			{
				x = z->right;
				rbTransplant(z, z->right);
			}
			else if
			(z->right == _TNULL)
			{
				x = z->left;
				rbTransplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
				{
					x->parent = y;
				}
				else
				{
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			destroyNode(z);
			if (y_original_color == BLACK)
			{
				deleteFix(x);
			}
			_size--;
			return (1);
		}
		
		void insertFix(Node_ptr k)
		{
			Node_ptr u;
			while (k->parent->color == RED)
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left;
					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						leftRotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->right;
					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->right)
						{
							k = k->parent;
							leftRotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						rightRotate(k->parent->parent);
					}
				}
				if (k == _root) 
				{
					break;
				}
			}
			_root->color = BLACK;
		}

		void printHelper(Node_ptr _root, std::string indent, bool last) {
			if (_root != _TNULL) {
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "   ";
				} else {
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = _root->color ? "RED" : "BLACK";
				std::cout << _root->data << "(" << sColor << ")" << std::endl;
				printHelper(_root->left, indent, false);
				printHelper(_root->right, indent, true);
			}
		}

	public:
		RBTree (const node_alloc& node_al = node_alloc()) : _alloc(node_al)
		{
				_TNULL = createNode();
				_TNULL->color = BLACK;
				_TNULL->left = NULL;
				_TNULL->right = NULL;
				_root = _TNULL;
				_size = 0;
			}
		
		RBTree (RBTree const& rhs):_alloc(rhs._alloc)
		{
			_TNULL = createNode();
			_root = _TNULL;
			*this = rhs;
		}

		~RBTree()
		{
			if (_root != _TNULL)
				deleteTree(_root);
			destroyNode(_TNULL);
		}
		
		Node_ptr createNode()
		{
			Node tmp;
			Node_ptr NewNode;
			NewNode = _alloc.allocate(1);
			_alloc.construct(NewNode, tmp);
			return (NewNode);
		}
		
		void destroyNode(Node_ptr node)
		{
			_alloc.deallocate(node, 1);
			//_alloc.destroy(node);
		}
		void deleteTree(Node_ptr node)
		{
			if (node == _TNULL)
				return;

			deleteTree(node->left);
			deleteTree(node->right);
			destroyNode(node);
		}
		
		Node_ptr searchTree(value_type k) const
		{
			return searchTreeHelper(this->_root, k);
		}
		
		bool isInTree(value_type k)
		{
			if (searchTree(k) == _TNULL)
				return (false);
			return true;
		}
		
		Node_ptr minimum(Node_ptr node) const
		{
			if (node != _TNULL)
			{
				while (node->left != _TNULL)
				{
					node = node->left;
				}
			}
			return node;
		}

		Node_ptr maximum(Node_ptr node) const
		{
			if (node != _TNULL)
			{
				while (node->right != _TNULL)
				{
					node = node->right;
				}
			}
			return node;
		}

		void leftRotate(Node_ptr x)
		{
			Node_ptr y = x->right;
			x->right = y->left;
			if (y->left != _TNULL)
			{
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL)
			{
				this->_root = y;
			}
			else if (x == x->parent->left)
			{
				x->parent->left = y;
			} else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void rightRotate(Node_ptr x)
		{
			Node_ptr y = x->left;
			x->left = y->right;
			if (y->right != _TNULL)
			{
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL)
			{
				this->_root = y;
			}
			else if (x == x->parent->right)
			{
				x->parent->right = y;
			}
			else
			{
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		
		bool insert(value_type key)
		{
			Node *toFind = searchTree(key);
			if (toFind != _TNULL)
				return (false);
			Node_ptr node = createNode();
			node->parent = NULL;
			Key *key_node = const_cast<Key*>(&node->data.first);
			*key_node = key.first;
			
			node->data.second = key.second;
			node->left = _TNULL;
			node->right = _TNULL;
			node->color = RED;
			_size++;
			
			Node_ptr y = NULL;
			Node_ptr x = this->_root;
			while (x != _TNULL)
			{
				y = x;
				if (_comp(node->data, x->data))
				{
					x = x->left;
				} 
				else
				{
					x = x->right;
				}
			}
			node->parent = y;
			if (y == NULL)
			{
				_root = node;
			}
			else if (_comp(node->data, y->data))
			{
				y->left = node;
			}
			else
			{
				y->right = node;
			}
			if (node->parent == NULL)
			{
				node->color = BLACK;
				return (true);
			}
			if (node->parent->parent == NULL)
			{
				return (true);
			}
			insertFix(node);
			return (true);
		}
		size_type deleteNode(value_type data)
		{
			return (deleteNodeHelper(this->_root, data));
		}

		void printTree()
		{
			if (_root) {
				printHelper(this->_root, "", true);
			}
		}

		Node_ptr getRoot() const { return ( this->_root ) ;}
		
		Node_ptr getTNULL() const { return (this->_TNULL ) ;}

		size_type getSize() const {return (this->_size );}
		
		void swap(RBTree &_x)
		{
			std::swap(_x._root, _root);
			std::swap(_x._TNULL, _TNULL);
			std::swap(_x._alloc, _alloc);
			std::swap(_x._size, _size);
		}
	};
	

}// namespace ft

#endif

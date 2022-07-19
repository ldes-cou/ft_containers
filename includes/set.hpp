/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:49:18 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/19 19:10:51 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP
#include <iostream>
#include "RB_tree_iterator.hpp"
#include "iterator_base_type.hpp"
#include "distance.hpp"
#include "lexicograpical_compare.hpp"
#include "stack.hpp"
#include "equal.hpp"
#include "utils.hpp"


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
			return u(a, b);
		}
		

		Node_ptr searchTreeHelper(Node_ptr node, value_type key) const
		{
			if (node == _TNULL || key == node->data)
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
			Key *key_node = const_cast<Key*>(&node->data);
			*key_node = key;
			
			node->data = key;
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
	
	
	template <class T,                                       				                            // map::mapped_type
			class Compare = std::less<T>,                     		                            // map::key_compare
			class Alloc = std::allocator<T> >	                            						// map::allocator_type
	class set
	{
		public :
			typedef T														key_type;	                    //The first template parameter (Key)	                //The second template parameter (T)	
			typedef T														value_type;                      //pair<const key_type,mapped_type>	
			typedef Compare													key_compare;					//The third template parameter (Compare)	defaults to: less<key_type>
			typedef Compare													value_compare;                           			
			typedef Alloc													allocator_type;                                    				//The fourth template parameter (Alloc)	defaults to: allocator<value_type>
			typedef	typename Alloc::reference								reference;											            //for the default allocator: value_type&
			typedef typename Alloc::const_reference							const_reference;									 			//for the default allocator: const value_type&
			typedef typename Alloc::pointer									pointer;	                    				                //for the default allocator: value_type*
			typedef typename Alloc::const_pointer							const_pointer;		    										//for the default allocator: const value_type*
			typedef ft::_Rb_tree_iterator<value_type>						iterator;														//convertible to const_iterator
			typedef ft::_Rb_tree_const_iterator<value_type> 				const_iterator;													//a bidirectional iterator to const value_type	
			typedef ft::reverse_iterator<iterator>							reverse_iterator;												//reverse_iterator<iterator>
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;											//reverse_iterator<const_iterator>	
			typedef	typename iterator_traits<iterator>::difference_type		difference_type;												//a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
			typedef typename allocator_type::size_type						size_type;

			private:
			
			allocator_type											_alloc;
			Compare													_comp;
			RBTree<key_type, value_type, value_compare, Alloc>		_rbtree;
			
				
		/********************************************** CONSTRUCTORS ****************************************/
		
		public :
			/* default */
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_comp(comp),
				_rbtree(_alloc)
			{}
			
			/* range */  
			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
				const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp), _rbtree()
			{
				insert(first, last);
			}

			/* copy */
			set (const set& x): _alloc(x._alloc), _comp(x._comp), _rbtree(_alloc) 
			{
				insert(x.begin(), x.end());
			}
			
			set& operator=(const set& x)
			{
				if (x != *this)
				{
					if (size() != 0)
						clear();
					_comp = x._comp;
					_alloc = x._alloc;
					insert(x.begin(), x.end());
				}
				return (*this);
			}
			~set()
			{}
			/********************************************** ITERATORS ****************************************/
            
			iterator begin()
			{
				return (iterator(_rbtree.minimum(_rbtree.getRoot()), _rbtree.getTNULL(), _rbtree.getRoot()));
			}
			
			const_iterator begin() const
			{
				return (const_iterator(_rbtree.minimum(_rbtree.getRoot()), _rbtree.getTNULL(), _rbtree.getRoot()));
			}
			
			iterator end()
			{
				return (iterator(_rbtree.getTNULL(), _rbtree.getTNULL(), _rbtree.getRoot()));
			}
			
			const_iterator end() const
			{
				return (const_iterator(_rbtree.getTNULL(), _rbtree.getTNULL(), _rbtree.getRoot())); 
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end()));
			}
			
			const_reverse_iterator rbegin() const
			{	
				return (const_reverse_iterator(this->end()));
			}
			
			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin()));
			}
			
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin()));
			}
            /**********************************************     CAPACITY    ****************************************/

            bool empty() const
			{
				if (this->_rbtree.getSize() == 0)
					return (true);
				return (false);
			}
			
			size_type max_size() const
			{
				return (_alloc.max_size());
			}
			
			size_type	size() const
			{
				return (this->_rbtree.getSize());
			}
            
            /**********************************************     MODIFIERS        ****************************************/
            
            	template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				for (;first != last; first++)
					insert(*first);
			}
			
			ft::pair<iterator, bool> insert( const value_type& value )
			{
				iterator it;
				it = iterator(_rbtree.searchTree(value), _rbtree.getTNULL(), _rbtree.getRoot());
				if (it != this->end())
					return (ft::make_pair(it, false));
				else
				{
					_rbtree.insert(value);
					it = iterator(_rbtree.searchTree(value), _rbtree.getTNULL(), _rbtree.getRoot());
					return (ft::make_pair(it, true));
				}
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				if (_rbtree.insert(val) == true)
					return (iterator(_rbtree.searchTree(val), _rbtree.getTNULL(), _rbtree.getRoot()));
				return (end());
			}

			void erase (iterator position)
			{
				_rbtree.deleteNode(*position);
			}

			size_type erase (const value_type& k)
			{
				//value_type	toErase = ft::make_pair(k, mapped_type());
				return(_rbtree.deleteNode(k));
			}
			
     		void erase (iterator first, iterator last)
			{
				ft::stack<value_type>	save;
				while (first != last)
				{
					save.push(*first);
					first++;
				}
				while (!save.empty())
				{

					this->erase(save.top());
					save.pop();
				}
			}
			
			void swap(set & __x)
			{
				this->_rbtree.swap(__x._rbtree);
			}
			
			void clear()
			{
				erase(begin(), end());
			}
			/**********************************************     OBSERVERS        ****************************************/
            
            key_compare	key_comp(void) const
			{
				return (_comp);
			}
			
			value_compare	value_comp(void) const
			{
				return (value_compare(key_comp()));
			}
            
            /**********************************************     OPERATIONS        ****************************************/
		
			iterator find (const value_type& k)
			{
				//value_type toFind = ft::make_pair(k, mapped_type());
				iterator it = iterator(_rbtree.searchTree(k), _rbtree.getTNULL(), _rbtree.getRoot());
				return (it);
			}
			
			const_iterator find (const value_type& k) const
			{
				//value_type toFind = ft::make_pair(k, mapped_type());
				const_iterator it = const_iterator(_rbtree.searchTree(k), _rbtree.getTNULL(), _rbtree.getRoot());
				return (it);
			}
			
			size_type count (const value_type& k) const
			{
				if (find(k) != end())
					return (1);
				return (0);
			}
			iterator lower_bound (const value_type& k)
			{
				
				iterator it = begin();
				while(it != end() )
				{
					if (!_comp(*it, k))
						break;
					++it;
				}
				return (it);

			}
			const_iterator lower_bound (const value_type& k) const
			{
				const_iterator it = begin();
				while(it != end())
				{
					if(!_comp(*it, k))
						break;
					it++;
				}
				return (it);
			}
			iterator upper_bound( const value_type & k )
			{
				iterator it = begin();
				while(it != end())
				{
					if(_comp(k, *it))
						break;
					++it;
				}
				return (it);
			}
			
			const_iterator upper_bound( const value_type & k ) const
			{
				const_iterator it = begin();
				while(it != end())
				{
					if(_comp(k, *it))
						break;
					++it;
				}
				return (it);
			}
			pair<iterator,iterator>             equal_range (const value_type& k)
			{
				iterator it = lower_bound (k);
  				return ft::make_pair ( it, upper_bound(k) );	
			}
			
			pair<const_iterator,const_iterator> equal_range (const value_type& k) const
			{
				const_iterator it = lower_bound (k);
  				return ft::make_pair ( it, upper_bound(k) );	
			}
			
            
            /**********************************************     GET_ALLOCATOR        ****************************************/
            
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			
	};
			
	template<typename _Val, typename _Compare, typename _Alloc>
    inline bool operator==(const ft::set<_Val, _Compare, _Alloc>& __x, const ft::set<_Val, _Compare, _Alloc>& __y)
    {
      return __x.size() == __y.size()
             && ft::equal(__x.begin(), __x.end(), __y.begin());
    }
	
  	template<typename _Val, typename _Compare, typename _Alloc>
    inline bool operator<(const ft::set<_Val, _Compare, _Alloc>& __x,
              const ft::set<_Val, _Compare, _Alloc>& __y)
    {
      return ft::lexicographical_compare(__x.begin(), __x.end(), 
                                          __y.begin(), __y.end());
    }
  	
	template<typename _Val, typename _Compare, typename _Alloc>
    inline bool operator!=(const ft::set<_Val, _Compare, _Alloc>& __x,
               const set<_Val, _Compare, _Alloc>& __y)
    { return !(__x == __y); }
  	
	template<typename _Val, typename _Compare, typename _Alloc>
    inline bool operator>(const ft::set<_Val, _Compare, _Alloc>& __x,
              const ft::set<_Val, _Compare, _Alloc>& __y)
    { return __y < __x; }
  	
	template<typename _Val, typename _Compare, typename _Alloc>
    inline bool operator<=(const ft::set<_Val, _Compare, _Alloc>& __x,
               const ft::set<_Val, _Compare, _Alloc>& __y)
    { return !(__y < __x); }
  	
	template<typename _Val, typename _Compare, typename _Alloc>
    inline bool operator>=(const ft::set<_Val, _Compare, _Alloc>& __x,
               const ft::set<_Val, _Compare, _Alloc>& __y)
    { return !(__x < __y); }
	
	template<typename _Val, typename _Compare, typename _Alloc>
    inline void swap (ft::set<_Val, _Compare, _Alloc>& __x, ft::set<_Val, _Compare, _Alloc>& __y)
    { __x.swap(__y); }


};

#endif
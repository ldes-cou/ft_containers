/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:27:28 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/12 16:04:18 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP
//#include "RB_tree.hpp"
#include "Node.hpp"
#include "vector/iterator.hpp"

template<typename _Tp>
class RBTree;

namespace ft
{
	
	template<typename _Tp>
	struct _Rb_tree_iterator 
	{
		//friend class									RBTree;
		typedef _Tp                       		        value_type;
		typedef _Tp&                      		        reference;
		typedef _Tp*                      		        pointer;
		typedef bidirectional_iterator_tag		        iterator_category;
		typedef ptrdiff_t		          		        difference_type;
		typedef _Rb_tree_iterator<_Tp>	                _Self;
		typedef	typename RB_Node<_Tp>::Node_ptr	        Node_ptr;
		
        private:
			Node_ptr        _M_node;
			Node_ptr		_NULL;
			// friend			typename RBTree<_Tp>.Rnil		Rnil;
		/***************************** CONSTRUCTORS ***********************************/
		public:
		_Rb_tree_iterator() : _M_node(), _NULL(NULL) { }

		explicit
		_Rb_tree_iterator(Node_ptr __x, Node_ptr TNULL) : _M_node(__x), _NULL(TNULL) { }
		
		Node_ptr min(Node_ptr node)
		{
			if (node != _NULL)
			{
				while (node->left != _NULL)
				{
					node = node->left;
				}
			}
			return node;
		}

		Node_ptr max(Node_ptr node)
		{
			if (node != _NULL)
			{
				while (node->right != _NULL)
				{
					node = node->right;
				}
			}
			return node;
		}
			
		Node_ptr	_next(Node_ptr node)
		{
				if (node->right != this->_NULL)
					return (this->min(node->right));
				Node_ptr parent = node->parent;
				while (parent != this->_NULL && node == parent->right)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
		}

		Node_ptr	_prev(Node_ptr node)
		{
			if (node->left != this->_NULL)
				return (this->max(node->left));
			Node_ptr parent = node->parent;
			while (parent != this->_NULL && node == parent->left) {
				node = parent;
				parent = parent->parent;
			}
			return (parent);
		}
	
		/****************************** OPERATORS ************************************/
		
		reference operator*() const 
		{ return (_M_node->data); }

		pointer operator->() const
		{ return (&(_M_node->data)); }
		
		_Self&  operator++()
		{ 
			_M_node = this->_next(_M_node);
			return (*this);
		}

		_Self operator++(int)
		{ 
			_Self __tmp = *this;
			_M_node = this->_next(_M_node);
			return (__tmp);
		}

		_Self& operator--()
		{
			_M_node = this->_prev(_M_node);
			return *this;
		}

		_Self operator--(int)
		{
			_Self __tmp = *this;
			_M_node = this->_prev(_M_node);
			return __tmp;
		}

		bool operator==(const _Self& __x) const
		{
			return _M_node == __x._M_node;
		}
		bool operator!=(const _Self& __x) const
		{
			return _M_node != __x._M_node;
		}
		operator	_Rb_tree_iterator<value_type const>(void) const
		{
				return (_Rb_tree_iterator<value_type const>(_M_node, this->_NULL));
			}

	};
	
	template<typename _Tp>
	
    struct _Rb_tree_const_iterator
    {
		typedef _Tp									 value_type;
		typedef const _Tp& 							reference;
		typedef const _Tp* 							pointer;
		typedef _Rb_tree_iterator<_Tp> 				iterator;
		typedef bidirectional_iterator_tag 			iterator_category;
		typedef ptrdiff_t			 				difference_type;
		typedef _Rb_tree_const_iterator<_Tp>		_Self;
		typedef typename RB_Node<_Tp>::Node_ptr		Node_ptr;

		private:
			Node_ptr _M_node;
			Node_ptr _NULL;
		
		public:

		/***************************** CONSTRUCTORS ***********************************/
		
		_Rb_tree_const_iterator() : _M_node(NULL), _NULL(NULL) { }
		
		explicit
		_Rb_tree_const_iterator(Node_ptr __x) : _M_node(__x) { }
		
		_Rb_tree_const_iterator(const iterator& __it) : _M_node(__it._M_node) { }

		/****************************** OPERATORS ************************************/
		Node_ptr min(Node_ptr node)
		{
			if (node != _NULL)
			{
				while (node->left != _NULL)
				{
					node = node->left;
				}
			}
			return node;
		}

		Node_ptr max(Node_ptr node)
		{
			if (node != _NULL)
			{
				while (node->right != _NULL)
				{
					node = node->right;
				}
			}
			return node;
		}
			
		Node_ptr	_next(Node_ptr node)
		{
				if (node->right != this->_NULL)
					return (this->min(node->right));
				Node_ptr parent = node->parent;
				while (parent != this->_NULL && node == parent->right) {
					node = parent;
					parent = parent->parent;
				}
				return (parent);
		}

		Node_ptr	_prev(Node_ptr node)
		{
			if (node->left != this->_NULL)
				return (this->max(node->left));
			Node_ptr parent = node->parent;
			while (parent != this->_NULL && node == parent->left) {
				node = parent;
				parent = parent->parent;
			}
			return (parent);
		}
		
		iterator _M_const_cast() const
		{ return iterator(const_cast<typename iterator::Node_ptr>(_M_node)); }
		
		reference operator*() const
		{ return (_M_node->data); }
		
		pointer operator->() const
		{ return (&(_M_node->data)) ; }
		
		_Self& operator++()
		{
			_M_node = _next(_M_node);
			return *this;
		}
		
		_Self operator++(int)
		{
			_Self __tmp = *this;
			_M_node = _next(_M_node);
			return __tmp;
		}
		
		_Self& operator--()
		{
			_M_node = _prev(_M_node);
			return *this;
		}
		
		_Self operator--(int)
		{
			_Self __tmp = *this;
			_M_node = _prev(_M_node);
			return __tmp;
		}
		bool operator==(const _Self& __x) const
		{ return _M_node == __x._M_node; }
		
		bool operator!=(const _Self& __x) const
		{ return _M_node != __x._M_node; }
		
};
	template<typename _Val> inline bool
    operator==(const _Rb_tree_iterator<_Val>& __x,  const _Rb_tree_const_iterator<_Val>& __y)
    { return __x._M_node == __y._M_node; }
	
  	template<typename _Val>
    inline bool operator!=(const _Rb_tree_iterator<_Val>& __x, const _Rb_tree_const_iterator<_Val>& __y)
    { return __x._M_node != __y._M_node; }
};
#endif

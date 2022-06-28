/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucrece <lucrece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:27:28 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/28 14:52:41 by lucrece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
#define RB_TREE_HPP
#include "RB_tree.hpp"
#include "../vector/iterator.hpp"

namespace ft
{
	
	template<typename _Tp>
	struct _Rb_tree_iterator
	{
		typedef _Tp                       		        value_type;
		typedef _Tp&                      		        reference;
		typedef _Tp*                      		        pointer;
		typedef bidirectional_iterator_tag		        iterator_category;
		typedef ptrdiff_t		          		        difference_type;
		typedef _Rb_tree_iterator<_Tp>	                		_Self;
		typedef typename	ft::RB_Node<_Tp>::Node_ptr	         _Base_ptr;
		
        private:
			_Base_ptr        _M_node;
            
		/***************************** CONSTRUCTORS ***********************************/
		public:
		_Rb_tree_iterator() : _M_node() { }

		explicit
		_Rb_tree_iterator(_Base_ptr __x) : _M_node(__x) { }

		
		//_Rb_tree_iterator(const iterator& __it) : _M_node(__it._M_node) { }
		
		/****************************** OPERATORS ************************************/
		
		reference operator*() const 
		{ return (_M_node->data); }

		pointer operator->() const
		{ return (&(_M_node->data)); }
		
		_Self&  operator++()
		{ 
			_M_node = _Rb_tree_increment(_M_node);
			return (*this);
		}

		_Self operator++(int)
		{ 
			_Self __tmp = *this;
			_M_node = _Rb_tree_increment(_M_node);
			return (__tmp);
		}

		_Self& operator--()
		{
			_M_node = _Rb_tree_decrement(_M_node);
			return *this;
		}

		_Self operator--(int)
		{
			_Self __tmp = *this;
			_M_node = _Rb_tree_decrement(_M_node);
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
		typedef typename ft::RB_Node<_Tp>::Node_ptr			_Base_ptr;

		private:
			_Base_ptr _M_node;
		
		public:

		/***************************** CONSTRUCTORS ***********************************/
		
		_Rb_tree_const_iterator() : _M_node() { }
		
		explicit
		_Rb_tree_const_iterator(_Base_ptr __x) : _M_node(__x) { }
		
		_Rb_tree_const_iterator(const iterator& __it) : _M_node(__it._M_node) { }

		/****************************** OPERATORS ************************************/
		
		iterator _M_const_cast() const
		{ return iterator(const_cast<typename iterator::_Base_ptr>(_M_node)); }
		
		reference operator*() const
		{ return (_M_node->data); }
		
		pointer operator->() const
		{ return (&(_M_node->data)) ; }
		
		_Self& operator++()
		{
			_M_node = _Rb_tree_increment(_M_node);
			return *this;
		}
		
		_Self operator++(int)
		{
			_Self __tmp = *this;
			_M_node = _Rb_tree_increment(_M_node);
			return __tmp;
		}
		
		_Self& operator--()
		{
			_M_node = _Rb_tree_decrement(_M_node);
			return *this;
		}
		
		_Self operator--(int)
		{
			_Self __tmp = *this;
			_M_node = _Rb_tree_decrement(_M_node);
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

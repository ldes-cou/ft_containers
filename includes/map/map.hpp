/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:49:18 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/14 16:53:30 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include "RB_tree.hpp"
#include "RB_tree_iterator.hpp"
// #include "vector/iterator_base_type.hpp"
// #include "vector/utils.hpp"
// #include "vector/lexicograpical_compare.hpp"
// #include "vector/equal.hpp"
#include "iterator_base_type.hpp"
#include "utils.hpp"
#include "lexicograpical_compare.hpp"
#include "equal.hpp"

namespace ft
{
		
	template < class Key,                                     			// map::key_type
			class T,                                       				// map::mapped_type
			class Compare = std::less<Key>,                     		// map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T> > >    	// map::allocator_type
	class map
	{
		public :
			typedef Key												key_type;	                    //The first template parameter (Key)	
			typedef T												mapped_type;                    //The second template parameter (T)	
			typedef typename ft::pair<const key_type, mapped_type>	value_type;                      //pair<const key_type,mapped_type>	
			typedef Compare											key_compare;					//The third template parameter (Compare)	defaults to: less<key_type>
			friend struct RB_Node<value_type>;
			class value_compare : std::binary_function<value_type, 	value_type, bool>				//Nested function class to compare elements	see value_comp
			{
				friend class map<key_type, value_type, key_compare>;
				//friend class RBTree<key_type, value_type, value_compare, Alloc>
				//protected:
				public:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				//public:
					bool operator() (const value_type& x, const value_type& y) const
					{ return (comp(x.first, y.first)); }
			};
			                           			
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

			allocator_type											_alloc;
			Compare													_comp;
			RBTree<key_type, value_type, key_compare, Alloc>		_rbtree;
			
			private:
				
		/********************************************** CONSTRUCTORS ****************************************/
		
		public :
			/* default */
			//map() : _rbtree() { }
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:
				_alloc(alloc),
				_comp(comp),
				_rbtree(_alloc)
			{}
			/* range */  
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
				const allocator_type& alloc = allocator_type()): _rbtree(), _comp(comp), _alloc(alloc)
			{
				insert(first, last);
			}

			/* copy */
			map (const map& x): _rbtree(x.rbtree), _comp(x.comp), _alloc(x._alloc)
			{
				*this = x;
			}
			
			map& operator=(const map& x)
			{
				if (x != *this)
				{
					clear();
					insert(this->begin(), this->end());
				}
				return (*this);
			}
			~map()
			{}
			
			mapped_type& operator[] (const key_type& k)
			{
				iterator toFind = find(k);
				if (toFind != end())
					return (toFind->second);
				return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
			}
			
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
				const_iterator it = const_iterator(_rbtree.getTNULL(), _rbtree.getTNULL(), _rbtree.getRoot());
				return (it); //ici pb
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

			void erase (iterator position)
			{
				_rbtree.deleteNode(*position);
			}

			size_type erase (const key_type& k)
			{
				value_type	toErase = ft::make_pair(k, mapped_type());
				return(_rbtree.deleteNode(toErase));
			}
			
     		void erase (iterator first, iterator last)
			{
				iterator tmp;
				while( first != last )
				{
					tmp = first++;
					erase(tmp);
				}
			}
			
			void swap(map& __x) //_GLIBCXX_NOEXCEPT_IF(__is_nothrow_swappable<_Compare>::value)
			{ _rbtree.swap(__x._rbtree); }
			
			void clear()
			{
				erase(begin(), end());
			}
			
			iterator find (const key_type& k)
			{
				value_type toFind = ft::make_pair(k, mapped_type());
				iterator it = iterator(_rbtree.searchTree(toFind), _rbtree.getTNULL(), _rbtree.getRoot());
				return (it);
			}
			
			const_iterator find (const key_type& k) const
			{
				value_type toFind = ft::make_pair(k, mapped_type());
				const_iterator it = const_iterator(_rbtree.searchTree(toFind), _rbtree.getTNULL(), _rbtree.getRoot());
				// if (it != end())
				// 	std::cout << _rbtree.searchTree(toFind)->data.first << std::endl;
				return (it);
			}
			
			size_type count (const key_type& k) const
			{
				if (find(k) != end())
					return (1);
				return (0);
			}
			iterator lower_bound (const key_type& k)
			{
				
				iterator it = begin();
				while(it != end() )
				{
					if (!_comp(it->first, k))
						break;//return (it);
					it++;
				}
				if (it != end())
					return (it++);
				return (it);

			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = begin();
				while(it != end())
				{
					if(!_comp(it->first, k))
						break;//return (it);
					it++;
				}
				if (it != end())
					return (it++);
				return (it);
			}
			iterator upper_bound( const Key& k )
			{
				iterator it = begin();
				while(it != end())
				{
					if(!_comp(it->first, k))
						break;//return (++it);
					it++;
				}
				if (it != end())
					return (++it);
				return (it);
			}
			
			const_iterator upper_bound( const Key& k ) const
			{
				const_iterator it = begin();
				while(it != end())
				{
					if(!_comp(it->first, k))
						break;//return (++it);
					it++;
				}
				if (it != end())
					return (++it);
				return (it);
			}
			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				iterator it = lower_bound (k);
  				return ft::make_pair ( it, upper_bound(k) );	
			}
			
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				const_iterator it = lower_bound (k);
  				return ft::make_pair ( it, upper_bound(k) );	
			}
			
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			key_compare	key_comp(void) const
			{
				return (_comp);
			}
			
			value_compare	value_comp(void) const
			{
				return (value_compare(key_comp()));
			}
	};
			
	template<typename _Key, typename _Val, typename _Compare, typename _Alloc>
    inline bool operator==(const ft::map<_Key, _Val, _Compare, _Alloc>& __x, const ft::map<_Key, _Val, _Compare, _Alloc>& __y)
    {
      return __x.size() == __y.size()
             && ft::equal(__x.begin(), __x.end(), __y.begin());
    }
	
  	template<typename _Key, typename _Val, typename _Compare, typename _Alloc>
    inline bool operator<(const ft::map<_Key, _Val, _Compare, _Alloc>& __x,
              const ft::map<_Key, _Val, _Compare, _Alloc>& __y)
    {
      return ft::lexicographical_compare(__x.begin(), __x.end(), 
                                          __y.begin(), __y.end());
    }
  	
	template<typename _Key, typename _Val, typename _Compare, typename _Alloc>
    inline bool operator!=(const ft::map<_Key, _Val, _Compare, _Alloc>& __x,
               const map<_Key, _Val, _Compare, _Alloc>& __y)
    { return !(__x == __y); }
  	
	template<typename _Key, typename _Val, typename _Compare, typename _Alloc>
    inline bool operator>(const ft::map<_Key, _Val, _Compare, _Alloc>& __x,
              const ft::map<_Key, _Val, _Compare, _Alloc>& __y)
    { return __y < __x; }
  	
	template<typename _Key, typename _Val, typename _Compare, typename _Alloc>
    inline bool operator<=(const ft::map<_Key, _Val, _Compare, _Alloc>& __x,
               const ft::map<_Key, _Val, _Compare, _Alloc>& __y)
    { return !(__y < __x); }
  	
	template<typename _Key, typename _Val, typename _Compare, typename _Alloc>
    inline bool operator>=(const ft::map<_Key, _Val, _Compare, _Alloc>& __x,
               const ft::map<_Key, _Val, _Compare, _Alloc>& __y)
    { return !(__x < __y); }
	
	template<typename _Key, typename _Val, typename _Compare, typename _Alloc>
    inline void swap (ft::map<_Key, _Val, _Compare, _Alloc>& __x, ft::map<_Key, _Val, _Compare, _Alloc>& __y)
    { __x.swap(__y); }			


};

#endif
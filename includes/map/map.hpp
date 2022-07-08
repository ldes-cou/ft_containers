/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:49:18 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/08 17:42:58 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef MAP_HPP
// #define MAP_HPP
// #include <iostream>
// //#include "RB_tree.hpp"
// #include "RB_tree_iterator.hpp"
// #include "../vector/iterator_base_type.hpp"
// #include "../vector/iterator.hpp"
// #include "utils.hpp"


// namespace ft
// {
		
// 	template < class Key,                                     			// map::key_type
// 			class T,                                       				// map::mapped_type
// 			class Compare = std::less<Key>,                     		// map::key_compare
// 			class Alloc = std::allocator<ft::pair<const Key,T> > >    	// map::allocator_type
// 	class map
// 	{
// 		public :
// 			typedef Key												key_type;	                    //The first template parameter (Key)	
// 			typedef T												mapped_type;                    //The second template parameter (T)	
// 			typedef typename ft::pair<const key_type,mapped_type>	value_type;                      //pair<const key_type,mapped_type>	
// 			typedef Compare											key_compare;					//The third template parameter (Compare)	defaults to: less<key_type>
//             friend class RBTree<key_type, mapped_type, key_compare>;
// 			friend struct RB_Node<value_type>;
// 			class value_compare : std::binary_function<value_type, 	value_type, bool>				//Nested function class to compare elements	see value_comp
// 			{
// 				friend class map<key_type, mapped_type, key_compare, Alloc>;	
				
// 				protected:
// 					Compare comp;
// 					value_compare (Compare c) : comp(c) {}
				
// 				public:
// 					bool operator() (const value_type& x, const value_type& y) const
// 					{ return (comp(x.first, y.first)); }
// 			};
			                           			
// 			typedef Alloc													allocator_type;                                    				//The fourth template parameter (Alloc)	defaults to: allocator<value_type>
// 			typedef	typename Alloc::reference								reference;											            //for the default allocator: value_type&
// 			typedef typename Alloc::const_reference							const_reference;									 			//for the default allocator: const value_type&
// 			typedef typename Alloc::pointer									pointer;	                    				                //for the default allocator: value_type*
// 			typedef typename Alloc::const_pointer							const_pointer;		    										//for the default allocator: const value_type*
// 			typedef ft::_Rb_tree_iterator<value_type>						iterator;														//convertible to const_iterator
// 			typedef ft::_Rb_tree_iterator<const value_type> 				const_iterator;													//a bidirectional iterator to const value_type	
// 			typedef ft::reverse_iterator<iterator>							reverse_iterator;												//reverse_iterator<iterator>
// 			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;											//reverse_iterator<const_iterator>	
// 			typedef	typename iterator_traits<iterator>::difference_type		difference_type;												//a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
// 			typedef typename allocator_type::size_type						size_type;

// 			allocator_type									_alloc;
// 			Compare											_comp;
// 			RBTree<key_type, value_type, mapped_type, key_compare>		_rbtree;
// 			private:
				
// 		/********************************************** CONSTRUCTORS ****************************************/
		
// 		public :
// 			/* default */
// 			//map() : _rbtree() { }
// 			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
// 			:
// 				_alloc(alloc),
// 				_comp(comp),
// 				_rbtree()
// 			{}
// 			/* range */  
// 			template <class InputIterator>
// 			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), 
// 				const allocator_type& alloc = allocator_type()): _rbtree(), _comp(comp), _alloc(alloc)
// 			{
// 				insert(first, last);
// 			}

// 			/* copy */
// 			map (const map& x): _rbtree(x.rbtree), _comp(x.comp), _alloc(x._alloc)
// 			{
// 				*this = x;
// 			}
			
// 			map& operator=(const map& x)
// 			{
// 				if (x != this)
// 				{
// 					clear(this);
// 					assign(this->begin, this->end);
// 				}
// 				return (*this);
// 			}
// 			template< class InputIt >
// 			void insert( InputIt first, InputIt last )
// 			{
// 				for (;first != last; first++)
// 					insert(*first);
// 			}
			
// 			ft::pair<iterator, bool> insert( const value_type& value )
// 			{
// 				iterator it;
// 				it = iterator(_rbtree.find(value));
// 				if (it != this->end())
// 					return (ft::make_pair(it, false));
// 				else
// 				{
// 					_rbtree.insert(value);
// 					it = iterator(_rbtree.find(value));
// 					return (ft::make_pair(it, true));
// 				}
// 			}
// 			iterator insert (iterator position, const value_type& val)
// 			{
// 				(void)position;
// 				return (iterator(_rbtree.insert(val)));
// 			}
// 			iterator begin()
// 			{
// 				return (iterator(_rbtree.minimum(_rbtree.getRoot())));
// 			}
			
// 			const_iterator begin() const
// 			{
// 				return (const_iterator(_rbtree.minimum(_rbtree.getRoot())));
// 			}
			
// 			iterator end()
// 			{
// 				return (iterator(_rbtree.geRnil()));
// 			}
			
// 			const_iterator end() const
// 			{
// 				return (const_iterator(_rbtree.geRnil()));
// 			}
			
// 			reverse_iterator rbegin()
// 			{
// 				return (iterator(_rbtree.geRnil()));
// 			}
			
// 			const_reverse_iterator rbegin() const
// 			{	
// 				return (const_iterator(_rbtree.geRnil()));
// 			}
			
// 			reverse_iterator rend()
// 			{
// 				return (iterator(_rbtree.minimum(_rbtree.getRoot())));
// 			}
			
// 			const_reverse_iterator rend() const
// 			{
// 				return (const_iterator(_rbtree.minimum(_rbtree.getRoot())));
// 			}
			
// 			bool empty() const
// 			{
// 				if (this->_rbtree.t_size == 0)
// 					return (true);
// 				return (false);
// 			}
// 			size_type max_size() const
// 			{
// 				return (_alloc.max_size());
// 			}
// 			size_type	size() const
// 			{
// 				return (_rbtree.t_size);
// 			}
// 			void erase (iterator position)
// 			{
// 				_rbtree.deleteByVal(*position);
// 			}
// 			size_type erase (const key_type& k)
// 			{
// 				value_type	toErase = ft::make_pair(k, mapped_type());
// 				return(_rbtree.deleteByVal(toErase));
// 			}
//      		void erase (iterator first, iterator last)
// 			{
// 				iterator tmp;
// 				while( first != last )
// 				{
// 					tmp = first++;
// 					erase(tmp);
// 				}
// 			}
// 			// void swap (map& x)
// 			// {
				
// 			// }
// 			// void clear()
// 			// {}
// 			iterator find (const key_type& k)
// 			{
// 				value_type toFind = ft::make_pair(k, mapped_type());
// 				iterator it = iterator(_rbtree.search(toFind));
// 				if (it->first == k)
// 					return it;
// 				return (end());
// 			}
// 			const_iterator find (const key_type& k) const
// 			{
// 				value_type toFind = ft::make_pair(k, mapped_type());
// 				iterator it = iterator(_rbtree.search(toFind));
// 				if (it->first == k)
// 					return it;
// 				return (end());
// 			}
// 			size_type count (const key_type& k) const
// 			{
// 				RB_Node<T> *temp;
// 				temp = _rbtree.search(k);
// 				if (temp == k)
// 					return (1);
// 				return (0);
// 			}
// 			// iterator lower_bound (const key_type& k)
// 			// {
// 			// 	iterator it;
// 			// 	Node *temp = search(k);
// 			// 	it = iterator(temp);
// 			// 	if (temp == k)
// 			// 		return (it);
// 			// 	it++;
// 			// 	return (it);
// 			// }
// 			// const_iterator lower_bound (const key_type& k) 
// 			// {
// 			// 	const_iterator it;
// 			// 	Node *temp = search(k);
// 			// 	it = const_iterator(temp);
// 			// 	if (temp == k)
// 			// 		return (it);
// 			// 	it++;
// 			// 	return (it);
// 			// }
// 			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const
// 			// {}
// 			// pair<iterator,iterator>             equal_range (const key_type& k)
// 			// {}
// 			allocator_type get_allocator() const
// 			{
// 				return (_alloc);
// 			}

// 	};		
			


// };

//#endif
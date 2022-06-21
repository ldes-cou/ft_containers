/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:49:18 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/21 12:38:10 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>

namespace ft
{
		
	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >>    // map::allocator_type

	class map
	{
		typedef Key												key_type;	                    //The first template parameter (Key)	
		typedef T												mapped_type;                    //The second template parameter (T)	
		typedef typename std::pair<const key_type,mapped_type>	value_type;                                       //pair<const key_type,mapped_type>	
		typedef Compare											key_compare;	//The third template parameter (Compare)	defaults to: less<key_type>
		typedef value_compare	                                    			//Nested function class to compare elements	see value_comp
		typedef Alloc									allocator_type;	                                    			//The fourth template parameter (Alloc)	defaults to: allocator<value_type>
		typedef	Alloc::reference						reference;											            			//for the default allocator: value_type&
		typedef Alloc::const_reference					const_reference;									 			//for the default allocator: const value_type&
		typedef Alloc::pointer							pointer;	                    				                   			//for the default allocator: value_type*
		typedef Alloc::const_pointer					const_pointer;		    			//for the default allocator: const value_type*
		//typedef std::bidirectional_iterator<value_type>		iterator;		//convertible to const_iterator
		//typedef std::bidirectional_iterator<const value_type> const_iterator;				//a bidirectional iterator to const value_type	
		//typedef std::bidirectional_reverse_iterator<iterator>		reverse_iterator;												//reverse_iterator<iterator>
		//typedef std::bidirectional_reverse_iterator<const iterator>	const_reverse_iterator;										//reverse_iterator<const_iterator>	
		typedef difference_type													//a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		typedef typename	allocator_type::size_type						size_type;
	};										//an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t  
};

#endif
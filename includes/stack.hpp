/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:17:55 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/18 18:23:43 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <iostream>  


namespace ft
{
	template< class T, class Container = ft::vector<T> >
	struct stack
	{
		typedef T                      				value_type;
		typedef Container              				container_type;
		typedef typename Container::size_type    	size_type;

		protected:
			Container _c;
			
		public:
		
			explicit stack (const container_type& ctnr = container_type()): _c(ctnr) { ;}
				
			/** Returns true if the %stack is empty. **/
			bool empty() const
			{ return (_c.empty()); }
			
			/**  Returns the number of elements in the %stack.  */
			size_type size() const
			{ return (_c.size()); }
			
			
			value_type& top()
			{
				return (_c.back());
			}
			
			const value_type& top() const
			{
				return (_c.back());
			}
			
			void push (const value_type& val)
			{
				{ _c.push_back(val); }
			}
			
			void pop()
			{
				{ _c.pop_back(); }
			}
			template <class U, class C>
			friend bool operator== (const stack<U,C>& lhs, const stack<U,C>& rhs);
			template <class U, class C>
			friend bool operator<  (const stack<U,C>& lhs, const stack<U,C>& rhs);		
	};
				 /********************************************************/
				/*				RELATIONAL OPERATORS		   			*/
			   /********************************************************/
			   

		template <class U, class C>
		bool operator== (const stack<U,C>& lhs, const stack<U,C>& rhs)
		{
			return (lhs._c == rhs._c);
		}

		template <class U, class C>
		bool operator<  (const stack<U,C>& lhs, const stack<U,C>& rhs)
		{
			return (lhs._c < rhs._c);
		}

		template <class U, class C>
		bool operator!= (const stack<U,C>& lhs, const stack<U,C>& rhs)
		{
			return !(lhs == rhs);
		}
		
		template <class U, class C>
		bool operator>  (const stack<U,C>& lhs, const stack<U,C>& rhs)
		{
			return (rhs < lhs);
		}
		template <class U, class C>
		bool operator<= (const stack<U,C>& lhs, const stack<U,C>& rhs)
		{
			return !(rhs < lhs);
		}
			
		template <class U, class C>
		bool operator>= (const stack<U,C>& lhs, const stack<U,C>& rhs)
		{
			return !(lhs < rhs);
		}
}
#endif


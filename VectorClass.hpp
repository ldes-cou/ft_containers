/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:39:33 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/04/22 12:03:43 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORCLASS_HPP
#define VECTORCLASS_HPP

#include <string.h>
#include <iostream>
#include <iomanip>
# include <vector>
#include <memory>
#include <stdexcept>
#include <limits>
namespace ft
{
    template < class T, class Allocator = std::allocator<T> >
    class vector{
    
                typedef T										value_type;
				typedef Allocator								allocator_type;
				typedef value_type&								reference;
				typedef const value_type&						const_reference;
				typedef typename Allocator::pointer				pointer;
				typedef typename Allocator::const_pointer		const_pointer;
				typedef value_type*								iterator;
				typedef const value_type*						const_iterator;
				typedef	std::reverse_iterator<iterator>			reverse_iterator;
				typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
				typedef typename std::ptrdiff_t					difference_type;
				typedef	typename std::size_t					size_type;
        
        private:
            allocator_type  _alloc;
            pointer         _start;
            pointer         _end;
            pointer         _capacity;
            // const size_type	computeCapacity(size_type __n)
			// {
			// 	if (this->_capacity() > (this->_size() + __n))
			// 		return (this->_capacity());
			// 	const size_type __len = size() + std::max(size(), __n);
			// 	return (__len < size() || __len > max_size()) ? max_size() : __len;
			//}   

           
            
        public:        
                
             /** ************************************************************************** */
		     /**                                     CONSTRUCTORS                           */
		     /** ************************************************************************** */
             
                 
                /** Default
                 * 
                 * @brief  Creates a %vector with default constructed elements.
                 * @param  __n  The number of elements to initially create.
                 * @param  __a  An allocator.
                 */
                explicit vector (const allocator_type& alloc = allocator_type()):
                    _alloc(alloc),
                    _start(0),
                    _end(0),
                    _capacity(0)
                 {}
                 
                 
                 /** fill
                 *  @brief  Creates a %vector with copies of an exemplar element.
                 *  @param  __n  The number of elements to initially create.
                 *  @param  __value  An element to copy.
                 *  @param  __a  An allocator.
                 *
                 *  This constructor fills the %vector with @a __n copies of @a __value.
                 */
                 explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
                 _alloc(alloc)
                 {
                     _start = _alloc.allocate(n);
                     _end = _start;
                     _capacity = (_start + n);
                     while(n--)
                     {
                        _alloc.construct(_end, val);
                        _end++;
                     }
                 }
                
                /** range
                 *  @brief  %Vector copy constructor.
                 *  @param  __x  A %vector of identical element and allocator types.
                 *
                 *  All the elements of @a __x are copied, but any unused capacity in
                 *  @a __x  will not be copied
                 *  (i.e. capacity() == size() in the new %vector).
                 *
                 *  The newly-created %vector uses a copy of the allocator object used
                 *  by @a __x (unless the allocator traits dictate a different object).
                 */
                template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename std::enable_if< !std::is_integral<InputIterator>::value, InputIterator>::type* = 0):
                _alloc(alloc)
                {
                    difference_type n = last - first;
                    _start = _alloc.allocate(n);
                    _end = _start;
                    _capacity = _start + n;
                    while(n--)
                    {
                        _alloc.construct(_end, *first);
                        first++;
                        _end++;
                    }
                }
                 
                 /** copy **/
                 /**
                 *  @brief  %Vector copy constructor.
                 *  @param  __x  A %vector of identical element and allocator types.
                 *
                 *  All the elements of @a __x are copied, but any unused capacity in
                 *  @a __x  will not be copied
                 *  (i.e. capacity() == size() in the new %vector).
                 *
                 *  The newly-created %vector uses a copy of the allocator object used
                 *  by @a __x (unless the allocator traits dictate a different object).
                 */
                //  vector (const vector& x)
                //  {
                     
                //  }
                 
                 
                 
             /** ************************************************************************** */
		     /**                                     ITERATORS                              */
		     /** ************************************************************************** */
                iterator begin() {return (this->_start);}
                iterator begin() const {return (this->_start);}
                iterator end()  {return (this->_end);}
                iterator end() const {return (this->_start);}
                reverse_iterator rbegin() {return  (reverse_iterator(this->_end));}
                reverse_iterator rbegin() const{return  (reverse_iterator(this->_end));}
                iterator rend(){return (reverse_iterator(this->_start));}
                iterator rend()const {return (reverse_iterator(this->_start));}
            
             /** ************************************************************************** */
		     /**                                 ELEMENT ACCESS                             */
		     /** ************************************************************************** */

             /** ************************************************************************** */
		     /**                                 CAPACITY                                   */
		     /** ************************************************************************** */

             size_type size() const{ return (this->_end - this->_start);}     
             size_type max_size() const{return (std::allocator<value_type>::max_size);}
             void resize (size_type n, value_type val = value_type())
             {
                if (n < size())
                {
                    while (size() > n)
                    {
                        _alloc.destroy(_end);
                        _end--;
                    }
                }
                if (n > size())
                {
                    while (size() > n)
                    {
                        _alloc.construct(_end, val);
                        _end++;
                    }
                }
                if (n > _capacity)
                {
                    while(_capacity < n)
                    {
                        _alloc.allocate(_end);
                        _end++;
                    }
                }
             }
             size_type capacity() const{return(_capacity);}
             bool empty() const{return (size() == 0);}
             void reserve (size_type n)
             {
                if (n > max_size())
                    throw std::length_error("vector::reserve");
                if (n > _capacity)
                {
                    while (_capacity < n)
                    {
                        _alloc.allocate(_end);
                        _end++;
                    }
                }
             }
            /** *************************************************************************** */
		    /**                                 MODIFIERS                                  */
		    /** ************************************************************************* */

            template <class InputIterator>
            void assign (InputIterator first, InputIterator last);

            void assign (size_type n, const value_type& val);

             
    };

}
#endif

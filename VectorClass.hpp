/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:39:33 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/04/27 12:26:02 by ldes-cou         ###   ########.fr       */
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
            size_type	computeCapacity(size_type __n)
			{
				if (this->capacity() > (this->size() + __n))
					return (this->capacity());
				size_type __len = size() + std::max(size(), __n);
				return (__len < size() || __len > max_size()) ? max_size() : __len;
			}   

           
            
        public:        
                
             /** ************************************************************************** */
		     /**                                     CONSTRUCTORS                           */
		     /** ************************************************************************** */
             
                 
                /**
                 *  Default
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
                
                /*destructor*/
                ~vector()
                {
                    this->_alloc.deallocate(this->_start, capacity());
                    clear();
                };
                 
                 
                 
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
                reference operator[] (size_type n){return (*(_start + n));}
                const_reference operator[] (size_type n) const { return (*_start + n);}
                
                reference at (size_type n)
                {
                    if (n >= size())
                    {
                        std::string error("vector::at: n (wich is ");
                        error += std::to_string(n);
                        error += std::string(") >= this->size() (wich is ");
                        error += std::to_string(size());
                        error += std::string(")");
                        throw(std::out_of_range(error));
                    }
                    return (*(_start + n));
                }
                const_reference at (size_type n) const
                {
                    if (n >= size())
                    {
                        std::string error("vector::at: n (wich is ");
                        error += std::to_string(n);
                        error += std::string(") >= this->size() (wich is ");
                        error += std::to_string(size());
                        error += std::string(")");
                        throw(std::out_of_range(error));
                    }
                    return (*(_start + n));
                }
                reference front(){return (*_start);}
                const_reference front() const {return (*_start);}
                reference back(){return (*(_end - 1));}
                const_reference back() const {return (*(_end - 1));}
             /** ************************************************************************** */
		     /**                                 CAPACITY                                   */
		     /** ************************************************************************** */

             size_type size() const{ return (this->_end - this->_start);}     
             size_type max_size() const{return (_alloc.max_size());}
             void resize (size_type n, value_type val = value_type())
             {
                if (n < size())
                {
                    while (size() > n)
                    {
                        --_end;
                        _alloc.destroy(_end);
                    }
                }
                else if (n > size())
                {
                    reserve(n);
                    while (size() < n)
                    {
                        _alloc.construct(_end, val);
                        _end++;
                    }
                }
             }
            size_type capacity() const{return (size_type(const_iterator(this->_capacity) - this->begin()));}
            
            /*Increase the capacity of the vector (the total number of elements that the vector can hold 
            without requiring reallocation) to a value that's greater or equal to new_cap. 
            If new_cap is greater than the current capacity(), new storage is allocated, 
            otherwise the function does nothing. reserve() does not change the size of the vector.
            If new_cap is greater than capacity(), all iterators, including the past-the-end iterator, 
            and all references to the elements are invalidated. Otherwise, no iterators or references are invalidated. */
            void reserve (size_type n)
            {
                if (n > max_size())
                    throw std::length_error("vector::reserve");
                if (n > capacity())
                {
                        pointer new_start = this->_alloc.allocate(n);
                        pointer new_end = new_start;
                        for (size_type i =0; i < this->size(); i++)
                        {
                            this->_alloc.construct(new_start + i, this->_start[i]);
                            this->_alloc.destroy(&(this->_start[i]));
                            new_end++;
                        }
                        this->_alloc.deallocate(this->_start, n);
                        this->_start = new_start;
                        this->_end = new_end;
                        this->_capacity = this->_start + n;
                }
             }
            /** *************************************************************************** */
		    /**                                 MODIFIERS                                  */
		    /** ************************************************************************* */

            // template <class InputIterator>
            // void assign (InputIterator first, InputIterator last)
            // {
            // }
            // void assign (size_type n, const value_type& val);
            void push_back (const value_type& val)
            {
                if (this->_end == this->_capacity)
                {
                    reserve(computeCapacity(1));
                }
                _alloc.construct(_end, val);
                _end++;
            }
            void pop_back()
            {
                --_end;
                _alloc.destroy(_end);
            }
            void clear()
            {
                size_type len = size();
                for (size_type i = 0; i < len; i++)
                    pop_back();
            }
        // void swap(vector& x)
        // {
            
        // }

    };

}
#endif

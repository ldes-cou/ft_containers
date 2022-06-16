/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:39:33 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/16 17:40:22 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP


//tester
// #include "base.hpp"
// #include "common.hpp"
#include "lexicograpical_compare.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "utils.hpp"
//#include "random_access_iterator.hpp"
#include <string.h>
#include <iostream>
#include <iomanip>
//#include <vector>
#include <memory>
#include <stdexcept>
#include <limits>


#define out(x) std::cout << x << std::endl; 

namespace ft
{
    template < class T, class Allocator = std::allocator<T> >   
    class vector{   
        public: 
                typedef T										        value_type;
				typedef Allocator								        allocator_type;
				typedef value_type&								        reference;
				typedef const value_type&						        const_reference;
				typedef typename Allocator::pointer				        pointer;
				typedef typename Allocator::const_pointer		        const_pointer;
				// typedef value_type*                                 iterator;
                // typedef const value_type*                           const_iterator;
                typedef ft::random_access_iterator<value_type>          iterator;
				typedef ft::random_access_iterator<const value_type>    const_iterator;
				typedef	ft::reverse_iterator<iterator>			        reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>	        const_reverse_iterator;
				typedef typename std::ptrdiff_t					        difference_type;
				// typedef	typename std::size_t					        size_type;
                typedef typename	allocator_type::size_type						size_type;
                
        private:
            allocator_type  _alloc;
            pointer         _start;
            pointer         _end;
            pointer         _capacity;
            
            size_type	computeCapacity(size_type __n)
			{
				if (this->capacity() > (this->size() + __n))
                {
					return (this->capacity());
                }
				size_type __len = size() + std::max(size(), __n);
				return (__len < size() || __len > max_size()) ? max_size() : __len;
			}   

           
            
        public:        
                
             /** ************************************************************************** */
		     /**                                     CONSTRUCTORS                           */
		     /** ************************************************************************** */
             
                 
                /*Default
                    Constructs an empty container, with no elements.
                */
                explicit vector (const allocator_type& alloc = allocator_type()):
                    _alloc(alloc),
                    _start(0),
                    _end(0),
                    _capacity(0)
                 {}
                 
                 
                /*fill constructor
                    Constructs a container with n elements. Each element is a copy of val.
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
                
                /*range constructor
                    Constructs a container with as many elements as the range [first,last), 
                    with each element constructed from its corresponding element in that range, in the same order.
                */
                template <class InputIterator>
                vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = 0):
                _alloc(alloc)
                {
                    difference_type n = ft::distance(first, last);
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
                 
                 /*copy constructor
                    Constructs a container with a copy of each of the elements in x, in the same order. 
                 */
                 vector (const vector& x):_alloc(x.get_allocator())
                 {
                     _start = _alloc.allocate(x.size());
                     _capacity = _start + x.size();
                     _end = _start;
                     assign(x.begin(), x.end()); 
                 }
                
                /*destructor*/
                ~vector()
                {
                    this->clear();
                    this->_alloc.deallocate(this->_start, capacity());
                }
                vector& operator= (const vector& x)
                {
                    if (this != &x)
                    {
                        this->clear();
                        this->assign(x.begin(), x.end());
                    }
                    return *this;
                }
                
             /** ************************************************************************** */
		     /**                                     ITERATORS                              */
		     /** ************************************************************************** */
                iterator begin() {return (this->_start);}
                const_iterator begin() const {return (this->_start);}
                iterator end()  {return ((this->_end));}
                const_iterator end() const {return ((this->_end));}
                reverse_iterator rbegin() {return  (reverse_iterator(this->_end));}
                const_reverse_iterator rbegin() const {return  (reverse_iterator(this->_end));}
                reverse_iterator rend(){return (reverse_iterator(this->_start));}
                const_reverse_iterator rend() const {return (reverse_iterator(this->_start));}
            
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
                        error += ft::to_string(n);
                        error += std::string(") >= this->size() (wich is ");
                        error += ft::to_string(size());
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
                        error += ft::to_string(n);
                        error += std::string(") >= this->size() (wich is ");
                        error += ft::to_string(size());
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
                if (n > max_size())
					throw std::length_error("vector::resize");
                else if (n < size())
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
					insert(this->end(), (n - this->size()), val);
                }
             }
            size_type capacity() const{return ((this->_capacity - this->_start));}
            bool empty() const{ return (size() == 0);}
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
                        pointer new_start = this->_alloc.allocate(n, this->_start);
                        pointer new_end = new_start;
                        for (size_type i = 0; i < this->size(); i++)
                        {
                            this->_alloc.construct(new_start + i, this->_start[i]);
                            this->_alloc.destroy(&(this->_start[i]));
                            new_end++;
                        }
                        this->_alloc.deallocate(this->_start, this->capacity());
                        this->_start = new_start;
                        this->_end = new_end;
                        this->_capacity = this->_start + n;
                }
            }
            // void	reserve(size_type n) {
			// 	if (n > this->max_size())
			// 		throw std::length_error("vector::reserve");
			// 	if (this->capacity() < n) {
			// 		const size_type old_size = this->size();
			// 		pointer		tmp = this->_alloc.allocate(n, this->_start);
			// 		for	(size_type i = 0; i < this->size(); i++) {
			// 			this->_alloc.construct(tmp + i, this->_start[i]);
			// 			this->_alloc.destroy(&(this->_start[i]));
			// 		}
			// 		this->_alloc.deallocate(this->_start, this->capacity());
			// 		this->_start = tmp;
			// 		this->_end = tmp + old_size;
			// 		this->_capacity = this->_start + n;
			// 	}
			//}
            /** *************************************************************************** */
		    /**                                 MODIFIERS                                  */
		    /** ************************************************************************* */

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
                if (this->size() != 0)
                    erase(this->begin(), this->end());
            }
            
            iterator insert (iterator position, const value_type& val)
            {
                size_type new_start = ft::distance(begin(), position);
                size_type i = size();
                reserve(computeCapacity(1));
                while (i > 0 && --i >= new_start)
                {
                    _alloc.construct(_start + i + 1, *(_start + i)); 
                    _alloc.destroy(_start + i);
                }
                _alloc.construct(_start + new_start, val);   
                _end++;
                return (iterator(_start + new_start)); 
            }
            
            void insert (iterator position, size_type n, const value_type& val)
            {
                if (n==0)
                    return ;
                size_type new_start = ft::distance(begin(), position);
                ptrdiff_t i = size();
                reserve(computeCapacity(n));
                while(i > 0 && --i >= static_cast<ptrdiff_t>(new_start))
                {
                    _alloc.construct((_start + i + n), *(_start + i)); 
                    _alloc.destroy(_start + i);
                }
                for (size_type u = 0; u < n;  u++, new_start++)
                {
                    _alloc.construct((_start + new_start), val);

                }
                _end += n;
            }
            
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                size_type dist = ft::distance(first, last);
                if (dist == 0)
                    return ;
                size_type new_start = ft::distance(begin(), position);
                size_type i = size();
                reserve(computeCapacity(dist));
                while (i > 0 && --i >= new_start)
                {
                    _alloc.construct(_start + i + dist, *(_start + i));
                    _alloc.destroy((_start + i));
                }
                for (size_type i = 0; i < dist; i++, new_start++)
                {
                    _alloc.construct((_start + new_start), *(first));
                    first++;
                }
                _end += dist;
            }
            
    

            iterator erase (iterator position) {
				return (erase(position, position + 1));
			}
            
            // iterator erase(iterator position)
            // {
            //     if (size() <= 0)
            //         return (position);
            //     size_type i = ft::distance(begin(), position);
            //     iterator it = position + 1;
            //     while (it != end())
            //     {
            //         _alloc.destroy(_start + i);
            //         _alloc.construct(_start + i, *it);
            //         it++;
            //         i++;
            //     }
            //     _alloc.destroy(_start + i);
            //     _end -= 1;
            //     return (position);
            // }

            
            // iterator erase (iterator first, iterator last)
            // {
            //     size_type dist = ft::distance(last, iterator(_end));
            //     size_type  i = ft::distance(iterator(_start), first);
            //     if (this->size() == 0)
            //         return (_end);
            //     while(i <= dist)
            //     {
            //         _alloc.destroy(_start + i);
            //         i++;
            //     }
            //     for (size_type i = 0; i <= dist; i++)
            //     {
            //         _alloc.construct((_start + i),*(last + i));
            //     }
            //     _end -= (last - first);
            //     return (last + 1);
            // }
            iterator erase (iterator first, iterator last)
             {
				if (first != this->end() && first != last) {
					pointer p_first = &(*first);
					for (; &(*first) != &(*last); first++)
						_alloc.destroy(&(*first));
					for (int i = 0; i < _end - &(*last); i++)
					{
						_alloc.construct(p_first + i, *(&(*last) + i));
						_alloc.destroy(&(*last) + i);
					}
					_end -= (&(*last) - p_first);
					return (iterator(p_first));
				}
				return (first);
			}
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                difference_type dist = ft::distance(first, last);
                this->clear();
                reserve(computeCapacity(dist));
                for (difference_type i = 0; i < dist; i++)
                {
                    //_alloc.construct((_start + i), *(first + i));
                    _alloc.construct((_start + i), *(first));
                    first++;
                }
                _end += (dist);
            }
            
            void assign (size_type n, const value_type& val)
            {
                reserve(computeCapacity(n));
                this->clear();
                for (size_type i = 0 ; i < n; i++)
                    _alloc.construct((_start + i), val);
                _end += n; 
            }
            
            void swap(vector& x)
            {
                std::swap(_start, x._start);
                std::swap(_end, x._end);
                std::swap(_capacity, x._capacity);
            }

            /** **************************************************************************** */
		    /**                                  ALLOCATOR                                  */
		    /** ************************************************************************** */
            allocator_type get_allocator() const {return (_alloc);}

        };
            /** *************************************************************************** */
		    /**                        NON MEMBER FUNCTION                                 */
		    /** ************************************************************************* */
            template <class T, class Alloc>
            void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
            {
                x.swap(y);
            }
            /** ************************************************************************** */
	        /**                            RELATIONAL OPERATORS                            */
	        /** ************************************************************************** */
            template <class T, class Alloc>
            bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            {
                return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
            }
            template <class T, class Alloc>
            bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            {
                return (!( lhs == rhs ));
            }
            template <class T, class Alloc>
            bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            {
                return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
            }

            template <class T, class Alloc>
            bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            {
                return (!( rhs < lhs ));
            }
            template <class T, class Alloc>
            bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            {
                return ( rhs < lhs );
            }
            template <class T, class Alloc>
            bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            {
                return (!( lhs < rhs ));
            }
        
}
#endif

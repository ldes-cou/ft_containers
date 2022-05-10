/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator_hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:34:24 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/05/10 11:08:02 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
#include "iterator.hpp"
#include "iterator_base_type.hpp"
namespace ft 
{
    template<typename T>
    class random_access_iterator: public ft::iterator<ft::random_access_iterator_tag, T>
    {
        
        public:
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category       iterator_category;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type              value_type;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type         difference_type;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference               reference;
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer                 pointer;
        protected:
            pointer _current;
        /** **************************************************************************   */
		/**                                     CONSTRUCTORS                            */
		/** ************************************************************************** */
        public:
        /*default constructor*/
        random_access_iterator(void): _current(0) {}

        /*constructor from a pointer*/
        random_access_iterator(pointer ptr) : _current(ptr) {}

        /*copy constructor */
        
        random_access_iterator(const random_access_iterator & src) : _current(src._current) {}

        /*destructor*/
        ~random_access_iterator() {}


        /** **************************************************************************   */
		/**                                 OPERATORS                                   */
		/** ************************************************************************** */
        
        //forward iterator requirements
        reference operator * () const
        {
            return *_current;
        }

        pointer operator->() const
        {
            return _current;
        }

        random_access_iterator& operator++()
        {
            ++_current;
            return (*this);
        }

        random_access_iterator operator++(int)
        {
            return (random_access_iterator(_current++));
        }
        
        //bidirectional iterator requirements
        random_access_iterator& operator--()
        {
            --_current;
            return (*this);
        }

        random_access_iterator operator--(int)
        {
            --_current;
            return (random_access_iterator(_current--));
        }

        //random access iterator requirements
        reference operator[](difference_type __n) const
        {
            return (_current[__n]);
        }

        random_access_iterator& operator+=(difference_type __n)
        {
            _current += __n;
            return (*this); 
        }

        random_access_iterator operator+(difference_type __n) const
        {
            return (random_access_iterator(_current + __n));
        }

        random_access_iterator& operator-=(difference_type __n)
        {
            _current -= __n;
            return *this;
        }
        
        random_access_iterator operator-(difference_type __n) const
        {
            return random_access_iterator(_current - __n);
        } 
        
        pointer base() const
        {
            return (_current);
        }
        };
        
        /** ************************************************************************** */
	    /**                           COMPARAISON OPERATORS                            */
	    /** ************************************************************************** */

        template<typename Left, typename Right>
        inline bool operator==(const random_access_iterator<Left>& __x, 
            const random_access_iterator<Right> &__y)
        { return __x.base() == __y.base(); }
        
        template<typename Left, typename Right>
        inline bool operator<(const random_access_iterator<Left> &__x,
                const random_access_iterator<Right>& __y)
        { return __y.base() < __x.base(); }
        
        template<typename Left, typename Right>
        inline bool operator!=(const random_access_iterator<Left>& __x,
                const random_access_iterator<Right>& __y)
        { return !(__x == __y); }
        
        template<typename Left, typename Right>
        inline bool operator>(const random_access_iterator<Left>& __x,
                const random_access_iterator<Right>& __y)
        { return __y < __x; }
        
        template<typename Left, typename Right>
        inline bool operator<=(const random_access_iterator<Left>& __x,
                const random_access_iterator<Right>& __y)
        { return !(__y < __x); }
        
        template<typename Left, typename Right>
        inline bool operator>=(const random_access_iterator<Left>& __x,
                const random_access_iterator<Right>& __y)
        { return !(__x < __y); }
        
        // template<typename _Iterator>
        // inline typename random_access_iterator<_Iterator>::difference_type
        // operator-(const random_access_iterator<_Iterator>& __x,
        //     const random_access_iterator<_Iterator>& __y)
        // { return __y.base() - __x.base(); }
        
        template<typename Left, typename Right>
        inline typename random_access_iterator<Left>::difference_type
        operator-(const random_access_iterator<Left>& __x,
            const random_access_iterator<Right>& __y)
        { return __y.base() - __x.base(); }
}
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:35:02 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/05/10 13:32:16 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "iterator_base_type.hpp"
namespace ft
{
   // Reverse iterators
   /**
    *  "Bidirectional and random access iterators have corresponding reverse
    *  %iterator adaptors that iterate through the data structure in the
    *  opposite direction.  They have the same signatures as the corresponding
    *  iterators.  The fundamental relation between a reverse %iterator and its
    *  corresponding %iterator @c i is established by the identity:
    *  @code
    *      &*(reverse_iterator(i)) == &*(i - 1)
    *  @endcode
    *
    *  This mapping is dictated by the fact that while there is always a
    *  pointer past the end of an array, there might not be a valid pointer
    *  before the beginning of an array." [24.4.1]/1,2
    *
    *  Reverse iterators can be tricky and surprising at first.  Their
    *  semantics make sense, however, and the trickiness is a side effect of
    *  the requirement that the iterators must be safe.
   */
   template<typename _Iterator>
   class reverse_iterator: public ft::iterator<typename iterator_traits<_Iterator>::iterator_category,
               typename iterator_traits<_Iterator>::value_type,
               typename iterator_traits<_Iterator>::difference_type,
               typename iterator_traits<_Iterator>::pointer,
               typename iterator_traits<_Iterator>::reference>
     {
     protected:
       _Iterator current;
 
     public:
       typedef _Iterator                                              iterator_type;
       typedef typename iterator_traits<_Iterator>::difference_type   difference_type;
       typedef typename iterator_traits<_Iterator>::reference         reference;
       typedef typename iterator_traits<_Iterator>::pointer           pointer;
 
     public:
       /**
        *  The default constructor default-initializes member @p current.
        *  If it is a pointer, that means it is zero-initialized.
       */
       // _GLIBCXX_RESOLVE_LIB_DEFECTS
       // 235 No specification of default ctor for reverse_iterator
       reverse_iterator() : current() { }
 
       /**
        *  This %iterator will move in the opposite direction that @p x does.
       */
       explicit
       reverse_iterator(iterator_type __x) : current(__x) { }
 
       /**
        *  The copy constructor is random_access.
       */
       reverse_iterator(const reverse_iterator& __x)
       : current(__x.current) { }
 
       /**
        *  A reverse_iterator across other types can be copied in the random_access
        *  fashion.
       */
       template<typename _Iter>
       reverse_iterator(const reverse_iterator<_Iter>& __x): current(__x.base()) { }
 
       /**
        *  @return  @c current, the %iterator used for underlying work.
       */
       iterator_type base() const
       { return current; }
 
       reference operator*() const
       {
            _Iterator __tmp = current;
            return *--__tmp;
       }
       
       pointer operator->() const
       { return &(operator*()); }
 
       
       reverse_iterator& operator++()
       {
            --current;
            return *this;
       }
 
       reverse_iterator operator++(int)
       {
            reverse_iterator __tmp = *this;
            --current;
            return __tmp;
       }
 
       reverse_iterator& operator--()
       {
            ++current;
            return *this;
       }
       
       reverse_iterator operator--(int)
       {
            reverse_iterator __tmp = *this;
            ++current;
            return __tmp;
       }

       reverse_iterator operator+(difference_type __n) const
       { return reverse_iterator(current - __n); }
       
       reverse_iterator& operator+=(difference_type __n)
       {
            current -= __n;
            return *this;
       }
       
       reverse_iterator operator-(difference_type __n) const
       { return reverse_iterator(current + __n); }
       
       reverse_iterator& operator-=(difference_type __n)
       {
            current += __n;
            return *this;
       }
       
       reference operator[](difference_type __n) const
       { return *(*this + __n); }
     };
 
   //{
   /**
    *
    *  Reverse iterators forward many operations to their underlying base()
    *  iterators.  Others are implemented in terms of one another.
    *
   */
    template<typename _IteratorL, typename _IteratorR>
    inline  bool
    operator==(const reverse_iterator<_IteratorL>& __x,
               const reverse_iterator<_IteratorR>& __y)
    { return __x.base() == __y.base(); }
    
    template<typename _IteratorL, typename _IteratorR>
    inline  bool
    operator<(const reverse_iterator<_IteratorL>& __x,
              const reverse_iterator<_IteratorR>& __y)
    { return __y.base() < __x.base(); }
    
    template<typename _IteratorL, typename _IteratorR>
    inline  bool
    operator!=(const reverse_iterator<_IteratorL>& __x,
                const reverse_iterator<_IteratorR>& __y)
    { return !(__x == __y); }
    
    template<typename _IteratorL, typename _IteratorR>
    inline  bool
    operator>(const reverse_iterator<_IteratorL>& __x,
              const reverse_iterator<_IteratorR>& __y)
    { return __y < __x; }
    
    template<typename _IteratorL, typename _IteratorR>
    inline  bool
    operator<=(const reverse_iterator<_IteratorL>& __x,
                const reverse_iterator<_IteratorR>& __y)
    { return !(__y < __x); }
    
    template<typename _IteratorL, typename _IteratorR>
    inline  bool
    operator>=(const reverse_iterator<_IteratorL>& __x,
                const reverse_iterator<_IteratorR>& __y)
    { return !(__x < __y); }

 }
 #endif


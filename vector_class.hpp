/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:39:33 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/04/15 17:39:56 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CLASS_HPP
#define VECTOR_CLASS_HPP

# include <vector>
namespace ft
{
    template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
           typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator
    {
      /// One of the @link iterator_tags tag types@endlink.
      typedef _Category  iterator_category;
      /// The type "pointed to" by the iterator.
      typedef _Tp        value_type;
      /// Distance between iterators is represented as this type.
      typedef _Distance  difference_type;
      /// This type represents a pointer-to-value_type.
      typedef _Pointer   pointer; 
      /// This type represents a reference-to-value_type.
      typedef _Reference reference;
    };
}
#endif

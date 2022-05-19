/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:08:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/05/10 16:30:58 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
# include <cstddef>
#include <string>
#include <sstream>
#include <typeinfo>
#include <iostream>
#include "random_access_iterator.hpp"

//#include "vector"

namespace ft
{
    template <typename T>
    std::string	to_string(T n)
    {
        std::ostringstream ss;
        ss << n;
        return (ss.str());
    }

    template<class It>
    typename ft::iterator_traits<It>::difference_type 
    distance(It first, It last)
    {
        return (__distance(first, last, typename ft::iterator_traits<It>::iterator_category()));
    }
    template <typename RandomAccessIterator>
	typename ft::iterator_traits<RandomAccessIterator>::difference_type
	__distance (RandomAccessIterator first, RandomAccessIterator last, ft::random_access_iterator_tag)
	{
		return (last - first);
	}

	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	__distance (InputIterator first, InputIterator last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	diff;
		for (diff = 0; first != last; ++first, ++diff) 
        { ; }
		return (diff);
	}
}    
#endif
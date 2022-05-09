/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:58:17 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/05/09 17:29:38 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
    template <typename T, bool is_integral_ret>
	    struct	is_int 
        {
		    typedef T 			type;
		    static const bool	value = is_integral_ret;
	    };

	template<typename T> struct is_integral_t : public is_int<bool, false> {};
    
	template<> struct is_integral_t<bool> : public is_int<bool, true> {};

	template<> struct is_integral_t<char> : public is_int<char, true> {};

	template<> struct is_integral_t<wchar_t> : public is_int<wchar_t, true> {};

	template<> struct is_integral_t<signed char> : public is_int<signed char, true> {};

	template<> struct is_integral_t<short int> : public is_int<short int, true> {};

	template<> struct is_integral_t<int> : public is_int<int, true> {};

	template<> struct is_integral_t<long int> : public is_int<long int, true> {};

	template<> struct is_integral_t<long long int> : public is_int<long long int, true> {};

	template<> struct is_integral_t<unsigned char> : public is_int<unsigned char, true> {};

	template<> struct is_integral_t<unsigned short int> : public is_int<unsigned short int, true> {};

	template<> struct is_integral_t<unsigned int> : public is_int<unsigned int, true> {};

	template<> struct is_integral_t<unsigned long int> : public is_int<unsigned long int, true> {};

	template<> struct is_integral_t<unsigned long long int> : public is_int<unsigned long long int, true> {};
    
    template <class T> struct is_integral :is_integral_t<T> {};
}
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:23:40 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/14 14:12:27 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_HPP
#define UTILS_HPP
#include <ostream>
#include <iostream>

namespace ft
{
    
    
    template <class T1, class T2>
    struct pair
    {
       // private:
            typedef T1 first_type;
            typedef T2 second_type;
            
            first_type first;
            second_type second;
        
        public:

        /*********************************** CONSTRUCTORS *******************************************/
        
            pair(): first(T1()), second(T2())
            {}
            
            template<class U, class V> pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) 
            {}
            
            pair (const first_type& a, const second_type& b): first(a), second(b)
            {}
        
        /*********************************** OVERLOAD OPERATOR *******************************************/
        pair& operator=(const pair& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
    };
        /*********************************** RELATIONAL OPERATOR *******************************************/
        
        template <class T1, class T2>
        bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first == rhs.first && lhs.second == rhs.second; }

        template <class T1, class T2>
        bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs==rhs); }

        template <class T1, class T2>
        bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return lhs.first < rhs.first || (!(rhs.first<lhs.first) && lhs.second < rhs.second); }

        template <class T1, class T2>
        bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(rhs < lhs); }

        template <class T1, class T2>
        bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return rhs < lhs; }

        template <class T1, class T2>
        bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        { return !(lhs < rhs); }
        
    
    /****************************************** MAKE_PAIR ***********************************************/
        
    /*  Constructs a pair object with its first element set to x and its second element set to y.
        The template types can be implicitly deduced from the arguments passed to make_pair.*/
        
    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    }
    /**************************************** OSTREAM OVERLOAD *******************************************/
    template <class T1, class T2>
    std::ostream& operator<<(std::ostream &stream, pair<T1, T2> var)
    {
        stream << var.second ;
        return (stream);
    }
};


#endif

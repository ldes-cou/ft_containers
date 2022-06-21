/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:23:40 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/21 17:04:21 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    
    template <class T1, class T2>
    struct pair
    {
        private:
            T1 first;
            T2 second;
        
        public:

        /*********************************** CONSTRUCTORS *******************************************/
        
            pair(): first(T1()), second(T2())
            {;}
            
            template<class U, class V> pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) 
            {;}
            
            pair (const first_type& a, const second_type& b): first(a), second(b)
            {;}
        
        /*********************************** OVERLOAD OPERATOR *******************************************/
        pair& operator= (const pair& pr)
        {
            pr.first = this->first;
            pr.second = this->second;
            return (pr);
        }
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
        
    };
    
    /****************************************** MAKE_PAIR ***********************************************/
        
    /*  Constructs a pair object with its first element set to x and its second element set to y.
        The template types can be implicitly deduced from the arguments passed to make_pair.*/
        
    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    }
};


#endif

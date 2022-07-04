/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/04 13:58:50 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map/map.hpp"
# include "../includes/map/RB_tree.hpp"
//# include <map>
# include <utility>
#include <iostream>

#define out(x) std::cout << x << std::endl; 
using namespace ft;

void test_map()
 {
   map<int, int> marks;
   
   
     marks.insert(pair<int, int>(160, 42));
    marks._rbtree.printTree();
     map<int, int>::iterator it = marks.begin();
    // it++;
     std::cout << it->second << std::endl;
     marks.insert(pair<int, int>(159, 30));
     it = marks.begin();
     std::cout << it->second << std::endl;
     marks.insert(pair<int, int>(163, 50));
     std::cout << marks._rbtree.t_size << std::endl;
     marks.insert(pair<int, int>(162, 40));
    //  std::cout << it->second << std::endl;
   // it = marks.begin();
    //  std::cout << it->second << std::endl;
     marks.insert(pair<int, int>(164, 31)); 
   // it = marks.begin();
    //  std::cout << it->second << std::endl;
     marks.insert(pair<int, int>(165, 12));
    //it = marks.begin();
    //  std::cout << it->second << std::endl;
     marks.insert(pair<int, int>(166, 34)); 
   
     map<int, int>::iterator itr; 
     std::cout << "nThe map marks is : n"; 
     std::cout << "ROLL NO.tMarksn"; 
     for (itr =  marks.begin(); itr !=  marks.end(); ++itr) { 
        std::cout  << itr->first 
             << "t   t" << itr->second << 'n'; 
     } 
     std::cout << std::endl;  

 }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/12 10:26:31 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map/map.hpp"
//# include "../includes/map/RB_tree.hpp"
//# include <map>
# include <utility>
#include <iostream>

#define out(x) std::cout << x << std::endl; 
using namespace ft;

void test_map()
 {
   map<int, int> marks;
   
     marks.insert(pair<int, int>(160, 42));
    //  map<int, int>::iterator it = marks.begin();
    //  std::cout << it->second << std::endl;
     marks.insert(pair<int, int>(15, 90));
     marks.insert(pair<int, int>(139, 70));
     marks.insert(pair<int, int>(129, 350));
     marks.insert(pair<int, int>(15419, 37450));
     marks.insert(pair<int, int>(34119, 3670));
     marks.insert(pair<int, int>(14319, 35470));
     marks.insert(pair<int, int>(1316, 375430));
     marks.insert(pair<int, int>(11119, 37430));
     marks.insert(pair<int, int>(16319, 360));
     marks.insert(pair<int, int>(119, 37032));
     marks.insert(pair<int, int>(1199, 37340));
     //marks.insert(pair<int, int>(119, 3720));
     marks.insert(pair<int, int>(1149, 3570));
     marks.insert(pair<int, int>(1139, 3750));
     
     marks._rbtree.printTree();
    out("                      ")
     out(marks.size())
     marks.erase(119);
     marks.erase(139);
     marks.erase(15);
     marks.erase(11119);
     marks._rbtree.printTree();
     out("                      ")
     out(marks.size())
     
     
 }
    


 

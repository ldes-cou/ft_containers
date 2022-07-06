/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucrece <lucrece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/06 22:11:24 by lucrece          ###   ########.fr       */
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
     //std::cout << it->second << std::endl;
    marks.insert(pair<int, int>(159, 30));
      map<int, int>::iterator it = marks.begin();
      //out(it->second)
     it++;
      map<int, int>::iterator itr = marks.end();
     //out(it->second)
     
     itr--; //faire un cas special pour les iterateurs --
     //out(itr->second)
     marks.insert(pair<int, int>(163, 50));
     marks.insert(pair<int, int>(164, 31)); 
     marks.insert(pair<int, int>(165, 12));
     marks.insert(pair<int, int>(166, 34));
     marks.insert(pair<int, int>(166, 34));
    //  out("                          ")
    //  out("max  ")
    //  out(marks._rbtree.getRoot()->data.first);
    //  out(marks._rbtree.getRoot()->data.second);
    //  out("root  ")
    //  out(marks._rbtree.maximum(marks._rbtree.getRoot())->data.first);
    //   out(marks._rbtree.maximum(marks._rbtree.getRoot())->data.second);
    //  marks._rbtree.swapValues(marks._rbtree.getRoot(), marks._rbtree.maximum(marks._rbtree.getRoot()));
    //  out(" AFTER SWAP ")
    //  out("max  ")
    //  out(marks._rbtree.getRoot()->data.first);
    //  out(marks._rbtree.getRoot()->data.second);
    //  out("root  ")
    //  out(marks._rbtree.maximum(marks._rbtree.getRoot())->data.first);
    //  out(marks._rbtree.maximum(marks._rbtree.getRoot())->data.second);
    //  for (it =  marks.begin(); it !=  marks.end(); it++) { 
    //     std::cout  << it->first 
    //          << "|" << it->second << '\n';
    //  }
     out ("   ")
     
     out((marks._rbtree.search(pair<int, int>(165, 12)))->data.first)// embrouille dans les search
     it = marks.find(164);
     it--;
     out(it->first)
    //  out((marks._rbtree.search(pair<int, int>(164, 31)))->data.first)
    //  out((marks._rbtree.search(pair<int, int>(164, 31)))->data.first)
    //  out((marks._rbtree.search(pair<int, int>(164, 31)))->data.first)
    //  out((marks._rbtree.search(pair<int, int>(164, 31)))->data.first)
    //  out((marks._rbtree.search(pair<int, int>(164, 31)))->data.first)
    //  out((marks._rbtree.search(pair<int, int>(163, 31)))->data.first)

     
     
     
    //  it = marks.find(163);
    //  out(it->first) out(" ")
    //  //out(*it->first)
    //  it = marks.find(162);
    //  out(it->first) out(" ") //out(it->second)
    //  marks.erase(164);
    //  marks.erase(163);
    //  marks.erase(166);
    //  marks.erase(165);
    //  out("              ")
    //   for (it =  marks.begin(); it !=  marks.end(); it++) { 
    //     std::cout  << it->first 
    //          << "|" << it->second << '\n';
    // //marks._rbtree.printTree();
    // }
 }
  //    it = marks.begin();
  //    std::cout << it->second << std::endl;
  //    marks.insert(pair<int, int>(163, 50));
  //marks._rbtree.printTree();
  //    std::cout << marks._rbtree.t_size << std::endl;
  //    marks.insert(pair<int, int>(162, 40));
  //   //  std::cout << it->second << std::endl;
  //  // it = marks.begin();
  //   //  std::cout << it->second << std::endl;
  //  // it = marks.begin();
  //   //  std::cout << it->second << std::endl;
  //   //it = marks.begin();
  //   //  std::cout << it->second << std::endl;
   
  //    map<int, int>::iterator itr; 
  //    std::cout << "nThe map marks is : n"; 
  //    std::cout << "ROLL NO.tMarksn"; 
  //    } 
  //    std::cout << std::endl;  

 

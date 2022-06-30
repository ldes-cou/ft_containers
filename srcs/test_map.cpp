/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucrece <lucrece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/30 15:26:33 by lucrece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map/map.hpp"
# include "../includes/map/RB_tree.hpp"
//# include <map>
# include <utility>
#include <tuple>
#include <iostream>

#define out(x) std::cout << x << std::endl; 
using namespace ft;

void test_map()
 {
   //out("here")
  ft::map<char,int> mymap;
  // first insert function version (single parameter):
  mymap.insert (ft::pair<char,int>('a',100) );
  std::cout << mymap.begin()->second << std::endl;
  //ft::map<char,int>::iterator it = mymap.begin();
  //std::cout << mymap.begin() << std::endl;
  // for (ft::map<char,int>::iterator it = mymap.begin(); it < mymap.end(); it++)
  //   std::cout << *it << std::endl;
  
  //_mymap._rbtree.printTree();
  //it++;
  //std::cout << mymap.begin()->second << std::endl;
  mymap.insert (ft::pair<char,int>('z',200) );
  std::cout << mymap.end()->second << std::endl;
  
  // ft::pair<ft::map<char,int>::iterator, bool> ret;
  // // ft::pair<map<char,int>::iterator,bool> ret;
  // ret = mymap.insert (ft::pair<char,int>('z',500) );
  // if (ret.second == false) {
  //   std::cout << "element 'z' already existed";
  //   std::cout << " with a value of " << ret.first->second << '\n';
  // }
 }
//   tree.printTree();

//   //bst.printTree();
//   // std::cout << std::endl
//   //    << "After deleting" << std::endl;
//   // bst.deleteNode(40);
//   //bst.printTree();
// //std::cout << tree.maximum(tree.getRoot()) << std::endl;
// tree.insert(7);
// //std::cout << tree.maximum(tree.getRoot()) << std::endl;
  //it = tree.insert(ft::pair<int 2, char *"caca">);
// tree.insert(18);
// tree.insert(10);
// tree.insert(22);
// tree.insert(8);
// tree.insert(11);
// tree.insert(26);
// tree.insert(2);
// tree.insert(6);
// tree.insert(13);

// tree.printTree();

// // tree.printInOrder();
// // tree.printLevelOrder();

// std::cout << std::endl <<"Deleting 18, 11, 3, 10, 22"<< std::endl;

// tree.deleteByVal(18);
// tree.deleteByVal(11);
// tree.deleteByVal(3);
// tree.deleteByVal(10);
// tree.deleteByVal(22);

// tree.printTree();
// // tree.printInOrder();
// // tree.printLevelOrder();
// return ;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/20 15:20:57 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map/map.hpp"
#include "../includes/map/rbtree.hpp"
#include <map>

//using namespace ft;

void test_map()
 {
  RBTree bst;
  bst.insert(55);
  bst.insert(40);
  bst.insert(65);
  bst.insert(60);
  bst.insert(75);
  bst.insert(57);

  bst.printTree();
  // std::cout << std::endl
  //    << "After deleting" << std::endl;
 // bst.deleteNode(40);
  //bst.printTree();
}
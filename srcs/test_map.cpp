/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/21 11:35:25 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map/map.hpp"
#include "../includes/map/rbtree.hpp"
#include <map>

//using namespace ft;

void test_map()
 {
  RBTree tree;
  // bst.insert(55);
  // bst.insert(40);
  // bst.insert(65);
  // bst.insert(60);
  // bst.insert(75);
  // bst.insert(57);

  //bst.printTree();
  // std::cout << std::endl
  //    << "After deleting" << std::endl;
  // bst.deleteNode(40);
  //bst.printTree();

tree.insert(7);
tree.insert(3);
tree.insert(18);
tree.insert(10);
tree.insert(22);
tree.insert(8);
tree.insert(11);
tree.insert(26);
tree.insert(2);
tree.insert(6);
tree.insert(13);

tree.printTree();

// tree.printInOrder();
// tree.printLevelOrder();

cout<<endl<<"Deleting 18, 11, 3, 10, 22"<<endl;

tree.deleteByVal(18);
tree.deleteByVal(11);
tree.deleteByVal(3);
tree.deleteByVal(10);
tree.deleteByVal(22);

tree.printTree();
// tree.printInOrder();
// tree.printLevelOrder();
return ;
}
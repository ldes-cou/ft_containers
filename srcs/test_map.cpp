/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/28 11:52:38 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map/map.hpp"
# include "../includes/map/RB_tree.hpp"
# include <map>
# include <utility>

using namespace ft;

void test_map()
 {
  RBTree<int, char> tree;

  //bst.printTree();
  // std::cout << std::endl
  //    << "After deleting" << std::endl;
  // bst.deleteNode(40);
  //bst.printTree();
//std::cout << tree.maximum(tree.getRoot()) << std::endl;
tree.insert(7);
//std::cout << tree.maximum(tree.getRoot()) << std::endl;
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

std::cout << std::endl <<"Deleting 18, 11, 3, 10, 22"<< std::endl;

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
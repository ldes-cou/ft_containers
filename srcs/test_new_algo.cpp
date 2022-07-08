/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new_algo.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/08 19:07:42 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map/RB_tree.hpp"
# include <utility>
#include <iostream>

using namespace ft;
void test_new_algo()
{
    
  RBTree<int, pair<int, int>, int> bst;
  
  bst.insert(pair<int, int>(42, 68));
  bst.insert(pair<int, int>(450, 68));
  bst.insert(pair<int, int>(472, 68));
  bst.insert(pair<int, int>(442, 68));
  bst.insert(pair<int, int>(452, 68));
  bst.insert(pair<int, int>(422, 68));
  bst.insert(pair<int, int>(422, 68));
  bst.insert(pair<int, int>(4272, 68));
  bst.insert(pair<int, int>(4922, 68));
  bst.insert(pair<int, int>(8842, 68));
  bst.insert(pair<int, int>(4228, 68));

  // bst.insert(55);
  // bst.insert(40);
  // bst.insert(65);
  // bst.insert(60);
  // bst.insert(775);
  // bst.insert(557);
  // bst.insert(574);
  // bst.insert(5736);
  // bst.insert(577);
  // bst.insert(578);
  // bst.insert(5777);
  // bst.insert(5667);
  // bst.insert(5123387);
  // bst.insert(57562);


  bst.printTree();
  // std::cout << std::endl
  //    << "After deleting" << std::endl;
//  bst.deleteNode(55);
  // bst.deleteNode(40);
  // bst.deleteNode(65);
  // bst.deleteNode(60);
  // bst.deleteNode(5777);
  // bst.deleteNode(5667);
  // bst.deleteNode(5123387);
  // bst.deleteNode(57562);
  //bst.printTree();
}
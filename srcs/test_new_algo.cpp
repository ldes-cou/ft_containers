/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new_algo.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/08 15:07:19 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map/NewRBT.hpp"
# include <utility>
#include <iostream>

void test_new_algo()
{
    
  RedBlackTree bst;
  bst.insert(55);
  bst.insert(40);
  bst.insert(65);
  bst.insert(60);
  bst.insert(75);
  bst.insert(57);

  bst.printTree();
  std::cout << std::endl
     << "After deleting" << std::endl;
  bst.deleteNode(40);
  bst.printTree();
}
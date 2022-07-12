/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new_algo.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/12 09:42:32 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map/RB_tree.hpp"
# include <utility>
#include <iostream>

using namespace ft;
void test_new_algo()
{
    
  RBTree<int, pair<int, int>, int> bst;
  
  // bst.insert(pair<int, int>(42, 68));
  // bst.insert(pair<int, int>(450, 68));
  // bst.insert(pair<int, int>(472, 68));
  // bst.insert(pair<int, int>(442, 68));
  // bst.insert(pair<int, int>(452, 68));
  // bst.insert(pair<int, int>(422, 68));
  // bst.insert(pair<int, int>(422, 68));
  // bst.insert(pair<int, int>(4272, 68));
  // bst.insert(pair<int, int>(4922, 68));
  // bst.insert(pair<int, int>(8842, 68));
  // bst.insert(pair<int, int>(4228, 68));

  bst.printTree();

}
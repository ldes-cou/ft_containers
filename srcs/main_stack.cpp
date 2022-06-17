/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:29:04 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/17 15:02:16 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack/stack.hpp"
#include "../includes/tests.hpp"

#include <deque>
#include <vector>
#include <list>

#ifndef NAMESPACE
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main ()
{
  std::cout <<  GREEN;
  test_stack_ft();
  std::cout << '\n' << BLUE1;
  test_stack_std();
  std::cout << '\n' << END;
  return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:29:04 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/17 11:56:57 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack/stack.hpp"
#include <deque>
#include <vector>
#include <list>

# if !defined(USING_STD)
#  define TESTED_NAMESPACE ft
# else
#  define TESTED_NAMESPACE std
# endif


int main ()
{
  ft::vector<int> __vector (3,100);          // deque with 3 elements
  ft::vector<int> myvector (2,200);         // vector with 2 elements

  ft::stack<int> first;                     // empty stack
  ft::stack<int> second (__vector);          // stack initialized to copy of deque
  
  ft::stack<int,std::deque<int> > third;   // empty stack using deque
  ft::stack<int,ft::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  ft::stack<int> a, b, c;
  a.push(10);
  a.push(20);
  a.push(30);

  b.push(10);
  b.push(20);
  b.push(30);

  c.push(30);
  c.push(20);
  c.push(10);

  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  //if (a<=b) std::cout << "a is less than or equal to b\n";
  //if (a>=b) std::cout << "a is greater than or equal to b\n";

  return 0;
}
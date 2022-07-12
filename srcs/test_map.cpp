/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/12 16:14:33 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map/map.hpp"
//# include "../includes/map/RB_tree.hpp"
//# include <map>
# include <utility>
#include <iostream>

#define out(x) std::cout << x << std::endl; 
using namespace ft;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

void test_map()
{
	pair<int, std::string>			my_pair(8, "salut");
	map<int, std::string>			test;
	map<int, std::string>::iterator	it;
	
	test.insert(my_pair);
	test.insert(pair<int, std::string>(-4, "bar"));
	test.insert(pair<int, std::string>(2, "machin"));
	test.insert(pair<int, std::string>(3, "foo"));
	test.insert(pair<int, std::string>(746, "Marcel"));
	test.insert(pair<int, std::string>(1, "truc"));
	test._rbtree.printTree();
	it = test.begin();
	map<int, std::string>::iterator	kit = test.end();
	std::cout <<(*kit) << std::endl;
	
	std::cout << '\n';

	while (it != test.end())
	{
		// cout << "start of while\n";
		std::cout << it->first << ", " << it->second << '\n';
		it++;
// 		cout << "iterator incremented\n";

// #ifndef STD
// 		cout << it.getPointer() << '\n';
// 		cout << test.end().getPointer() << '\n';
// #endif

	}
	std::cout << "End of display loop\n";
}
     

    


 

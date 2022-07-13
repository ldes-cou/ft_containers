/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/13 12:20:55 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map/map.hpp"
//# include "../includes/map/RB_tree.hpp"
//# include <map>
# include <utility>
#include <iostream>

# define BLUE2 "\x1B[36m"
# define PINK "\x1B[45;1m"
# define END "\033[0m"

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
	
	test.insert(my_pair);
	test.insert(pair<int, std::string>(-4, "bar"));
	test.insert(pair<int, std::string>(2, "machin"));
	test.insert(pair<int, std::string>(3, "foo"));
	test.insert(pair<int, std::string>(746, "Marcel"));
	test.insert(pair<int, std::string>(1, "truc"));
	test._rbtree.printTree();
	map<int, std::string>::iterator	kit = test.end();
	std::cout <<(*kit) << std::endl;
	
	std::cout << '\n';

	// while (it != test.end())
	// {
	// 	// cout << "start of while\n";
	// 	std::cout << it->first << ", " << it->second << '\n';
	// 	it++;
// 		cout << "iterator incremented\n";

// #ifndef STD
// 		cout << it.getPointer() << '\n';
// 		cout << test.end().getPointer() << '\n';
// #endif

	//}
	//std::cout << "End of display loop\n";

	// out("                       ")
	// out(PINK)
	// out("           TEST BEGIN()         ")
	map<char,int> mymap;


	if (mymap.begin() != mymap.end())
		std::cout << "This should not happen\n";

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	if (mymap.begin() == mymap.end())
		std::cout << "This is wrong\n";
  // show content:
  	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    	std::cout << it->first << " => " << it->second << '\n';

	std::cout << "Hello there\n";
	for (map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); it++)
    	std::cout << it->first << " => " << it->second << '\n';
	std::cout << "General Kenobi\n";

	map<char, int>::const_iterator it = mymap.begin();
	map<char, int>::const_iterator ti = mymap.end();
	std::cout << "Wupwup\n";

	it++;
	out("caca")
	++it;
	out("caca")

	it--;
	out("caca")

	--it;
	out("caca")

	std::cout << "marker1\n";

	ti--;
	--ti;
	++ti;
	ti++;

	ti = it;

	std::cout << "Trump is a kiddo\n";
	map<char, int>::iterator end = mymap.end();
	while(it != end)
	{
    	std::cout << it->first << " => " << it->second << '\n';
		it++;
	}

	 map<char,int> mimap;
  char c;

  mimap ['a']=101;
  std::cout << "assigned 'a'\n";
  mimap ['c']=202;
  std::cout << "assiged 'c'\n";
  mimap ['f']=303;
  std::cout << "assigned 'f'\n";

	std::cout << "end of assignations\n";
  
  map<char, int>::iterator tit = mimap.find('a');
  out(*tit)
  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mimap.count(c)>0)
      std::cout << " is an element of map.\n";
    else 
      std::cout << " is not an element of map.\n";
  }


}
     

    


 

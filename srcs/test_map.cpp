/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:44:58 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/14 16:55:55 by ldes-cou         ###   ########.fr       */
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

	out("                       ")
	out(BLUE2)
	out("***************	 TEST ITERATORS		*****************")
	out(END)
	map<char,int> mymap;


	if (mymap.begin() != mymap.end())
		std::cout << "This should not happen\n";

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	if (mymap.begin() == mymap.end())
		std::cout << "This is wrong\n";
	
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
	++it;

	it--;

	--it;

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

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mimap.count(c)>0)
			std::cout << " is an element of map.\n";
		else 
			std::cout << " is not an element of map.\n";
	}

	out(BLUE2)
	out("**************      TEST VALUECOMP/KEYCOMP   ****************** ")
	out(END)
	map<char,int>::key_compare mycomp = mymap.key_comp();
	std::cout << mycomp(3 , 2) << std::endl;
	map<char,int>::value_compare micomp = mymap.value_comp();

	std::cout << micomp(make_pair('a', 2), make_pair('b', 4)) << std::endl;
	out(BLUE2)
	out("**************      TEST EMPTY   ****************** ")
	out(END)
	bool empty = mymap.empty();
	if (empty == true)
		std::cout << " that container is empty" << std::endl;
	std::cout << "that container is not empty" << std::endl;

	out(BLUE2)
	out("**************      TEST RELATIONAL OPERATORS   ****************** ")
	out(END)
	
	map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	out(BLUE2)
	out("**************      TEST OPERATOR[]   ****************** ")
	out(END)
	
	map<char,std::string> themap;

	themap['a']="an element";
	themap['b']="another element";
	themap['c']=themap['b'];

	std::cout << "themap['a'] is " << themap['a'] << '\n';
	std::cout << "themap['b'] is " << themap['b'] << '\n';
	std::cout << "themap['c'] is " << themap['c'] << '\n';
	std::cout << "themap['d'] is " << themap['d'] << '\n';
	std::cout << "themap now contains " << themap.size() << " elements.\n";

	out(BLUE2)
	out("**************      TEST OPERATOR=   ****************** ")
	out(END)
	
	map<char,int> first;
	map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                	// second now contains 3 ints
	first=map<char,int>();  		// and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';


	out(BLUE2)
	out("**************      TEST LOWER_BOUND   ****************** ")
	out(END)
	
	map<char,int> mamap;
	map<char,int>::iterator itlow,itup;

	mamap['a']=20;
	mamap['b']=40;
	mamap['c']=60;
	mamap['d']=80;
	mamap['e']=100;

	itlow = mamap.lower_bound ('b');  // itlow points to b
	itup = mamap.upper_bound ('d');   // itup points to e (not d!)

	std::cout << "low : " << itlow->first << '\n';
	std::cout << "up : " << itup->first << '\n';

	//mamap.erase(itlow,itup);        

	// print content:
	for (map<char,int>::iterator it=mamap.begin(); it!=mamap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	out(BLUE2)
	out("**************      TEST EQUAL RANGE   ****************** ")
	out(END)
	
	map<char,int> The_map;
	The_map['a']=10;
	The_map['b']=20;
	The_map['c']=30;

	pair<map<char,int>::iterator,map<char,int>::iterator> ret;
	ret = The_map.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}







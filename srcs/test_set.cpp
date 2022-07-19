# include "../includes/set.hpp"
# include <set>
# include <utility>
# include <iostream>
# include <list>

# define BLUE2 "\x1B[36m"
# define PINK "\x1B[45;1m"
# define END "\033[0m"

# if !defined(NM)
#  define NM ft
# endif /* = STD */

#define out(x) std::cout << x << std::endl; 
template <class T>
void	print(NM::set<T>& lst)
{
	for (typename NM::set<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}
void test_set_clear();
void test_set_wap();

void test_set_insert()
{
	out("                       ")
	out(BLUE2)
	out("***************	 TEST INSERT		*****************")
	out(END)
	//NM::pair<int, std::string>			my_pair(8, "salut");
	NM::set<std::string>			test;

	test.insert("bar");
	test.insert("machin");
	test.insert("foo");
	test.insert("Marcel");
	test.insert("truc");
	NM::set<std::string>::iterator	kit = test.begin();
	for (; kit != test.end(); kit++)
		std::cout <<(*kit) << std::endl;
		
}

void test_set_erase()
{
	out("                       ")
	out(BLUE2)
	out("***************	 TEST ERASE		*****************")
	out(END)
	
	NM::set<int> a_set;
	NM::set<int>::iterator tit;

	// insert some values:
	a_set.insert(10);
    a_set.insert(20);
    a_set.insert(30);
    a_set.insert(70);
    a_set.insert(50);
    a_set.insert(180);
    a_set.insert(102);

	tit=a_set.find(20);
	std::cout << "found b\n";
	a_set.erase (tit);                   
	std::cout << "erase iterator to b\n";
	a_set.erase ('c');                 
	std::cout << "erase by key 'c'\n";
	tit=a_set.find (50);
	std::cout << "erase by range 'e' to end\n";
	a_set.erase ( tit, a_set.end() );    

	std::cout << " display :\n";
	// show content:
	for (tit=a_set.begin(); tit!=a_set.end(); ++tit)
		std::cout << *tit << '\n';
}

void test_set()
{
	test_set_insert();
	test_set_erase();
	
	out("                       ")
	out(BLUE2)
	out("***************	 TEST ITERATORS		*****************")
	out(END)
	NM::set<int> mymap;


	if (mymap.begin() != mymap.end())
		std::cout << "This should not happen\n";

	mymap.insert(100);
	mymap.insert(200);
	mymap.insert(892);
	if (mymap.begin() == mymap.end())
		std::cout << "This is wrong\n";
	
	for (NM::set<int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
		std::cout << *it << '\n';

	std::cout << "Hello there\n";
	for (NM::set<int>::const_iterator it=mymap.begin(); it!=mymap.end(); it++)
		std::cout << *it<< '\n';
	std::cout << "General Kenobi\n";

	NM::set<int>::const_iterator it = mymap.begin();
	NM::set<int>::const_iterator ti = mymap.end();
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
	NM::set<int>::iterator end = mymap.end();
	while(it != end)
	{
		std::cout << *it<< '\n';
		it++;
	}

	out(BLUE2)
	out("**************      TEST VALUECOMP/KEYCOMP   ****************** ")
	out(END)
	
	NM::set<int>::key_compare mycomp = mymap.key_comp();
	std::cout << "comparing 3 to 2 " << std::endl;
	if (mycomp(3 , 2) == true )
		std::cout << BLUE2 << "3 is inferior to 2" << END << std::endl;
	else
		std::cout << BLUE2 << "3 is not inferior to 2" << END << std::endl;

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
	
	NM::set<int> foo,bar;
	foo.insert(100);
	foo.insert(200);
	bar.insert(10);
	bar.insert(1000);

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	out(BLUE2)
	out("**************      TEST OPERATOR=   ****************** ")
	out(END)
	
	NM::set<int> first;
	NM::set<int> second;
	first.insert(8);
	first.insert(6);
	first.insert(32);

	second=first;                	// second now contains 3 ints
	first=NM::set<int>();  		// and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';


	out(BLUE2)
	out("**************      TEST LOWER_BOUND   ****************** ")
	out(END)
	
	NM::set<int> mamap;
	NM::set<int>::iterator itlow;
    NM::set<int>::iterator itup;
	mamap.insert(20);
	mamap.insert(40);
	mamap.insert(60);
	mamap.insert(80);
	mamap.insert(100);


	itlow = mamap.lower_bound ('b');  // itlow points to b
	itup = mamap.upper_bound ('d');   // itup points to e (not d!)

	std::cout << "low : " << *itlow << '\n';
	std::cout << "up : " << *itup << '\n';

	mamap.erase(itlow,itup);
}

void	test_set_clear()
{
	NM::set<int> mymap;
	mymap.insert(-4);
	mymap.insert(2);
	mymap.insert(3);
	mymap.insert(746);
	mymap.insert(1);

	
	std::cout << "mymap size before clear is " << mymap.size() << std::endl;
	mymap.clear();
	std::cout << "mymap size after clear is " << mymap.size() << std::endl;

}

void test_set_swap()
{
	
	out(BLUE2)
	out("**************      TEST SWAP   ****************** ")
	out(END)
	
	NM::set<int> foo,bar;

	foo.insert(100);
	foo.insert(75);
 	bar.insert(11);
	bar.insert(22);
	bar.insert(33);


	NM::set<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	NM::set<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	std::cout << "foo contains:\n";
	for (NM::set<int>::iterator it=foo.begin();it!=foo.end(); ++it)
		std::cout << *it <<'\n';
	
	std::cout << "bar contains:\n";
	for (NM::set<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it <<'\n';
		
	foo.swap(bar); //tmp iterates through bar
					//tmp2 iterates through foo

	std::cout << "foo contains:\n";
	for (NM::set<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it <<'\n';

	std::cout << "bar contains:\n";
	for (NM::set<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it <<'\n';

	NM::set<int>	other;

	other.insert(73);
	other.insert(173);
	other.insert(763);
	other.insert(73854);
	other.insert(74683);
	other.insert(753);

	NM::set<int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	std::cout << "foo contains:\n";
	for (NM::set<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it <<'\n';

	std::cout << "bar contains:\n";
	for (NM::set<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it <<'\n';

	while(tmp != bar.end())
	{
		std::cout << *tmp <<'\n';
		tmp++;
	}
	tmp--;

	while(tmp2 != foo.end())
	{
		std::cout << *tmp2 << '\n';
		tmp2++;
	}
	tmp2--;

	other.swap(foo); //tmp2 iterates through other
					//tmp3 iterates throught foo
	print(other);
	print(foo);
	print(bar);
	while(tmp != bar.begin())
	{
		std::cout << *tmp <<'\n';
		tmp--;
	}
	std::cout << *tmp <<'\n';

	while(tmp2 != other.begin())
	{
		std::cout << *tmp2 <<  '\n';
		tmp2--;
	}
	std::cout << *tmp2<<  '\n';

	while(tmp3 != foo.end())
	{
		std::cout << *tmp3<< '\n';
		tmp3++;
	}
	tmp3--;

	bar.swap(foo);

	print(other);
	print(foo);
	print(bar);

	while(tmp != foo.end())
	{
		std::cout << *tmp <<'\n';
		tmp++;
	}

	while(tmp2 != other.end())
	{
		std::cout << *tmp2<<  '\n';
		tmp2++;
	}

	while(tmp3 != bar.begin())
	{
		std::cout << *tmp3 << '\n';
		tmp3--;
	}
	std::cout << *tmp3 << '\n';
}
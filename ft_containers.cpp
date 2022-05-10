/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:14:06 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/05/10 17:49:53 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorClass.hpp"

# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define BLUE3 "\x1B[34;1m"
# define END "\033[0m"
# define SIZE 42

int main()
{
    std::cout << PINK << "************** TEST CONSTRUCTOR ****************" << END << std::endl;
      // constructors used in the same order as described above:
    ft::vector<int> first;
    std::cout << "ok" <<std::endl;                                 // empty vector of ints
    ft::vector<int> second (4,100);
    std::cout << "ok" <<std::endl;
                         // four ints with value 100
    //std::cout << *second.begin() << " " << *second.end() << std::endl;             
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    std::cout << third.size() << std::endl;
    for (int i=0;i<(int)third.size() - 1;i++)
      std::cout << ' ' << third[i] << std::endl;   
    
    /**************************************************************************************************/
    std::cout << std::endl << "ok" <<std::endl; 
    ft::vector<int> fourth (third);
    
    for (int i=0;i<(int)fourth.size() - 1;i++)
      std::cout << ' ' << fourth[i];
    std::cout << '\n';
    std::cout << PINK << "************** TEST CAPACITY ****************" << END << std::endl;
    
    for (int i=0; i<100; i++) third.push_back(i);
    for (int i=0; i<100; i++) third.push_back(i);
    std::cout << "size: " << third.size() << "\n";
    std::cout << "capacity: " << third.capacity() << "\n";
    std::cout << "max_size: " << third.max_size() << "\n";
    third.pop_back();
    std::cout << "size: " << third.size() << "\n";
    third.clear();
    std::cout << "size: " << third.size() << "\n";

    std::cout << PINK << "************** TEST RESIZE ****************" << END << std::endl;
    ft::vector<int> myvector;
    for (int i=1;i<10;i++) myvector.push_back(i);
    std::cout << myvector.size() << std::endl;
    for (int i=0;i<(int)myvector.size();i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
    myvector.resize(5);
    std::cout << myvector.size() << std::endl;
    myvector.resize(8,100);
    std::cout << myvector.size() << std::endl;
    myvector.resize(12);
    std::cout << "end :" << *((myvector.end()- 1)) << std::endl;
    std::cout << PINK << "************** TEST ELEMENT ACCESS ****************" << END << std::endl;
    std::cout << "myvector contains:";
    for (int i=0;i<(int)myvector.size();i++)
    {
      try
      {
        std::cout << ' ' << myvector.at(i);
    }
    catch (const std::out_of_range& oor)
    {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    }
    std::cout << '\n';
    std::cout << "front: "<< myvector.front() << std::endl;
    std::cout << "back : " << myvector.back() << std::endl;
    std::cout << PINK << "************** MODIFIERS ****************" << END << std::endl;
    std::cout << BLUE2 << "**************  INSERT ****************" << END << std::endl;
    ft::vector<int>::iterator it;
    it = myvector.begin();
    std::cout << "my vector   :";
    for (int i=0;i<(int)myvector.size();i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
    it = myvector.insert(it, 4);
    std::cout << "new_content :";
    for (int i=0;i<(int)myvector.size();i++) // ok
      std::cout << ' ' << myvector[i];
    std::cout << std::endl;
  
    
    std::vector<int> v(3, 2);
    std::vector<int>::iterator t;
    t = v.begin();
    std::cout << "my vector   :";
    for (int i=0;i<(int)v.size();i++)
      std::cout << ' ' << v[i];
    std::cout << std::endl;
    v.insert(t, 5, 6);
    std::cout << "new_content :";
    for (int i=0;i<(int)v.size();i++)
      std::cout << ' ' << v[i];
    std::cout << std::endl;

    
    ft::vector<int> l(5, 8);
    std::cout << "my vector   :";
    for (int i=0;i< (int)l.size();i++)
      std::cout << ' ' << l[i];
    std::cout << std::endl;
    l.insert(l.begin(), v.begin(), v.end());
    std::cout << "new_content caca:";
    for (int i=0;i<(int)l.size();i++)
      std::cout << ' ' << l[i];
    std::cout << std::endl;
    
    
    l.clear();
    std::cout << BLUE2 << "**************  ERASE ****************" << END << std::endl;
    for (int i = 0; i < 10; i++)
    {
      l.push_back(i);
    }
    for (int i=0;i<(int)l.size();i++)
      std::cout << ' ' << l[i];
    std::cout << std::endl;
    l.erase(l.begin() + 4);
    for (int i=0;i<(int)l.size();i++)
      std::cout << ' ' << l[i];
    std::cout << std::endl;
    l.erase(l.begin(), (l.end() - 2));
    for (int i=0;i<(int)l.size();i++)
      std::cout << ' ' << l[i];
    std::cout << std::endl;
    std::cout << BLUE2 << "**************  ASSIGN ****************" << END << std::endl;
    
    ft::vector<int> f;
    ft::vector<int> s;
    ft::vector<int> th;

    f.assign (7,100);    
             // 7 ints with a value of 100
    ft::vector<int>::iterator iti;
    iti=f.begin()+1;
    s.assign (iti,f.end()-1); // the 5 central values of first
    int myints[] = {1776,7,4};
    th.assign (myints,myints+3);   // assigning from array.

    std::cout << "Size of first: " << int (f.size()) << '\n';
    std::cout << "Size of second: " << int (s.size()) << '\n';
    std::cout << "Size of third: " << int (th.size()) << '\n';
    
    std::cout << BLUE2 << "**************  SWAP  ****************" << END << std::endl;

    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
    std::cout << '\n';
    
    std::cout << BLUE2 << "**************  OPERATOR=  ****************" << END << std::endl;
    ft::vector<int> jet (3,0);
    ft::vector<int> li (5,0);

    li = jet;
    jet = ft::vector<int>();

    std::cout << "Size of jet: " << int(jet.size()) << '\n';
    std::cout << "Size of li : " << int(li.size()) << '\n';
    
    std::cout << PINK << "************** NON MEMBER FONCTION OVERLOADS ****************" << END << std::endl;
    std::cout << BLUE2 << "**************  RELATIONAL OPERATOR==  ****************" << END << std::endl;
    {
    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (2,200);   // two ints with a value of 200

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    }  
}

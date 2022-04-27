/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:14:06 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/04/27 18:09:27 by ldes-cou         ###   ########.fr       */
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
    std::cout << "ok" <<std::endl;                      // four ints with value 100
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    std::cout << "ok" <<std::endl; 
    //ft::vector<int> fourth (third);                       // a copy of third
    std::cout << PINK << "************** TEST CAPACITY ****************" << END << std::endl;
    //ft::vector<int> myvector;
    // set some content in the vector:
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
    std::cout << "end :" << *(myvector.end()) << std::endl;
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
    ft::vector<int>::iterator it;
    it = myvector.begin();
    for (int i=0;i<(int)myvector.size();i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
    it = myvector.insert(it, 4);
    for (int i=0;i<(int)myvector.size();i++)
      std::cout << ' ' << myvector[i];
    std::cout << std::endl;


    
    ft::vector<int> v(3, 2);
    ft::vector<int>::iterator t;
    t = v.begin();
    for (int i=0;i<(int)v.size();i++)
      std::cout << ' ' << v[i];
    std::cout << std::endl;
    v.insert(t, 5, 6);
    for (int i=0;i<(int)v.size();i++)
      std::cout << ' ' << v[i];
    std::cout << std::endl;
    std::vector<int> l(5, 8);
    for (int i=0;i<(int)l.size();i++)
      std::cout << ' ' << l[i];
    std::cout << std::endl;
    
    l.insert(l.begin(), v.begin(), v.end());
    for (int i=0;i<(int)l.size();i++)
      std::cout << ' ' << l[i];
    std::cout << std::endl;
    
    
    

  
    
      
}

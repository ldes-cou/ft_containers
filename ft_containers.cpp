/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:14:06 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/04/22 14:52:09 by ldes-cou         ###   ########.fr       */
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
    ft::vector<int> myvector;
    // set some content in the vector:
    for (int i=0; i<100; i++) myvector.push_back(i);
    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n";

  // std::cout << PINK << "************** TEST RESIZE ****************" << END << std::endl;
  // std::vector<int> myvector;
  //   for (int i=1;i<10;i++) myvector.push_back(i);

  //   myvector.resize(5);
  //   myvector.resize(8,100);
  //   myvector.resize(12);

  //   std::cout << "myvector contains:";
  //   for (int i=0;i<(int)myvector.size();i++)
  //     std::cout << ' ' << myvector[i];
  //   std::cout << '\n'; //va pas chercher la bonne valeur
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:02:51 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/17 15:40:03 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/vector.hpp"
#include "tests.hpp"
#include <vector>
#include <list>

#ifndef NAMESPACE
# define NAMESPACE std

#endif

using namespace NAMESPACE;

int main()
{
    //std::cout <<  GREEN << "********************************************* FT *********************************************" << std::endl << std::endl << END;
    test_vector_ft();
    //std::cout << '\n' << BLUE1 << "********************************************* STD *********************************************" << std::endl << std::endl << END;
    // test_vector_std();
    // std::cout << '\n';
    return 0;
}
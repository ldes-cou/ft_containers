# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define END "\033[0m"
# define SIZE 42

# if !defined(NM)
#  define NM ft
# endif

#include "includes/map.hpp"

#include <map>
#include <time.h>



void test_vector();
void test_stack();
void test_map();
void test_set();

int main()
{

    clock_t tStart = clock();

    std::cout << PINK << "/**************************   STACK   ******************************/" << END << std::endl; 
    test_stack();
    std::cout  << std::endl;

    std::cout << PINK << "/**************************   VECTOR  ******************************/" << END << std::endl; 
    test_vector();
    std::cout << std::endl;

    std::cout << PINK << "/**************************     MAP     ***************************/" << END << std::endl; 
    test_map();
    std::cout << std::endl;

    std::cout << PINK << "/**************************     SET     ***************************/" << END << std::endl; 
    test_set();
    std::cout << std::endl;

    std::cout << PURPLE << "Time taken: "  << (double)(clock() - tStart)/CLOCKS_PER_SEC << std::endl;
    return 0;
}


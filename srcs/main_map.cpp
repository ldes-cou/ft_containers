# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PINK "\x1B[45;1m"
# define BLUE1 "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE2 "\x1B[36m"
# define BLUE3 "\x1B[34;1m"
# define END "\033[0m"
# define SIZE 42

# if !defined(NM)
#  define NM ft
# endif

#include "includes/tests.hpp"
#include "includes/map.hpp"

#include <map>
#include <time.h>



void test_vector();
void test_stack();
void test_map();

int main()
{
   // test_new_algo();
    clock_t tStart = clock();
    test_stack();
    test_map();
    test_vector();
    std::cout << "Time taken: "  << (double)(clock() - tStart)/CLOCKS_PER_SEC << std::endl;
    return 0;
}



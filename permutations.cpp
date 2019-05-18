#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cassert>

// C++17

template<class It>
size_t countPermutations(It p, It q)
{
    std::vector copy(p,q);
    std::sort(copy.begin(), copy.end());
    size_t acc = 0;
    do {
        if(std::adjacent_find(copy.cbegin(), copy.cend()) == copy.cend())
            acc++;
    } while(std::next_permutation(copy.begin(), copy.end()));

    return acc;
}


int main()
{
    using namespace std;
    array a1 = {1,2,1};
    size_t c1 = countPermutations(a1.begin(), a1.end()); // 1
    assert(c1 == 1);

    array a2 = {1,2,3};
    size_t c2 = countPermutations(a2.begin(), a2.end()); // 6
    assert(c2 == 6);

    array a3 = {1,2,3,4,4};
    size_t c3 = countPermutations(a3.begin(), a3.end()); // 36
    assert(c3 == 36);
}



#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

using namespace std;


int main() {
    // set of elements to permute
    std::vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // size of one permutation
    int k = 3;
    
    // generate all permutations in lexicographic order
    do {
        for (int i = 0; i < k; i++) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(elements.begin(), elements.end()) && k--);
    
    return 0;
}
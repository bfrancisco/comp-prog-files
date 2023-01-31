#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main ()
{
    std::set<int> myset = {3, 5, 8, 10, 13, 15, 18, 23};
    std::set<int>::iterator itlow,itup;

    itlow=myset.lower_bound(4);

    // itup=myset.upper_bound (90);
    
    cout << *(--itlow) << endl;
    // cout << *itup << endl;

    return 0;
}
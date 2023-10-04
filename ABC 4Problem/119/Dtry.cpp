#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> a = {1,3,5,7,9,11};

    int lo = lower_bound(a.begin(), a.end(), 3) - a.begin();
    int hi = upper_bound(a.begin(), a.end(), 3) - a.begin();

    cout << lo << " " << hi;
    return 0;
}   
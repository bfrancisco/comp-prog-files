#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> a = {9,7,5,3};
    cout << *lower_bound(a.end(), a.begin(), 7) << endl;
    
    return 0;
}
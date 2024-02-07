#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (freq.find(x) == freq.end()) freq[x]=1;
        else freq[x]++;
    }

    auto l = freq.begin(), r = freq.rbegin();
    

    return 0;
}
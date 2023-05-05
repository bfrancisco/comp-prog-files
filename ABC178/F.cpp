#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    unordered_map<int, int> freq;

    for (int i = 0; i < 2*n; i++){
        int x; cin >> x;
        if (freq.find(x) == freq.end())
            freq[x] = 1;
        else
            freq[x]++;
    }
    bool pas = true;
    for (auto &[k, v] : freq){
        if (v > n/2){
            pas = false;
            break;
        }
    }

    
    return 0;
}
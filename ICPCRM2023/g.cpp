#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int n;
    ll r;
    cin >> n >> r;

    map<ll, int> freq;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        freq[x]++;
    }

    for (auto [k, v] : freq){
        cout << k << " " << v << endl;
    }

    


    return 0;
}
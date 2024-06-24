#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int n; cin >> n;
    vector<int> city(n+1);
    for (int i = 1; i <= n; i++){
        cin >> city[i];
    }
    city[0] = 0;
    sort(city.begin(), city.end());

    int q; cin >> q;
    while (q--){
        int c; cin >> c;
        if (c < city[1]) { cout << 0 << endl; continue; }
        int lo = lower_bound(city.begin(), city.end(), c) - city.begin();
        int up = upper_bound(city.begin(), city.end(), c) - city.begin();
        // cout << lo << " " << up << endl;
        if (lo > n) cout << n << endl;
        else if (city[lo] == c) cout << up-1 << endl;
        else cout << lo-1 << endl;
    }
    

    return 0;
}
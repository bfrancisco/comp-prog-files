#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b(n-1);
    for (int i = 0; i < n-1; i++){
        b[i] = a[i] + a[i+1];
        // cout << b[i] << " ";
    }
    // cout << endl;

    map<int, int> db;
    vector<int> used(n-1, 0);
    db[b[0]]++;
    used[0]++;
    for (int i = 1; i < n-1; i++){
        if (used[i-1] && b[i] == b[i-1]) continue;
        db[b[i]]++;
        used[i] = 1;
    }

    int mx = 1;
    for (auto [k, v] : db){
        // cout << k << " " << v << endl;
        mx = max(mx, v);
    }

    cout << mx << endl;
    
    return 0;
}
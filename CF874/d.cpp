#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int mxi = -1, mxi2 = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == n){
            mxi = i;
        }
        else if (a[i] == n-1){
            mxi2 = i;
        }
    }

    if (n == 1){
        cout << a[0] << endl;
        return;
    }

    if (mxi == 0) mxi = mxi2;

    vector<vector<int>> bank;

    for (int l = 0; l < mxi; l++){
        // cout << l << endl;
        vector<int> tmp;
        for (int i = mxi; i < n; i++){
            tmp.push_back(a[i]);
        }
        // rev
        for (int i = mxi-1; i >= l; i--){
            tmp.push_back(a[i]);
        }
        for (int i = 0; i < l; i++){
            tmp.push_back(a[i]);
        }
        bank.push_back(tmp);
    }

    if (mxi == n-1){
        vector<int> tmp;
        tmp.push_back(a[mxi]);
        for (int i = 0; i < mxi; i++){
            tmp.push_back(a[i]);
        }
        bank.push_back(tmp);
    }

    sort(bank.begin(), bank.end(), greater<vector<int>>());

    // for (auto v : bank){
    //     for (auto e : v) cout << e << " ";
    //     cout << endl;
    // } cout << endl;

    for (int i = 0; i < n; i++) cout << bank[0][i] << " ";
    cout << endl;
    
    
}

int main(){

    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;

    unordered_map<int, int> db;
    vector<vector<int>> in;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        vector<int> temp;
        for (int j = 0; j < k; j++){
            int x; cin >> x;
            temp.push_back(x);
            if (db.find(x) == db.end()){
                db[x] = 1;
            }
            else{
                db[x]++;
            }
        }
        in.push_back(temp);
    }
    
    for (auto vec : in){
        bool pas = true;
        for (auto x : vec){
            if (db[x] - 1 <= 0) pas = false;
        }
        if (pas) {cout << "Yes" << endl; return;}
    }

    cout << "No" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;

    unordered_map<int, int> db;
    bool pas = false;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        bool goodcase = true;

        for (int j = 0; j < k; j++){
            int x; cin >> x;
            if (db.find(x) == db.end()){
                db[x] = 1;
                goodcase = false;
            }
            // else{
            //     db[x]++;
            // }
        }
        if (goodcase) pas = true;
    }

    if (pas) cout << "Yes" << endl;
    else cout << "No" << endl;
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
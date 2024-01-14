#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    int low = -1000000000;
    int high = 1000000000;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int c, v; cin >> c >> v;
        if (c == 1){
            low = max(low, v);

        }
        else if (c == 2){
            high = min(high, v);
        }
        else{
            a.push_back(v);
        }
    }
    int ans = high-low + 1;

    for (auto e : a){
        if (low <= e && e <= high) ans--;
    }
    cout << (low <= high ? ans : 0) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
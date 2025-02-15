#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int l = 0, r = 0;
    map<int, int> freq;
    for (auto x : a){
        freq[x]++;
    }

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
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        a[i] = i+1;
    }

    for (int i = n-(n-k), j = 1; i >= 0; i--, j++){
        a[i] = j;
    }

    reverse(a.begin(), a.end());
    for (auto x : a) cout << x << " "; cout << endl;



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
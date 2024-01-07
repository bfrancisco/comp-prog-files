#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int c = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        c += a[i];
    }
    cout << (n==c ? "YES" : "NO") << endl;
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
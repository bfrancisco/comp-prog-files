#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), pa(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    pa[0] = a[0];
    for (int i = 1; i < n; i++) pa[i] = pa[i-1] + a[i];

    int mxb = 0;
    int score = 0;
    for (int i = 0; i < n && i < k; i++){
        mxb = max(mxb, b[i]);
        score = max(score, pa[i] + mxb*(k-i-1));
    }
    cout << score << endl;
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
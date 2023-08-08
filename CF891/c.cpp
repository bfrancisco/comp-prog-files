#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    int m = n * (n-1) / 2;
    vector<int> a(m);
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int inc = n;
    for (int i = 0; i < m; i += inc){
        cout << a[i] << " ";
        inc--;
    }
    cout << 1000000000 << endl;

    
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
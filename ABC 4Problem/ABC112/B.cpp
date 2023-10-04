#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, T; cin >> n >> T;
    int mx = 1e9;

    for (int i = 0; i < n; i++){
        int c, t; cin >> c >> t;
        if (c < mx && t <= T)
            mx = c;
    }
    if (mx == 1e9) cout << "TLE";
    else cout << mx;

    return 0;
}
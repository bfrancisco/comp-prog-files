#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m; cin >> n >> m;
    vector<ll> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    // cout << "answ" << endl;
    ll ans = 0;
    for (int i = 0; i < m; i++){
        int j = i-1;
        while(j >= 0 && a[j] != a[i]) j--;
        // cout << "j:" << j << endl;
        ans = ans + (n-1) - (i-j-1);
        
        cout << ans << endl; 
    }

    return 0;
}
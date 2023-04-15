#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m; cin >> n >> m;

    if (n%m==0) cout << 0 << endl;
    else {
        ll r = n%m;
        cout << min(r, m-r) << endl;
    }

     
    return 0;
}   
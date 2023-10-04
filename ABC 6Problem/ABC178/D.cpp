#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    vector<ll> a(n+1);
    a[1] = a[2] = 0;
    a[3] = a[4] = a[5] = 1;
    for (int i = 6; i <= n; i++)
        a[i] = (a[i-1] + a[i-3]) % 1000000007;
    cout << a[n] << endl;
    return 0;
}
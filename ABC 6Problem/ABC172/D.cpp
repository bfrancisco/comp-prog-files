#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, i, j, ans = 0; cin >> n;
    vector<ll> a(n+1, 1);
    for (i = 3; i <= n; i++)
        for (j = i; j <= n; j+=i)
            a[j]++;

    for (i = 1; i <= n; i++)
        ans += (i%2 ? a[i]*i : (a[i]+1)*i);
    
    cout << ans << endl;
    
    return 0;
}
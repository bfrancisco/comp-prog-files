#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll a[100010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int c = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < 0) c++;
        a[i] = abs(a[i]);
        ans += abs(a[i]);
    }
    
    sort(a, a+n);
    // cout << c << " " << a[0] << endl;
    if (c%2) ans -= a[0]*2LL;

    cout << ans << endl;
    


    return 0;
}
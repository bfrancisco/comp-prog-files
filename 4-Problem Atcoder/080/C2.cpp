#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    ll a[101][11];
    ll b[101][11];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 10; j++){
            cin >> b[i][j];
        }
    }
    ll ans = -(1e12);
    for (int bit = 1; bit < (1 << 10); bit++){
        ll res = 0;
        for (int i = 0; i < n; i++){
            ll count = 0;
            for (int j = 0; j < 10; j++){
                if ((bit >> j & 1) && a[i][j] == 1ll){
                    count++;
                }
            }
            res += b[i][count];
        }
        ans = max(ans, res);
    }

    cout << ans;

    return 0;
}
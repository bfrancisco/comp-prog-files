#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n+1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll jmp; cin >> jmp;
    int q; cin >> q;
    int lg = 30; // guess
    vector<vector<int>> lift(n+1, vector<int>(lg+1,0));

    // base case
    for (int i = 1; i <= n; i++) {
        lift[i][0] = (upper_bound(a.begin(), a.end(), a[i] + jmp) - a.begin()) - 1;
    }

    for (int j = 1; j <= lg; j++) {
        for (int i = 1; i <= n; i++) {
            lift[i][j] = lift[lift[i][j-1]][j-1];
        }
    }

    while (q--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        int ans = 0;
        for (int k = lg; k >= 0; k--) {
            if (lift[u][k] < v) {
                ans += (1<<k);
                u = lift[u][k];
            }
        }
        cout << ans+1 << '\n';
    }
    return 0;
}
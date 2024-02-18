#include <bits/stdc++.h>
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const int MAXN = 500;
using namespace std;

int n, m;
int adjMatrix[MAXN][MAXN], A2[MAXN][MAXN], A4[MAXN][MAXN];
ll d[MAXN];
map<pair<int,int>,ll> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int cc, dd, ee, i, j, k, a, b;
    
    for (i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
        d[a]++;
        d[b]++;
    }
 
    for (cc = 0; cc < n; ++cc)
        for (dd = cc + 1; dd < n; ++dd)
            for (ee = dd + 1; ee < n; ++ee)
                if (adjMatrix[cc][dd] && adjMatrix[dd][ee] && adjMatrix[ee][cc]){
                    mp[{cc,dd}]++;
                    mp[{dd,ee}]++;
                    mp[{cc,ee}]++;
                }
    ll tri = 0;
    for (const auto& m : mp){
        tri += m.second*(m.second-1)/2;
        tri %= MOD;
    }
 
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            for (k = 0; k < n; ++k)
                (A2[i][k] += adjMatrix[i][j] * adjMatrix[j][k])%MOD;
    
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            for (k = 0; k < n; ++k)
                (A4[i][k] += A2[i][j] * A2[j][k])%MOD;

    ll degsum = accumulate(d, d+n, 0);
    ll degsumsq = inner_product(d, d+n, d, 0);
    ll tr = 0;
    for (i = 0; i < n; ++i)
        tr += A4[i][i];
 
    ll ans = (tr - 2 * degsumsq + degsum);
    cout << (ans / 8 - tri) % MOD << "\n";
 
    return 0;
}
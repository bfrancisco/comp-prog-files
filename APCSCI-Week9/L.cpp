// Mysterious Present - the mail problem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, w0, h0;
vector<pair<int, int>> hw;
int dp[5010], link[5010];

int rec(int u){
    if (dp[u] > 0) return dp[u];
    // cout << "rec: " << u << endl;
    for(int v = 1; v < n; v++){
        if (hw[u].first < hw[v].first && hw[u].second < hw[v].second){
            int val = rec(v);
            if (val + 1 > dp[u]){
                link[u] = v;
                dp[u] = val+1;
            }
        }
    }
    return dp[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> w0 >> h0;
    // w.resize(n+1);
    // h.resize(n+1);
    // dp.resize(n+1);
    // link.resize(n+1);
    hw.push_back({w0, h0});
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        // if (x <= w0 || y <= h0) continue;
        hw.push_back({x, y});
    }
    n = hw.size();

    // sort(hw.begin(), hw.end());

    int ans = rec(0);
    cout << ans << endl;
    for (int node = link[0]; node != 0; node = link[node]){
        cout << node << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<int>> adj;
vector<int> vis;

void dfs(int u, vector<int>& reg){
    // cout << u << endl;
    reg.push_back(u);
    for (auto v : adj[u]){
        if (vis[v]) continue;
        vis[v] = 1;
        dfs(v, reg);
    }
}

ll calc(int i, vector<int>& reg, set<int> avail_colors, vector<int>& cur_colors){
    if (i == reg.size()) return 1ll;

    for (auto v : adj[reg[i]]){
        if (avail_colors.find(cur_colors[reg[i]]) != avail_colors.end()){
            avail_colors.erase(cur_colors[reg[i]]);
        }
    }

    ll ret = 0;
    for (auto c : avail_colors){
        cur_colors[reg[i]] = c;

        set<int> new_colors;
        for (auto c : avail_colors){
            new_colors.insert(c);
        }
        new_colors.erase(c);
        if (new_colors.size() == 0) continue;

        cout << "U: " << reg[i] << endl;
        cout << "avail colors: ";
        for (auto e : avail_colors) cout << e << " ";
        cout << endl;
        for (int i = 1; i <= n; i++) cout << i << " " << cur_colors[i] << endl;
        cout << endl;

        ret += calc(i+1, reg, new_colors, cur_colors);
        cur_colors[reg[i]] = 0;
    }

    return ret;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis.resize(n+1);
    ll ans = 1;
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        cout << "REGION: " << i << endl;

        vis[i] = 1;
        vector<int> reg;
        dfs(i, reg);


        // for (auto e : reg) cout << e << " "; cout << endl << endl;

        set<int> avail_colors = {1,2,3};
        vector<int> cur_colors(n+1, 0);
        ans *= calc(0, reg, avail_colors, cur_colors);
    }

    cout << ans << endl;

    
    return 0;
}
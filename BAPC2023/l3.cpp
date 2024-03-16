#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN = 1e5+10;
int n, m;
vector<vector<int>> adj;

int id = 0, sccCount = 0;
int ids[MAXN], low[MAXN], onStack[MAXN];
stack<int> st;

vector<vector<int>> sccAdj;
vector<int> indeg;
vector<int> vis;
int ans = 0;

void dfs2(int u){
    for (auto v : sccAdj[u]){
        if (vis[v]) continue;
        vis[v] = 1;
        dfs2(v);
    }
}

void dfs(int at){
    st.push(at);
    onStack[at] = 1;
    ids[at] = low[at] = id++;

    for (auto to : adj[at]){
        if (ids[to] == -1)
            dfs(to);
        if (onStack[to])
            low[at] = min(low[at], low[to]);
    }

    if (ids[at] == low[at]){
        while (!st.empty()){
            int node = st.top();
            st.pop();
            onStack[node] = 0;
            low[node] = ids[at];
            if (node == at)
                break;
        }
        sccCount++;
    }
}

void fixIndex(){
    map<int, int> old_new;
    int newi = 0;
    for (int i = 0; i < n; i++){
        if (old_new.find(low[i]) == old_new.end()){
            old_new[low[i]] = newi++;
        }
    }
    for (int i = 0; i < n; i++){
        low[i] = old_new[low[i]];
    }
}

void tarjan(){
    memset(ids, -1, sizeof(ids));
    for (int i = 0; i < n; i++){
        if (ids[i] == -1)
            dfs(i);
    }
    fixIndex();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    tarjan();
    // cout << sccCount << endl;
    sccAdj.resize(sccCount);
    indeg.assign(sccCount, 0);
    for (int u = 0; u < n; u++){
        // cout << u+1 << " " << low[u] << endl; 
        for (auto v : adj[u]){
            if (low[u] == low[v]) continue;
            sccAdj[low[u]].push_back(low[v]);
            indeg[low[v]]++;
        }
    }

    // for (int i = 0; i < sccCount; i++){
    //     cout << "scc: " << i << endl;
    //     for (auto v : sccAdj[i]) cout << v << " "; cout << endl;
    // }

    // for (int u = 0; u < sccCount; u++){
    //     cout << u << " " << indeg[u] << endl;
    // }cout << endl;


    set<pair<int, int>> topo;
    for (int u = 0; u < sccCount; u++){
        // cout << u << endl;
        // for (auto v : sccAdj[u]) cout << v << " "; cout << endl;
        topo.insert({indeg[u], u});
    }
    // for (auto [o, u] : topo){
    //     cout << u << " ";
    // }cout << endl;

    vis.assign(sccCount, 0);
    for (auto &[indegree, u] : topo){
        if (vis[u]) continue;
        vis[u] = 1;
        dfs2(u);
        // cout << u << endl;
        // for (int i = 0; i < sccCount; i++) cout << vis[i] << " "; cout << endl;
        ans++;
    }
    cout << ans << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN = 1e5+10;
int n;
vector<vector<int>> adj;

int id = 0, sccCount = 0;
int ids[MAXN], low[MAXN], onStack[MAXN];
stack<int> st;

vector<pair<int, int>> ans;

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

void dfs2(int u, int prev, int grandpa, int reg, vector<vector<int>>& leaves, vector<vector<int>>& sccRevAdj, map<int, int>& sccRep){
    if (sccRevAdj[u].size() == 0){
        if (reg == 0)
            ans.push_back({sccRep[grandpa], sccRep[u]});
        leaves[reg].push_back({})
        return;
    }
    for (auto v : sccRevAdj[u]){
        if (v == prev) continue;
        dfs2(v, u, grandpa, sccRevAdj, sccRep);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; i++){
        int v; cin >> v;
        v--;
        adj[i].push_back(v);
    }
    tarjan();

    if (sccCount == 1) {cout << 0 << endl; return 0; }

    map<int, int> sccRep;
    for (int i = 0; i < n; i++){
        if (sccRep.find(low[i]) == sccRep.end()){
            sccRep[low[i]] = i;
        }
    }

    vector<vector<int>> sccRevAdj(sccCount); // reverse adjlist, so we bfs
    set<int> sccPathRep; // startingpoint of bfs
    for (int u = 0; u < n; u++){
        for (auto v : adj[u]){
            if (low[u] == low[v]){
                sccPathRep.insert(low[u]);
            }
            else{
                sccRevAdj[low[v]].push_back(low[u]);
            }
        }
    }

    vector<int> regions; // reg[i] is representative of region i
    int r = sccPathRep.size(); // no. of reigons
    for (auto x : sccPathRep) regions.push_back(x);

    vector<vector<int>> leaves(sccCount);
    // complete first region (SCC)
    dfs2(regions[0], -1, regions[0], 0, leaves, sccRevAdj, sccRep);

    // precalculate leaves of all regions

    // connect first region to leaves of 2nd region, 2nd->3rd, ...
    // connect head of r-th region to head of r-1th region, ...

    cout << ans.size() << endl;
    for (auto& [a, b] : ans){
        cout << a+1 << " " << b+1 << endl;
    }

    return 0;
}
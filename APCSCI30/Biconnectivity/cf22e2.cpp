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

void dfs2(int u, int prev, int region, vector<vector<int>>& tails, vector<vector<int>>& sccRevAdj){
    if (sccRevAdj[u].empty()){
        // if (region == 1){cout << "HELLO" << u << endl;}
        tails[region].push_back(u);
        return;
    }
    for (auto v : sccRevAdj[u]){
        if (v == prev) continue;
        dfs2(v, u, region, tails, sccRevAdj);
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

    vector<vector<int>> sccRevAdj(sccCount); // reverse adjlist
    set<int> headsset; // size is no. of regions
    for (int u = 0; u < n; u++){
        for (auto v : adj[u]){
            if (low[u] == low[v]){
                headsset.insert(low[u]);
            }
            else{
                sccRevAdj[low[v]].push_back(low[u]);
            }
        }
    }
    vector<int> heads;
    for (auto h : headsset) heads.push_back(h);
    int r = heads.size();
    vector<vector<int>> tails(r);
    for (int i = 0; i < r; i++){
        dfs2(heads[i], -1, i, tails, sccRevAdj);
    }

    // for (int u = 0; u < sccCount; u++){
    //     cout << u << "  :  ";  for (auto v : sccRevAdj[u]) cout << v << " "; cout << endl;
    // }

    // for (auto h : heads) cout << h << " "; cout << endl;
    // for (int i = 0; i < r; i++){
    //     cout << i << " |  "; for (auto t : tails[i]) cout << t << " "; cout << endl;
    // }

    // 1st head - 2nd tail, 2nd head - 3rd tail, ... , last head - first tail
    for (int i = 0; i < r-1; i++){
        for (auto t : tails[i+1]){
            ans.push_back({sccRep[heads[i]], sccRep[t]});
        }
    }
    for (auto t : tails[0]){
        ans.push_back({sccRep[heads[r-1]], sccRep[t]});
    }

    cout << ans.size() << endl;
    for (auto &[a, b] : ans) cout << a+1 << " " << b+1 << endl;

    return 0;
}
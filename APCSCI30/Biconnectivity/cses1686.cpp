#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN = 1e5+10;
int n;
vector<vector<int>> adj;
vector<vector<int>> sccadj;
vector<ll> dp;
vector<ll> SCCcost;

int id = 0, sccCount = 0;
int ids[MAXN], low[MAXN], onStack[MAXN];
stack<int> st;

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

void tarjan(){
    memset(ids, -1, sizeof(ids));
    for (int i = 0; i < n; i++){
        if (ids[i] == -1)
            dfs(i);
    }
}

ll dfs2(int u, int prev){
    if (dp[u] != -1){
        return dp[u];
    }
    ll val = 0;
    for (auto v : sccadj[u]){
        if (prev == v) continue;
        val = max(val, dfs2(v, u));
    }
    dp[u] = val + SCCcost[u];
    return dp[u];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m;
    cin >> n >> m;
    vector<ll> cost(n);
    for (int i = 0; i < n; i++){
        cin >> cost[i];
    }
    adj.resize(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    tarjan();

    // map<int, int> sccRep;
    // for (int i = 0; i < n; i++){
    //     if (sccRep.find(low[i]) == sccRep.end()){
    //         sccRep[low[i]] = i;
    //     }
    // }

    sccadj.resize(sccCount);
    SCCcost.resize(sccCount);
    vector<int> starting;

    for (int u = 0; u < n; u++){
        SCCcost[low[u]] += cost[u];
        cout << u << endl;
        if (adj[u].empty())
            starting.push_back(u);
        for (auto v : adj[u]){
            if (low[u] != low[v]){
                cout << low[v] << endl;
                sccadj[low[v]].push_back(low[u]);
                // sccadj is reversed
            }
        }
    }


    for (int i = 0; i < sccCount; i++){
        cout << i << "  |  ";
        for (auto v : sccadj[i]) cout << v << " "; cout << endl;
    }

    dp.assign(sccCount, -1);
    ll ans = 0;
    for (auto s : starting){
        ans = max(ans, dfs2(s, -1));
    }

    cout << ans << endl;

    return 0;
}
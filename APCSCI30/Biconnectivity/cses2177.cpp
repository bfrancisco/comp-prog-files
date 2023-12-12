#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN = 1e5+10;
int n;
vector<vector<int>> adj;

int id = 0, sccCount = 0;
int ids[MAXN], low[MAXN], onStack[MAXN];
stack<int> st;

vector<set<int>> newadj;

void dfs(int at, int prev){
    st.push(at);
    onStack[at] = 1;
    ids[at] = low[at] = id++;

    for (auto to : adj[at]){
        if (to == prev)
            continue;
        if (newadj[to].find(at) == newadj[to].end())
            newadj[at].insert(to);
        if (ids[to] == -1)
            dfs(to, at);
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
            dfs(i, -1);
    }
    fixIndex();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m;
    cin >> n >> m;
    adj.resize(n);
    newadj.resize(n);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tarjan();

    if (sccCount > 1) { cout << "IMPOSSIBLE" << endl; return 0; }
    for (int u = 0; u < n; u++){
        for (auto v : newadj[u]){
            cout << u+1 << " " << v+1 << endl;
        }
    }

    return 0;
}
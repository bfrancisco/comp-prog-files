#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN = 1e5+10;
int n;
vector<vector<int>> adj;

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
    int bigSCC = -1;
    for (int i = 0; i < n; i++){
        if (sccRep.find(low[i]) == sccRep.end()){
            sccRep[low[i]] = i;
        }
        else{
            bigSCC = low[i];
        }
    }

    vector<int> sccAdj(sccCount, -1); // cycles dont have outdegs
    set<int> lonelySCC;
    for (int i = 0; i < sccCount) lonelySCC.insert(i);
    for (int u = 0; u < n; u++){
        for (auto v : adj[u]){
            if (low[u] == low[v]) continue;
            sccAdj[low[u]] = low[v];
            lonelySCC.erase(low[v]);
        }
    }

    // for (int i = 0; i < sccCount; i++) cout << i << " " << sccAdj[i] << endl;
    vector<pair<int, int>> ans;
    // bfs from lonelySCCs
    vector<int> reached(sccCount, -1);
    for (auto ls : lonelySCC){
        int node = ls;
        while ()
    }

    return 0;
}
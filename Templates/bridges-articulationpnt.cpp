// for undirected graphs

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAX = 1e5+1;
int t = 0; //time
vector<vector<int>> adj;
int disc[MAX], low[MAX];

vector<pair<int, int>> bridges;
vector<int> artic_pnts;

void dfs(int u, int p){
    disc[u] = low[u] = t++;
    int children = 0;
    bool has_low_child = false;
    
    for (auto v : adj[u]){
        if (disc[v] == -1){
            // tree edge
            dfs(v, u);

            low[u] = min(low[u], low[v]);
            children++;

            if (low[v] > disc[u]){
                bridges.push_back({u, v});
            }
            if (low[v] >= disc[u]){
                has_low_child = true;
            }
        }
        else if (v != p){
            // back edge
            low[u] = min(low[u], disc[v]);
        }
    }

    if ((p == -1 and children >= 2) or (p != -1 and has_low_child)){
        artic_pnts.push_back(u);
    }
}

void printdata(){
    cout << "Bridges:" << endl;
    for (auto &[u, v] : bridges){
        cout << u << " " << v << endl;
    }
    cout << "\nArticulation Points:" << endl;
    for (auto u : artic_pnts){
        cout << u << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        // u++; v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        disc[i] = low[i] = -1;
    }

    for (int i = 1; i <= n; i++){
        dfs(i, -1);
    }

    printdata();
    

    return 0;
}

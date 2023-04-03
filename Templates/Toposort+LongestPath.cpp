#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<int>> adj;
vector<int> indeg;
vector<int> maxPath; // dp
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    adj.resize(n+1);
    indeg.resize(n+1, 0);
    maxPath.resize(n+1, 0);

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v] ++;
    }

    queue<int> q;
    for (int u = 1; u <= n; u++){
        if (indeg[u] == 0)
            q.push(u);
    }

    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : adj[u]){
            maxPath[v] = max(maxPath[v], 1 + maxPath[u]);
            indeg[v] --;
            if (indeg[v] == 0){
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int u = 1; u <= n; u++){
        ans = max(ans, maxPath[u]);
    }
    cout << ans;
    return 0;
}
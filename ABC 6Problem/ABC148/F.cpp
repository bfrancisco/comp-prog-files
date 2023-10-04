#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> adj;
int n, S, E;
int vis[100010];
int distS[100010];
int distE[100010];

void dfs(int u, int d, char c){
    if (c=='S') distS[u] = d;
    else distE[u] = d;

    for (auto v : adj[u]){
        if (c=='S' && distS[v] == -1) dfs(v, d+1, 'S');
        else if (c=='E' && distE[v] == -1) dfs(v, d+1, 'E');
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> S >> E;
    adj.resize(n+1);
    for (int i = 0; i <= n; i++){
        distS[i] = -1;
        distE[i] = -1;
    }

    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(S, 0, 'S');
    dfs(E, 0, 'E');

    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (distS[i] < distE[i]){
            ans = max(ans, distE[i]);
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << distS[i] << endl;
    // }
    cout << --ans << endl;
    

    return 0;
}   
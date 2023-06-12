#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll facto[200001];
ll n;
vector<vector<int>> adj;

void precompfact(){
    facto[1] = 1;
    for (int i = 2; i <= n; i++){
        facto[i] = i*facto[i-1];
    }
}

void bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, adj[start].size()});
     
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    precompfact();
    adj.resize(n+1);

    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++){
        bfs(i);
    }
    
    
    return 0;
}
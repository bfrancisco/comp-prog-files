#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> adj(n+1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u]++;
        adj[v]++;
    }

    for (int i = 1; i <= n; i++)
        cout << adj[i] << endl;

    return 0;
}
bool bellman(int s){
    dist[s] = 0;
    for (int i = 0; i < n-1; i++){
        for (int u = 1; u <= n; u++){
            for (auto& [v, w] : adj[u]){
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
    ll ans = dist[n];
    for (int u = 1; u <= n; u++){
        for (auto& [v, w] : adj[u]){
            dist[v] = max(dist[v], dist[u] + w);
            // if dist[v] changes, there's a cycle
        }
    }
    return ans == dist[n];
}
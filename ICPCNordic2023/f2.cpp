#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

const int MXSIEVE = 500;

vector<ll> sieve(int n){
    int prime[MXSIEVE+1];
    memset(prime, 1, sizeof(prime));
    for (int p = 2; p*p <= n; p++){
        if (prime[p]){
            for (int i = p*p; i <= n; i += p){
                prime[i] = 0;
            }
        }
    }

    vector<ll> primes;
    for (int i = 2; i <= n; i++){
        if (prime[i]) primes.push_back(i);
    }

    return primes;
}

int n;
vector<vector<int>> adj;
vector<int> parent;
vector<pair<int, vector<int>>> db; // depth, path

void dfs(int u, int p, int d){
    bool is_leaf = true;
    for (auto v : adj[u]){
        if (v == p) continue;
        is_leaf = false;
        parent[v] = u;
        dfs(v, u, d+1);
    }
    if (is_leaf){
        vector<int> path;
        int x = u;
        while (x != 1){
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(), path.end());
        db.push_back({d, path});
    }
}

int main(){
    vector<ll> primes = sieve(MXSIEVE); // 95 primes
    cin >> n;
    adj.resize(n+1);
    parent.assign(n+1, -1);

    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    sort(db.begin(), db.end(), greater<pair<int, vector<int>>>());
    // for (auto &[depth, path] : db){
    //     cout << "depth: " << depth << endl;
    //     for (auto x : path) cout << x << " "; cout << endl;
    // }

    int ip = 0;
    vector<ll> val(n+1, 1);
    for (auto &[depth, path] : db){
        for (auto u : path){
            if (val[u] == 1 || val[u] % primes[ip] == 0){
                val[u] = val[parent[u]] * primes[ip];
            }
        }
        ip += 1;
    }

    for (int i = 1; i <= n; i++) cout << val[i] << " "; cout << endl;
    
    return 0;
}
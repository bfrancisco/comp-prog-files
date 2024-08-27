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

    vector<ll> primes = {1};
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
        while (x != -1){
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(), path.end());
        db.push_back({d, path});
    }
}

int getlca(vector<int>& a, vector<int>& b){
    int lca = 1;
    for (int i = 0; i < max(a.size(), b.size()); i++){
        if (a[i] == b[i]) lca = a[i];
        else break;
    }
    return lca;
}

int main(){
    vector<ll> primes = sieve(MXSIEVE); // 95 primes
    // for (auto p : primes) cout << p << " "; cout << endl;
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
    // } cout << endl;

    vector<ll> val(n+1, 1);
    vector<ll> mxfact(n+1, 0); // index of primes
    int npths = db.size();
    for (int i = 0; i < db.size(); i++){
        int lca = 1;
        for (int j = 0; j < i; j++){
            lca = max(lca, getlca(db[i].second, db[j].second));
        }

        // cout << "lca of path " << i+1 << ": " << lca << endl;

        int pi = 0;
        while (val[lca] % primes[pi] == 0){
            pi++;
        }

        // cout << "prime: " << primes[pi] << endl;
        int j = 0;
        while (db[i].second[j] != lca) j++;
        
        for (j++; j < db[i].second.size(); j++){
            int u = db[i].second[j];
            val[u] *= val[parent[u]] * primes[pi];
            // cout << "node " << u << ": " << val[u] << endl; 
        }
        // cout << endl;
    }

    for (int i = 1; i <= n; i++){
        assert(val[i] <= (ll)1e18);
        cout << val[i] << " ";
    } 
    cout << endl;
    
    return 0;
}
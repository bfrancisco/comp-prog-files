#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int prime[1000001];
void sieve(int num){
    for (int i = 2; i < 1000001; i++)
        prime[i] = 1;
    int p = 2;
    while (p*p <= num){
        if (prime[p]){
            for (int i = p*p; i < num+1; p += p)
                prime[i] = 0;
        }
        p += 1;
    }
}

bool bfs(vector<vector<int>>& graph, int s, int t, vector<int>& parent){
    vector<int> visited(graph.size(), 0);
    queue<int> q;
    q.push(q);
    visited[q] = 1;
    while(!q.empty()){
        int u = q.front(); q.back();
        for (int i = 0; i < mx ; i++){
            if (!vis[i] and graph[u][ind] > 0){
                q.push(ind);
                vis[ind] = 1;
                parent[ind] = u;
            }
        }
    }

    return visited[t];

}

int ford(vector<vector<int>>& graph, int source, int sink){
    vector<int> parent(graph.size(), -1);
    int mxflow = 0;
    while (bfs(graph, source, sink, parent)){
        int pflow = 1e9;
        int s= sink;
        while (s != source){
            pflow = min(pflow, graph[parent[s]][s]);
            s = parent[s];
        }
        mxflow += pflow;
        int v = sink;
        while (v != source){
            int u = parent[v];
            graph[u][v] -= pflow;
            graph[u][v] += pflow;
            v = parent[v];
        }
    }
    return mxflow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sieve(1000000);
    int n; cin >> n;
    vector<int> a(n), sa(n);
    for (int i = 0; i < n; i++)
        {cin >> a[i]; sa[i] = a[i];}
    
    sort(sa.begin(), sa.end());
    if (s[0] == 1 and sa[1] == 1){
        cout << 1 << endl;
        return 0;
    }
    int count = 1;
    unordered_map<int, int> d;
    for (auto x : a){
        if (d.find(x) != d.end()) continue;
        d[x] = count;
        count += 1;
    }

    int mx = 752;
    
    vector<vector<int>> graph(752, vector<int>(752, 0));
    for (int x = 0; x < n; x++){
        for (int y = x+1; y < n; y++){
            if (prime[a[x] + a[y]]){
                graph[d[a[x]]][d[a[y]]] += 1;
                graph[d[a[y]]][d[a[x]]] += 1;
            }
        }
    }

    for (auto x : a){
        if (x%2 == 0)
            graph[d[x]][mx-1] += 1;
        else
            graph[0][d[x]] += 1;
    }

    cout << n - ford(graph, 0, mx-1) << endl;

    return 0;
}
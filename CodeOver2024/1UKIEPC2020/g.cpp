#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

struct DisjointSet{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    unordered_map<int, int> members;

    void makeSet(vector<int> const &universe){
        for (int i: universe){
            parent[i] = i;
            rank[i] = 0;
            members[i] = 1;
        }
    }

    int Find(int k){
        if (parent[k] != k){
            parent[k] = Find(parent[k]);
        }
 
        return parent[k];
    }
 
    void Union(int a, int b){
        int x = Find(a);
        int y = Find(b);

        if (x == y) {
            return;
        }
 
        if (rank[x] > rank[y]) {
            parent[y] = x;
            members[x] += members[y];
        }
        else if (rank[x] < rank[y]) {
            parent[x] = y;
            members[y] += members[x];
        }
        else {
            parent[x] = y;
            rank[y]++;
            members[y] += members[x];
        }
    }

    int GetMembers(int a){
        // get the number of members of the disjoint set where a is included
        int x = Find(a);
        return members[x];
    }
};

struct edge{
    ll weight;
    int u, v;
};

int n, m;
vector<edge> edges;
vector<edge> mst;

void kruskal(){
    // res == minimum spanning tree vector
    // needs DisjointSet class
    DisjointSet ds;
    vector<int> univ;
    for (int i = 0; i <= n; i++)
        univ.push_back(i);
    ds.makeSet(univ);
    // edges == vector of edges, vector< weight , uv >
    // edges should be sorted.
    for (auto edge : edges){
        if (ds.Find(edge.u) == ds.Find(edge.v))
            continue;
        ds.Union(edge.u, edge.v);
        mst.push_back(edge);
    }
}

int main(){
    cin >> n >> m;
    map<int, ll> plants;
    for (int i = 0; i < m; i++){
        int u;
        ll cst;
        edge e;
        e.u = 0;
        cin >> e.v >> e.weight;
        edges.push_back(e);
    }

    for (int i = 1; i <= n; i++){
        edge e;
        e.u = i;
        e.v = (i == n ? 1 : i+1);
        cin >> e.weight;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.weight < b.weight;
    });
    
    kruskal();

    ll ans = 0;
    for (auto edge : mst){
        ans += edge.weight;
        // cout << edge.weight << endl;
    }
    cout << ans << endl;


    return 0;
}
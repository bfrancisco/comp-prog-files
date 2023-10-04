#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// https://www.techiedelight.com/disjoint-set-data-structure-union-find-algorithm/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m, k;
vector<int> x;
vector<pair<ll, pair<int, int>>> edges;
ll last;
unordered_set<int> hset;

class DisjointSet
{
    unordered_map<int, int> parent;
 
    // stores the depth of trees
    unordered_map<int, int> rank;

    // store number of members in a disjoint set
    unordered_map<int, int> members;

    // problem specific
    unordered_map<int, int> xmems;
 
public:
    // perform MakeSet operation
    void makeSet(vector<int> const &universe)
    {
        // create `n` disjoint sets (one for each item)
        for (int i: universe)
        {
            parent[i] = i;
            rank[i] = 0;
            members[i] = 1;
            if (hset.find(i) != hset.end())
                xmems[i] = 1;
            else
                xmems[i] = 0;
        }
    }
 
    // Find the root of the set in which element `k` belongs
    int Find(int k)
    {
        // if `k` is not the root
        if (parent[k] != k)
        {
            // path compression
            parent[k] = Find(parent[k]);
        }
 
        return parent[k];
    }
 
    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find the root of the sets in which elements `x` and `y` belongs
        int x = Find(a);
        int y = Find(b);
 
        // if `x` and `y` are present in the same set
        if (x == y) {
            return;
        }

        // Always attach a smaller depth tree under the root of the deeper tree.
        if (rank[x] > rank[y]) {
            parent[y] = x;
            members[x] += members[y];
            xmems[x] += xmems[y];
        }
        else if (rank[x] < rank[y]) {
            parent[x] = y;
            members[y] += members[x];
            xmems[y] += xmems[x];
        }
        else {
            parent[x] = y;
            rank[y]++;
            members[y] += members[x];
            xmems[y] += xmems[x];
        }
    }

    int GetMembers(int a)
    {
        // get the number of members of the disjoint set where a is included
        int x = Find(a);
        return members[x];
    }

    bool hasCycle(int u, int v){
        int x = Find(u), y = Find(v);
        if (x == y)
            return true;
        return false;
    }

    int GetX(int a){
        int x = Find(a);
        return xmems[x];
    }
};

ll kruskal(){
    DisjointSet ds;
    vector<int> univ;
    for (int i = 1; i <= n; i++)
        univ.push_back(i);
    for (auto kx : x)
        hset.insert(kx);
    ds.makeSet(univ);
    
    for (auto &[w, uv] : edges){
        int u = uv.first, v = uv.second;
        if (ds.hasCycle(u, v))
            continue;
        int up = ds.Find(u), vp = ds.Find(v);
        ds.Union(u, v);
        int newup = ds.Find(u), newvp = ds.Find(v);
        last = w;

        if (ds.GetX(u) == k)
            break;
    }
    return last;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++){
        int xtemp; cin >> xtemp;
        x.push_back(xtemp);
    }
    for (int i = 0; i < m; i++){
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());

    kruskal();

    while (k--) cout << last << " ";
    return 0;
}
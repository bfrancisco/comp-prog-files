#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// https://www.techiedelight.com/disjoint-set-data-structure-union-find-algorithm/
 
int n;
 
class DisjointSet
{
    unordered_map<int, int> parent;
 
    // stores the depth of trees
    // unordered_map<int, int> rank;
 
    // store number of members in a disjoint set
    unordered_map<int, ll> members;
 
public:
    // perform MakeSet operation
    void makeSet(vector<int> const &universe)
    {
        // create `n` disjoint sets (one for each item)
        for (int i: universe)
        {
            parent[i] = i;
            // rank[i] = 0;
            members[i] = 1;
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
        if (x == y) return;
        parent[x] = y;
        members[y] += members[x];
    }
 
    ll GetMembers(int a)
    {
        // get the number of members of the disjoint set where a is included
        int x = Find(a);
        return members[x];
    }
};
 
void printSets(vector<int> const &universe, DisjointSet &ds)
{
    for (int i: universe) {
        cout << ds.Find(i) << ' ';
    }
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    vector<int> univ;
    for (int i = 1; i <= n; i++) univ.push_back(i);
    DisjointSet ds;
    ds.makeSet(univ);
    set<pair<ll, pair<int, int>>> edges;
    ll ans = 0;
    for (int i = 0; i < n-1; i++){
        int u, v; 
        ll w;
        cin >> u >> v >> w;
 
        edges.insert({w, {u, v}});
    }
 
    for (auto ele : edges){
        int u, v;
        ll w;
        w = ele.first; u = ele.second.first; v = ele.second.second;
        
        ans += ds.GetMembers(u) * ds.GetMembers(v) * w;
        ds.Union(u, v);
    }
    cout << ans;
    return 0;
}
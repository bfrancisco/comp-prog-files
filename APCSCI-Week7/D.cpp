#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// https://www.techiedelight.com/disjoint-set-data-structure-union-find-algorithm/
 
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int n;
 
class DisjointSet
{
    unordered_map<int, int> parent;
 
    // stores the depth of trees
    unordered_map<int, int> rank;
 
    // store number of members in a disjoint set
    unordered_map<int, int> members;
 
    // weight of groups
    unordered_map<int, int> weight;
 
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
            weight[i] = 0;
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
    void Union(int a, int b, int w)
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
            weight[x] = max(weight[x], w);
        }
        else if (rank[x] < rank[y]) {
            parent[x] = y;
            members[y] += members[x];
            weight[y] = max(weight[y], w);
        }
        else {
            parent[x] = y;
            rank[y]++;
            members[y] += members[x];
            weight[y] = max(weight[y], w);
        }
    }
 
    int GetMembers(int a)
    {
        // get the number of members of the disjoint set where a is included
        int x = Find(a);
        return members[x];
    }
 
    int getWeight(int a){
        // get weight of group
        int x = Find(a);
        return weight[x];
    }
    
    bool Same(int x, int y){
        // check if x and y have the same root node
        return (Find(x) == Find(y));
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
    ll ans = 0;
    for (int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        int mems;
        if (ds.Same(u, v)) continue;
 
        ds.Union(u, v, w);
        mems = ds.GetMembers(u) - 1;
        ans += mems * ds.getWeight(u);
    }
    cout << ans;
    
 
    
    return 0;
}
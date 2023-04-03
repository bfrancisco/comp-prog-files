// https://www.techiedelight.com/disjoint-set-data-structure-union-find-algorithm/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class DisjointSet
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    unordered_map<int, int> members;
 
public:
    void makeSet(vector<int> const &universe)
    {
        for (int i: universe)
        {
            parent[i] = i;
            rank[i] = 0;
            members[i] = 1;
        }
    }

    int Find(int k)
    {
        if (parent[k] != k)
        {
            parent[k] = Find(parent[k]);
        }
 
        return parent[k];
    }
 
    void Union(int a, int b)
    {
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

    int GetMembers(int a)
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
 
// Disjoint–Set data structure (Union–Find algorithm)
int main()
{
    // universe of items
    vector<int> universe = { 1, 2, 3, 4, 5};
 
    // initialize `DisjointSet` class
    DisjointSet ds;
 
    // create a singleton set for each element of the universe
    ds.makeSet(universe);
    printSets(universe, ds);
 
    ds.Union(4, 3);        // 4 and 3 are in the same set
    printSets(universe, ds);
 
    ds.Union(2, 1);        // 1 and 2 are in the same set
    printSets(universe, ds);
 
    ds.Union(1, 3);        // 1, 2, 3, 4 are in the same set
    printSets(universe, ds);
 
    return 0;
}
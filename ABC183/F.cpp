#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int student_class[200001];

class DisjointSet
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    unordered_map<int, unordered_map<int, int>> clasize;
    // student : <class : occurence> 

 
public:
    void makeSet()
    {
        for (int i = 1; i <= 200000; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            clasize[i][student_class[i]] = 1;
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
            Transfer(y, x);
        }
        else if (rank[x] < rank[y]) {
            parent[x] = y;
            Transfer(x, y);
        }
        else {
            parent[x] = y;
            rank[y]++;
            Transfer(x, y);
        }
    }

    void Transfer(int a, int b)
    {
        // transfer from a to b
        for (auto co : clasize[a]){
            if (clasize[b].find(co.first) != clasize[b].end()){
                clasize[b][co.first] += co.second;
            }
            else{
                clasize[b][co.first] = co.second;
            }
        }
    }

    int GetClassSize(int a, int clas){
        int x = Find(a);
        if (clasize[x].find(clas) != clasize[x].end()){
            return clasize[x][clas];
        }
        return 0;
    }

    
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q; cin >> n >> q;
    
    for (int i = 1; i <= n; i++)
        cin >> student_class[i];

    DisjointSet ds;
    ds.makeSet();

    while (q--){
        int mode; cin >> mode;

        if (mode == 1){
            int a, b; cin >> a >> b;
            ds.Union(a, b);
        }
        else{
            int x, y; cin >> x >> y;
            cout << ds.GetClassSize(x, y) << endl;
        }
    }

    return 0;
}
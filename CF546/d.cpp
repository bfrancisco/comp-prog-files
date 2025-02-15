#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<set<int>> adj(n+1);
    for (int i = 0; i < m; i++){
        int v, u; cin >> v >> u;
        adj[u].insert(v);
    }

    if (n==1) {cout << 0 << endl; return 0;}

    int back = p[n-1];
    int ans = 0;
    int i = n-2;
    while (i >= 0){
        if (adj[back].find(p[i]) != adj[back].end()) ans++;
        else break;
        i--;
    }

    int child = p[i];
    i--;
    while (i >= 0){
        if (adj[back].find(p[i]) != adj[back].end() && 
            adj[child].find(p[i]) != adj[child].end()){
                ans++;
            }
        else{
            break;
        }
        i--;
    }

    cout << ans << endl;


    return 0;
}
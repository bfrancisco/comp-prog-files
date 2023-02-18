#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

unordered_map<string, ll> cost;
unordered_map<string, unordered_map<string, ll>> req;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, r, q; 
    cin >> n >> r >> q;

    for (int i = 0; i < n; i++){
        string s; ll c;
        cin >> s >> c;
        cost[s] = c;
    }

    for (int i = 0; i < r; i++){
        string v, u; ll c;
        cin >> v >> u >> c;
        req[v][u] = c;
        

    }



    return 0;
}
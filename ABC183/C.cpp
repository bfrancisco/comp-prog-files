#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n; ll k;
int ans = 0;
ll grid[8][8];

void rb(int u, int s, ll val, set<int> bank){
    if (s == n){
        val += grid[u][0];
        if (val == k) ans++;
        return;
    }

    for (int v = 1; v < n; v++){
        if (bank.find(v) != bank.end()) continue;
        bank.insert(v);
        rb(v, s+1, val + grid[u][v], bank);
        bank.erase(v);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    set<int> b = {0};
    rb(0, 1, 0, b);
    
    cout << ans;
    return 0;
}
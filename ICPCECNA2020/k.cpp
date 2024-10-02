#include<bits/stdc++.h>
using namespace std;

const int MXN = 5000;
const int MXM = 20;

int n, m;
int dp[MXN+10][MXM+10];

int rec(int limit, int pallet){
    if (pallet == 1 || limit <= 1){
        return limit;
    }
    if (dp[limit][pallet] != -1) return dp[limit][pallet];

    dp[limit][pallet] = 1e9;
    for (int i = 0; i <= limit; i++){
        int enemy = max(rec(i, pallet-1), rec(limit-i-1, pallet)) + 1;
        dp[limit][pallet] = min(dp[limit][pallet], enemy);
    }

    return dp[limit][pallet];
}

int main(){

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    
    if (m == 1) {cout << n << " " << 1 << endl; return 0;}
    if (n == 1) {cout << "1 1" << endl; return 0;}

    int mn = 1e9;
    vector<int> first(n+1);
    for (int i = 0; i <= n; i++){
        int mx_expe = max(rec(i, m-1), rec(n-i-1, m)) + 1;
        first[i] = mx_expe;
        mn = min(mn, mx_expe);
        
    }
    int l = -1, r = -1;
    for (int i = 0; i <= n; i++){
        if (mn == first[i]){
            if (l == -1) l = i+1;
            else r = i+1;
        }
    }

    cout << mn << " " << l;
    if (l < r) cout << "-" << r;
    cout << endl;
    

    return 0;
}
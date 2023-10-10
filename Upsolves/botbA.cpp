#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll m = 1e9 + 7;
ll dp[100001][10];


ll mod(ll x){
    return (x%m + m) % m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t; 

    for (int i = 0; i < 10; i++) dp[1][i] = 1;

    for (int x = 2; x <= 100000; x++){
        for (int i = 0; i < 10; i++){
            for (int j = 9; j; j--){
                dp[x][i] += dp[x-1][j];
            }
        }
    }

    for (int x = 2; x <= 100000; x++){
        for (int i = 0; i < 10; i++){
            for (int j = )
        }
    }

    while (t--){
        int n; cin >> n;
        cout << dp[n][9] - dp[n-1][9] << endl;
    }

      
    return 0;
}
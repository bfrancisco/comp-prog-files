#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H, n; cin >> H >> n;

    int a[1001], b[1001];

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int dp[10001];
    for (int i = 0; i <= H; i++){
        dp[i] = 100000000;
    }
    dp[H] = 0;

    for (int h = H; h > 0; h--){
        for (int i = 0; i < n; i++){
            int ind = h - a[i];
            if (ind < 0) ind = 0;

            dp[ind] = min(dp[h] + b[i], dp[ind]);
        }
    }
    cout << dp[0];


    
    return 0;
}   
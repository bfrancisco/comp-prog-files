#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    ll a[100010];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll dp[100010];
    for (int i = 0; i < n; i++)
        dp[i] = 1e13;
    dp[0] = 0;
    for (int i = 1; i < n; i++){
        for (int j = i-k; j < i; j++){
            if (j < 0) continue;
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }
        
    cout << dp[n-1];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> a(n+105), dp(n+105, 1e9);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[101] = 0;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= k; j++){
            dp[i+100] = min(dp[i+100], 
                        dp[i+100-j] + abs(a[i] - a[i-j]));
        }
    }

    // for (int i = 101; i <= 100+n; i++) cout << dp[i] << " "; cout << endl;

    cout << dp[n+100] << endl;


    return 0;
}
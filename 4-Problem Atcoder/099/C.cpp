#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;

    vector<int> dp(n+1, 1000000000);
    dp[0] = 0;
    int c;
    for (int i = 1; i <= n; i++){
        c = 1;
        while (c <= i){
            dp[i] = min(dp[i], dp[i-c] + 1);
            c *= 6;
        }
        c = 1;
        while (c <= i){
            dp[i] = min(dp[i], dp[i-c] + 1);
            c *= 9;
        }
    }
    cout << dp[n];
    return 0;
}
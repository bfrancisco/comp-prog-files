#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n), dp(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0] = 0;
    dp[1] = abs(a[0]-a[1]);
    for (int i = 2; i < n; i++){
        dp[i] = min(dp[i-1] + abs(a[i]-a[i-1]),
                    dp[i-2] + abs(a[i]-a[i-2]));
    }

    cout << dp[n-1] << endl;


    return 0;
}
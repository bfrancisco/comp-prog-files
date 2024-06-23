#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, K;
vector<ll> h;
ll dp[310][310][310];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    h.resize(N+1);
    for (int i = 1; i <= N; i++) cin >> h[i];

    for (int j = 0; j <= N; j++)
    for (int k = 0; k <= K; k++)
        dp[0][k][j] = h[j];
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++){
        for (int k = 0; k <= K; k++){
            for (int j = 0; j < i; j++){
                dp[i][k][j] = min(
                                (k ? dp[i-1][k-1][j] : (ll)1e11),
                                dp[i-1][k][i] + max(0ll, h[j]-h[i])
                                );
            }
        }
    }

    ll ans = 1e11;
    for (int k = 0; k <= K; k++)
    for (int j = 0; j <= N; j++){
        ans = min(ans, dp[N][k][j]);
        cout << dp[N][k][j] << endl;
    }

    cout << ans << endl;
    
    return 0;
}
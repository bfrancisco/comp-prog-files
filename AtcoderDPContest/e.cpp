#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[2][100001];
int N;
ll W;
const ll INF = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> W;
    for (int i = 0; i <= N*1000; i++){
        dp[0][i] = INF;
        dp[1][i] = INF;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++){
        ll w; int vi;
        cin >> w >> vi;
        for (int v = 0; v <= N*1000; v++){
            dp[i%2][v] = min(dp[(i-1+2)%2][v], (v-vi >= 0 ? dp[(i-1+2)%2][v-vi] + w : INF));
        }
    }

    for (int v = N*1000; v >= 0; v--){
        if (dp[N%2][v] <= W){
            cout << v << endl;
            break;
        }
    }

    return 0;
}
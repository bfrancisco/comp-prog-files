#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[2][100001];
int N, W;

int mod(int v, int m){
    return (v+m)%m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> W;
    for (int i = 1; i <= N; i++){
        int wi;
        ll v;
        cin >> wi >> v;
        for (int w = 1; w <= W; w++){
            dp[mod(i, 2)][w] = max(dp[mod(i-1, 2)][w], (w-wi >= 0 ? dp[mod(i-1, 2)][w-wi] + v : 0));
        }
    }

    cout << dp[mod(N, 2)][W];

    return 0;
}
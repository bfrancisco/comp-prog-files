#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, T;
vector<pair<int, int>> A;
vector<vector<int>> dp;

int rec(int i, int t){
    if (t <= 0 || i >= N) return 0;
    else if (dp[i][t] != -1) return dp[i][t];
    
    dp[i][t] = max(rec(i+1, t), A[i].second + rec(i+1, t-A[i].first));
    return dp[i][t];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> T;
    A.resize(N);
    for (int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        A[i] = {a, b};
    }

    sort(A.begin(), A.end());
    
    dp.assign(N, vector<int>(T+1, -1));

    cout << rec(0, T) << endl;
    
    return 0;
}
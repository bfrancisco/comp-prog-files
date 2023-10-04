#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[101][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {cin >> a[i]; mx += a[i];}
    sort(a.begin(), a.end());
    
    for (int j = 1; j <= mx; j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= mx; j++){
            if (j < a[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] += dp[i-1][j] + dp[i-1][j-a[i-1]];
        }
    }

    vector<int> flatt(mx+1, 0);
    for (int j = 0; j <= mx; j++){
        for (int i = n; i >= 0; i--){
            if (dp[i][j] > 0){
                flatt[j] = 1;
                break;
            }
        }
    }

    int mid = (mx + 2 - 1) / 2;
    while (flatt[mid] == 0){
        mid++;
    }
    cout << mid << endl;
    return 0;
}
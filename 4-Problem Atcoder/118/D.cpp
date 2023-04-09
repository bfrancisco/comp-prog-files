#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int d[] = {-1000, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> a(m);
    vector<int> dp(n+1);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i <= n; i++)
        dp[i] = -1000;
    dp[0] = 0;

    sort(a.begin(), a.end(), greater<int>());

    // dp[i] = max len(digits), i == matchsticks count
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < m; j++){
            // index in bound, already existing count, get max
            if (i-d[a[j]] >= 0 && dp[i-d[a[j]]] >= 0 && dp[i-d[a[j]]] + 1 > dp[i])
                dp[i] = dp[i-d[a[j]]] + 1;
        }
    }

    // for (int i = 2; i <= n; i++)
    //     cout << i << ": " << dp[i] << endl;

    // baktrak
    int val = n;
    vector<int> ans;
    while (val > 0){
        for (int j = 0; j < m; j++){
            if (dp[val - d[a[j]]] + 1 == dp[val] && val - d[a[j]] >= 0){
                ans.push_back(a[j]);
                val -= d[a[j]];
                // cout << val << " " << a[j] << " " << d[a[j]] << endl;
                break;
            }
        }
    }

    for (auto x : ans) cout << x;
    cout << endl;


    return 0;
}
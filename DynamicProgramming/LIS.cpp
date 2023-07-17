#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/lecture-16-dynamic-programming-part-2-lcs-lis-coins/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n);
    dp[n-1] = 1;
    for (int i = n-1; i >= 0; i--){
        for (int j = i+1; j < n; j++)
            if (a[i] < a[j])
                dp[i] = max(dp[i], 1 + dp[j]);
    }
    
    int mx = -1;
    for (auto x : dp) mx = max(mx, x);

    vector<int> LIS;
    for (int i = 0, count = mx; i < n && count > 0; i++){
        if (dp[i] == count){
            count--;
            LIS.push_back(a[i]);
        }
    }

    for (auto val : LIS) cout << val << " ";
    cout << endl;
    
    return 0;
}
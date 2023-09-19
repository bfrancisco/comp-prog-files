// https://codeforces.com/gym/101853/problem/E
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int mat[16][16];
int dp[16][1<<16];

int solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    // O(n*2^n)
    vector<int> goodbits;
    for (int i = 0; i < 1<<n; i++){
        int good = 1;
        for (int j = 0; j < n; j++){
            if (i&(1<<j) && i&(1<<(j+1))) {good = 0; break;}
        }
        if (good) goodbits.push_back(i);
    }

    // (a^2*n) where a = sizeof goodbits
    vector<vector<int>> bestbits(goodbits.size());
    for (int i = 0; i < goodbits.size(); i++){
        for (auto prevbit : goodbits){
            int good = 1;
            for (int j = 0; j < n; j++){
                if (goodbits[i] & (1 << j) &&
                    (prevbit & (1 << j) || 
                    prevbit & (1 << (j+1)) || 
                    (j != 0 && prevbit & (1 << (j-1))))){
                        good = 0;
                        break;
                }
            }
            if (good) bestbits[i].push_back(prevbit);
        }
    }

    // O(n^2*a)
    vector<unordered_map<int, int>> valmat(n);
    for (int i = 0; i < n; i++){
        for (int b = 0; b < goodbits.size(); b++){
            int val = 0;
            for (int j = 0; j < n; j++){
                if (goodbits[b] & (1 << j))
                    val += mat[i][n-j-1];
            }
            valmat[i][goodbits[b]] = val;
        }
    }
    memset(dp, 0, sizeof dp);

    for (int b = 0; b < goodbits.size(); b++){
        dp[0][goodbits[b]] = valmat[0][goodbits[b]];
    }

    // O(n*a*b) where b is sizeof bestbits(a)
    for (int i = 1; i < n; i++){
        for (int b = 0; b < goodbits.size(); b++){
            for (auto c : bestbits[b]){
                dp[i][goodbits[b]] = max(dp[i][goodbits[b]], dp[i-1][c] + valmat[i][goodbits[b]]);
            }
        }
    }

    int ans = -1;
    for (int bit : goodbits){
        ans = max(ans, dp[n-1][bit]);
    }

    cout << goodbits.size() << endl;
    return ans;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h, w;
ll MOD = 1000000007;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> h >> w;
    vector<vector<ll>> ans(h+1, vector<ll>(w+1, 0));

    for (int i = 0; i < h; i++){
        string s;
        cin >> s;
        for (int j = 0; j < w; j++){
            if (s[j] == '#')
                ans[i+1][j+1] = -1;
        }
    }

    ans[1][1] = 1;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            if ((i == 1 && j == 1) || ans[i][j] == -1 || (ans[i-1][j] == -1 && ans[i][j-1] == -1))
                continue;
            else if (ans[i-1][j] == -1)
                ans[i][j] = ans[i][j-1] % MOD; 
            else if (ans[i][j-1] == -1)
                ans[i][j] = ans[i-1][j] % MOD;
            else
                ans[i][j] = (ans[i-1][j] + ans[i][j-1]) % MOD;
        }
    }

    cout << ans[h][w];

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, c;
    cin >> n >> c;
    int D[31][31];
    int C[501][501];

    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= c; j++)
            cin >> D[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> C[i][j];

    vector<vector<int>> A(3, vector<int>(31, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            A[(i+j)%3][C[i][j]]++;
        }
    }

    int ans = 1e9;
    for (int i = 1; i <= c; i++){
        for (int j = 1; j <= c; j++){
            if (i == j) continue;
            for (int k = 1; k <= c; k++){
                if (i == k || j == k) continue;
                int temp = 0;
                for (int l = 1; l <= c; l++){
                    temp += A[0][l] * D[l][i];
                }
                for (int l = 1; l <= c; l++){
                    temp += A[1][l] * D[l][j];
                }
                for (int l = 1; l <= c; l++){
                    temp += A[2][l] * D[l][k];
                }
                // cout << i << " " << j << " " << k << " " << temp << endl;
                ans = min(ans, temp);
            }
        }
    }

    cout << ans;
    return 0;
}
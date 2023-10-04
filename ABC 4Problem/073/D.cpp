#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N, M, R;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> R;
    vector<int> r(R);
    vector<vector<int>> mat(N+1, vector<int>(N+1, 1e9));

    for (int i = 0; i < R; i++)
        cin >> r[i];
    
    for (int i = 1; i <= N; i++)
        mat[i][i] = 0;

    for (int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
        mat[v][u] = w;        
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];

    sort(r.begin(), r.end());
    int ans = 1e9;
    // cout << endl;
    do{
        // for (int x : r) cout << x << " ";
        // cout << endl;

        int cost = 0;
        for (int i = 0; i < R-1; i++){
            cost += mat[r[i]][r[i+1]];
        }
        ans = min(cost, ans);

    }while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;

    return 0;
}
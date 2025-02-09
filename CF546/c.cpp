#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid1(n, vector<int>(m)), grid2(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid1[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid2[i][j];
        }
    }

    for (int R = 0; R < n; R++){
        int r = R, c = 0;
        vector<int> A, B;
        while (r >= 0 && c < m){
            // cout << r << " " << c << endl;
            A.push_back(grid1[r][c]);
            B.push_back(grid2[r][c]);
            r -= 1;
            c += 1;
        }
        // cout << endl;
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if (A != B){
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int C = 1; C < m; C++){
        int r = n-1, c = C;
        vector<int> A, B;
        while (r >= 0 && c < m){
            // cout << r << " " << c << endl;
            A.push_back(grid1[r][c]);
            B.push_back(grid2[r][c]);
            r -= 1;
            c += 1;
        }
        // cout << endl;

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if (A != B){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
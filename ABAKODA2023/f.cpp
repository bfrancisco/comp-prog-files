#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<char>> up(n-1, vector<char>(n-1, '-')), down(n-1, vector<char>(n-1, '-'));
    vector<vector<char>> upr(n-1, vector<char>(n-1, '-')), downr(n-1, vector<char>(n-1, '-'));
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j <= i; j++){
            cin >> up[i][j];
        }
    }
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1-i; j++){
            cin >> down[i][j];
        }
    }
    for (int i = 0; i < n-1; i++){
        for (int j = n-2-i, k = 0; j < n-1; j++, k++){
            upr[i][j] = up[i][k];
        }        
    }
    for (int i = 0; i < n-1; i++){
        for (int j = i, k = 0; j < n-1; j++, k++){
            downr[i][j] = down[i][k];
        }     
    }
    
    //debug
    // for (auto v : up){
    //     for (auto c : v) cout << c << " "; cout << endl;
    // }
    // for (auto v : down){
    //     for (auto c : v) cout << c << " "; cout << endl;
    // }
    for (auto v : upr){
        for (auto c : v) cout << c << " "; cout << endl;
    }
    for (auto v : downr){
        for (auto c : v) cout << c << " "; cout << endl;
    }

    // needles[i-th needle][0 - cw, 1 - ccw][0 - up, 1 - down][j-th char, distance from the needle] 
    vector<vector<vector<vector<char>>>> needles(n, vector<vector<vector<char>>>(2, vector<vector<char>>(2, vector<char>(n-1, '-'))));
    
    // process cw up
    for (int ni = 0; ni < n-1; ni++){
        for (int ri = 0; ri < n-1; ri++){
            needles[ni][0][0][n-2-ri] = up[ri][ni];
        }
    }
    // process ccw down
    for (int ni = 0; ni < n-1; ni++){
        for (int ri = 0; ri < n-1; ri++){
            needles[ni][1][1][ri] = down[ri][ni];
        }
    }
    // process cw down
    for (int ni = n-1; ni > 0; ni--){
        for (int ri = n-2; ri >= 0; ri--){
            needles[ni][0][1][ri] = downr[ri][ni-1];
        }
    }


    // debug
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j++){
            cout << needles[i][0][1][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
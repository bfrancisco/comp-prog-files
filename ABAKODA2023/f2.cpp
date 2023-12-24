#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<char>> up;
vector<vector<char>> down;
vector<vector<vector<char>>> needles;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    up.assign(n-1, vector<char>(n-1, '-'));
    down.assign(n-1, vector<char>(n-1, '-'));

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
    
    //debug
    // for (auto v : up){
    //     for (auto c : v) cout << c << " "; cout << endl;
    // } cout << endl;
    // for (auto v : down){
    //     for (auto c : v) cout << c << " "; cout << endl;
    // } cout << endl;

    // needles[i-th needle][0 - cw, 1 - ccw][j-th char, distance from the needle]
    needles.assign(n, vector<vector<char>>(2, vector<char>(n-1, '-')));
    
    // process cw up
    for (int ni = 0; ni < n-1; ni++){
        for (int ri = 0; ri < n-1; ri++){
            needles[ni][0][n-2-ri] = up[ri][ni];
        }
    }
    // process ccw down
    for (int ni = 0; ni < n-1; ni++){
        for (int ri = 0; ri < n-1; ri++){
            needles[ni][1][ri] = down[ri][ni];
        }
    }

    // debug
    // for (int k = 0; k < 2; k++){
    //     for (int i = 0; i < n; i++){
    //         for (int j = 0; j < n-1; j++){
    //             cout << needles[i][k][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // } cout << endl;

    while (m--){
        string s; cin >> s;
        vector<int> needi(2);
        int dir = 1; // ccw default
        for (int i = 0, ni = 0; i < n; i++){
            if (s[i] != '|'){
                needi[ni] = i;
                if (ni == 0 && s[i] == '/')
                    dir = 0;
                ni++;
            }
        }
        int dst = needi[1] - needi[0];
        cout << needles[needi[0]][dir][dst-1];
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> grid;
int N = 8;
int ans = 0;

void rec(int q, unordered_set<int>& queens){
    if (queens.size() == N){

        // check diags
        for (int R = N-1, C = 0; R >= 0; R--){
            int qs = 0;
            for (int r = R, c = C; r >= 0; r--, c++){
                if (grid[r][c] == 'Q'){
                    qs++;
                }
            }
            if (qs > 1) {return;}
        }

        for (int R = N-1, C = 0; C < N; C++){
            int qs = 0;
            for (int r = R, c = C; c < N; r--, c++){
                if (grid[r][c] == 'Q'){
                    qs++;
                }
            }
            if (qs > 1) {return;}
        }

        for (int R = 0, C = 0; R < N; R++){
            int qs = 0;
            for (int r = R, c = C; r < N; r++, c++){
                if (grid[r][c] == 'Q'){
                    qs++;
                }
            }
            if (qs > 1) {return;}
        }

        for (int R = 0, C = 0; C < N; C++){
            int qs = 0;
            for (int r = R, c = C; r < N; r++, c++){
                if (grid[r][c] == 'Q'){
                    qs++;
                }
            }
            if (qs > 1) {return;}
        }

        
        // cout << endl;
        // for (int i = 0; i < N; i++){
        //     cout << grid[i] << endl;
        // }
        ans++;

        return;
    }

    for (int i = 0; i < N; i++){
        if (queens.find(i) != queens.end()) continue;
        if (grid[queens.size()][i] == '*') continue;
        queens.insert(i);
        grid[queens.size() - 1][i] = 'Q';
        rec(q+1, queens);
        grid[queens.size() - 1][i] = '.';
        queens.erase(i);
    }
    return;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    grid.resize(N);
    for (int i = 0; i < N; i++){
        cin >> grid[i];
    }

    unordered_set<int> queens;
    rec(0, queens);
    cout << ans << endl;
    return 0;
}
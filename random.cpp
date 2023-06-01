#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> grid;
int N = 8;
int ans = 0;

void rec(int q, unordered_set<int>& queens){
    if (queens.size() == N){
        // check for diagonals only
        int r, c, qc;

        
        
        ans += 1;
        return;
    }

    for (int i = 0; i < 8; i++){
        if (queens.find(i) != queens.end() || grid[queens.size() - 1][i] == '*') continue;
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
    grid.resize(8);
    for (int i = 0; i < N; i++){
        cin >> grid[i];
    }

    unordered_set<int> queens;
    rec(0, queens);
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int H, W;

void swap_col(vector<vector<char>>& grid, int a, int b){
    char tmp;
    for (int i = 0; i < H; i++){
        swap(grid[i][a], grid[i][b]);
    }
}

void do_sym(vector<vector<char>>& grid, int a, int b){
    // make row a & b symmetric
    // remove row a & b from grid
}

bool rec(vector<vector<char>>& grid){
    if (grid.empty()) return true;
    
    for (int j = 1; j < W; j++){
        if (can_sym(grid[0], grid[j])){
            do_sym(grid, 0, j);
            return rec(grid);
        }
    }
    
    if (can_palindrome(grid[0])){
        // remove first row
        return rec(grid);
    }
    return false;
}

int main(){
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++) cin >> grid[i][j];
    }

    // pair up rows then combine thru col ops
    cout << (rec(grid) ? "YES" : "NO") << endl;

    return 0;
}
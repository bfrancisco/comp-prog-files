#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int H, W;
vector<vector<char>> newest;

void swap_col(vector<vector<char>>& grid, int a, int b){
    for (int i = 0; i < grid.size(); i++){
        swap(grid[i][a], grid[i][b]);
    }
}

pair<vector<vector<char>>, bool> do_sym(vector<vector<char>> grid, int a, int b){
    int h, w;
    h = grid.size();
    w = grid[0].size();

    vector<vector<char>> oldgrid(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            oldgrid[i][j] = grid[i][j];

        
    // make row a & b symmetric
    for (int i = 0; i < (int)w/2; i++){
        // cout << "  " << i << endl;
        bool has_match = false;
        if (grid[a][i] == grid[b][w-i-1]) continue;
        for (int j = i+1; j < w-i; j++){
            // cout << "    " << j << endl;
            if (grid[a][i] == grid[b][j]){
                has_match = true;
                swap_col(grid, j, w-i-1);
                break;
            }
        }
        if (!has_match) return {oldgrid, false};
    }

    // check if match
    for (int i = 0; i < w; i++){
        if (grid[a][i] != grid[b][w-i-1]) return {oldgrid, false};
    }

    // remove row a & b from grid
    vector<vector<char>> newgrid;
    for (int i = 0; i < h; i++){
        if (i == a || i == b) continue;
        newgrid.push_back(grid[i]);
    }

    return {newgrid, true};
}

bool can_palindrome(vector<char> row){
    vector<int> freq(26);
    for (auto c : row){
        if (freq[c-'a']) freq[c-'a']--;
        else freq[c-'a']++;
    }

    int balance = 0;
    for (auto f : freq) balance += f;
    if ((row.size()%2 == 0 && balance == 0) || 
        (row.size()%2 && balance == 1)) return true;
    
    return false;
}
vector<vector<char>> remove_row(vector<vector<char>> grid, int x){
    vector<vector<char>> newgrid;
    for (int i = 0; i < grid.size(); i++){
        if (i == x) continue;
        newgrid.push_back(grid[i]);
    }
    return newgrid;
}

bool rec(vector<vector<char>> grid, bool has_pal){
    if (grid.empty()) return true;
    // cout << grid.size() << " " << grid[0].size() << endl;

    bool can_sym;
    for (int i = 1; i < grid.size(); i++){
        // cout << i << endl;
        auto pp = do_sym(grid, 0, i);
        grid = pp.first;
        can_sym = pp.second;
        
        if (can_sym){
            return rec(grid, has_pal);
        }
    }
    
    if (!has_pal && grid.size()%2 && can_palindrome(grid[0])){
        grid = remove_row(grid, 0);
        return rec(grid, true);
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
    cout << (rec(grid, false) ? "YES" : "NO") << endl;

    return 0;
}
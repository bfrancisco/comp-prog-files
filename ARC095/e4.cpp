#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int H, W;
vector<vector<char>> grid;

void pr(){
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }cout << endl;
}

void swap_col(int a, int b){
    for (int i = 0; i < grid.size(); i++){
        swap(grid[i][a], grid[i][b]);
    }
}

bool check_palindrome(vector<char> row){
    vector<int> freq(26);
    for (auto c : row){
        if (freq[c-'a']) freq[c-'a']--;
        else freq[c-'a']++;
    }

    int balance = 0;
    for (auto f : freq) balance += f;
    if ((W%2 == 0 && balance == 0) || 
        (W%2 && balance == 1)) return true;
    
    return false;
}

bool can(int a, int b){
    bool swapped = false;

    vector<char> v1, v2;
    v1 = grid[a];
    v2 = grid[b];

    for (int i = 0; i < W/2; i++){
        if (v1[i] == v2[W-i-1] && v1[W-i-1] == v2[i]) continue;

        bool has_match = false;
        for (int j = i+1; j < W-i-1; j++){
            if (v1[i] == v2[j] && v1[j] == v2[i]){
                has_match = true;
                swap(v1[j], v1[W-i-1]);
                swap(v2[j], v2[W-i-1]);
                break;
            }
        }

        if (!has_match){
            if (W%2 == 0) return false;
            else if (swapped) return false;
            else{
                swap(v1[i], v1[W/2]);
                swap(v2[i], v2[W/2]);
                swapped = true;
                i--;
            }
        }
    }

    return true;
}

bool check(){
    // cout << "chek" << endl;
    for (int c1 = 0; c1 < W/2; c1++){
        bool has_match = false;
        for (int c2 = c1+1; c2 < W-c1; c2++){
            // given 2 cols, check if all pairs matches, then swap
            bool good = true;
            for (int r = 0; r < H/2; r++){
                if (grid[r][c1] != grid[H-r-1][c2] || grid[H-r-1][c1] != grid[r][c2]){
                    good = false;
                    break;
                }
            }

            if (good){
                swap_col(c2, W-c1-1);
                has_match = true;
                break;
            }
        }
        if (!has_match){
            if (W%2 == 0) return false;
            swap_col(c1, W/2);
            c1--;
        }
    }

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (grid[i][j] != grid[H-i-1][W-j-1]) return false;
        }
    }
    return true;
}


bool rec(int i, bool have_palin){
    // pr();
    if (i == H/2){
        return check();
    }
    bool res = false;
    for (int j = i+1; j < H-i; j++){
        
        if (can(i, j)){
            // cout << i << " " << j << endl;
            swap(grid[j], grid[H-i-1]);
            res = res | rec(i+1, have_palin);
            swap(grid[j], grid[H-i-1]);
        }
    }

    if (!res && !have_palin){
        if (H%2 && check_palindrome(grid[i])){
            // cout << "swap: " << i << " " << H/2 << endl;
            swap(grid[i], grid[H/2]);
            res = res | rec(i, true);
            swap(grid[i], grid[H/2]);
        }
    }

    return res;
}

int main(){
    cin >> H >> W;
    grid.resize(H, vector<char>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];

    if (H==1){
        cout << (check_palindrome(grid[0]) ? "YES" : "NO") << endl;
        return 0;
    }
    cout << (rec(0, false) ? "YES" : "NO") << endl;

    return 0;
}
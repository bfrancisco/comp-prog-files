#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int H, W;
vector<vector<char>> grid;

void swap_col(int a, int b){
    for (int i = 0; i < grid.size(); i++){
        swap(grid[i][a], grid[i][b]);
    }
}

bool alldone(bitset<12>& done){
    for (int i = 0; i < H; i++) if (done[i] == 0) return false;
    return true;
}

pair<vector<pair<int, int>>, bool> make_sym(int a, int b){
    vector<pair<int, int>> ops;

    bool swapped_to_mid = false;

    for (int i = 0; i < W/2; i++){
        if (grid[a][i] == grid[b][W-i-1] && grid[b][i] == grid[a][W-i-1]){
            // cout << "?" << endl;
            continue;
        }
        bool has_match = false;
        for (int j = i+1; j < W-i-1; j++){
            if (grid[a][i] == grid[b][j] && grid[a][j] == grid[b][i]){
                has_match = true;
                swap_col(j, W-i-1);
                ops.push_back({j, W-i-1});
                break;
            }
        }
        if (!has_match){
            if (W%2 == 0) return {ops, false};
            else if (swapped_to_mid) return {ops, false};
            else{
                swap_col(i, W/2);
                ops.push_back({i, W/2});
                swapped_to_mid = true;
                i--;
            }
        }
    }

    return {ops, true};
}

void undo_ops(int a, int b, vector<pair<int, int>> ops){
    for (auto &[l, r] : ops){
        swap_col(l, r);
    }
}

bool last_check(bool have_palin){

    if (have_palin){
        for (int i = 0; i < W/2; i++){
            if (grid[H/2][i] == grid[H/2][W-i-1]) continue;
            bool has_match = false;
            for (int j = i+1; j < W-i-1; j++){
                if (grid[H/2][j] == grid[H/2][i]){
                    has_match = true;
                    swap_col(j, W-i-1);
                }
            }
            if (!has_match) return false;
        }
    }

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (grid[i][j] != grid[H-i-1][W-j-1]) return false;
        }
    }
    return true;


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

bool rec(bitset<12> done, bool have_palin){
    if (alldone(done)){
        return last_check(have_palin);
    }
    vector<pair<int, int>> ops;
    bool possible = false;

    int first_not_done = -1;
    for (int i = 0; i < H; i++){
        if (done[i] == 0){
            first_not_done = i;
            break;
        }
    }

    done[first_not_done] = 1;

    // cout << "FIX: " <<  first_not_done << endl;
    for (int j = 0; j < H; j++){
        if (done[j]) continue;
        // cout << j << endl;
        pair<vector<pair<int, int>>, bool> res = make_sym(first_not_done, j);
        if (!res.second) continue; 
        // cout << "PAIR: " << first_not_done << " " << j << endl;
        // for (int i = 0; i < H; i++){
        //     for (int j = 0; j < W; j++) cout << grid[i][j];
        //     cout << endl;
        // } cout << endl;
        ops = res.first;
        done[H-first_not_done-1] = 1;
        swap(grid[j], grid[H-first_not_done-1]);

        possible = possible | rec(done, have_palin);

        swap(grid[j], grid[H-first_not_done-1]);
        done[H-first_not_done-1] = 0;
        undo_ops(0, j, ops);
    }

    if (!possible && !have_palin){
        if (H%2 && check_palindrome(grid[first_not_done])){
            done[H/2] = 1;
            swap(grid[first_not_done], grid[H/2]);
            possible = possible | rec(done, true);
            swap(grid[first_not_done], grid[H/2]);
            done[H/2] = 0;
        }
    }

    return possible;
}

int main(){
    cin >> H >> W;
    grid.resize(H, vector<char>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];

    bitset<12> tmp;
    cout << (rec(tmp, false) ? "YES" : "NO") << endl;

    return 0;
}
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
    for (auto b : done) if (b == 0) return false;
    return true;
}

pair<vector<char>, bool> make_sym(int a, int b){
    vector<char> v1, v2;
    v1 = grid[a];
    v2 = grid[b];
    vector<pair<int, int>> ops;

    bool swapped_to_mid = false;

    for (int i = 0; i < W/2; i++){
        if (v1[i] == v2[W-i-1] && v2[i] == v1[W-i-1]) continue;

        bool has_match = false;
        for (int j = i+1; j < W-i-1; j++){
            if (v1[i] == v2[j] && v1[j] == v2[i]){
                has_match = true;
                swap(v1[j], v1[W-i-1]);
                swap(v2[j], v2[W-i-1]);
                ops.push_back(j, W-i-1);
                break;
            }
        }
        if (!has_match){
            if (W%2 == 0) return {ops, false};
            else if (swapped_to_mid) return {ops, false};
            else{
                swap(v1[i], v1[W/2]);
                swap(v2[i], v2[W/2]);
                ops.push_back(i, W/2);
                swapped_to_mid = true;
                i--;
            }
        }
    }

    return {ops, true};
}

bool rec(bitset<12> done, bool have_palin){
    if (alldone(done)) return true;
    vector<pair<int, int>> ops;
    bool possible = false;

    for (int j = 1; j < H; j++){
        if (done[j]) continue;
        pair<vector<char>, bool> res = make_sym(0, j);
        if (!res.second) continue; 

        ops = res.first;
        done[0] = done[j] = 1;
        possible = possible | rec(done, have_palin);
        done[0] = done[j] = 0;
        undo_ops(0, j, ops);
    }

    if (!possible && !have_palin){
        if (check_palindrome()){
            done[0] = 1;
            possible = possible | rec(done, true);
            done[0] = 0;
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
    rec(tmp);
    cout << (check() ? "YES" : "NO") << endl;

    return 0;
}
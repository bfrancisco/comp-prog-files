#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 9;
vector<vector<int>> grid;

// 0 0 0  0 0 0  0 0 0
// 0 0 0  0 0 0  0 0 0
// 0 0 0  0 0 0  0 0 0

// 0 0 0  0 0 0  0 0 0
// 0 0 0  0 0 0  0 0 0
// 0 0 0  0 0 0  0 0 0

// 0 0 0  0 0 0  0 0 0
// 0 0 0  0 0 0  0 0 0
// 0 0 0  0 0 0  0 0 0

bool can_place(int R, int C, int x){
    int gud = 1;
    // col
    for (int r = 0; r < N; r++){
        if (x == grid[r][C]) {gud = 0; break;}  
    }

    // row
    for (int c = 0; c < N; c++){
        if (x == grid[R][c]) {gud = 0; break;}
    }

    // box
    int sr = R, sc = C;
    while (sr%3!=0) sr--;
    while (sc%3!=0) sc--;
    for (int r = sr; r < sr+3; r++) for (int c = sc; c < sc+3; c++){
        if (x == grid[r][c]) {gud = 0; break;}
    }

    return gud;
}

int svr(int R, int C){
    int val = 0;
    for (int x = 1; x <= N; x++){
        if (can_place(R, C, x)){
            if (val == 0) val = x;
            else {val = 0; break;}
        }
    }

    return val;
}

int ulr_row(int R){
    set<int> pos_val = {1,2,3,4,5,6,7,8,9};
    vector<int> index;
    for (int c = 0; c < N; c++){
        if (pos_val.find(grid[R][c]) != pos_val.end()){
            pos_val.erase(grid[R][c]);
        }
        if (grid[R][c] == 0){
            index.push_back(c);
        }
    }

    int toret = 0;

    for (auto val : pos_val){
        vector<int> can;
        for (auto c : index){
            if (can_place(R, c, val)){
                can.push_back(c);
            }
        }
        if ((int)can.size() == 1){
            grid[R][can[0]] = val;
            toret++;
        }
    }

    return toret;
}

int ulr_col(int C){
    set<int> pos_val = {1,2,3,4,5,6,7,8,9};
    vector<int> index;
    for (int r = 0; r < N; r++){
        if (pos_val.find(grid[r][C]) != pos_val.end()){
            pos_val.erase(grid[r][C]);
        }
        if (grid[r][C] == 0){
            index.push_back(r);
        }
    }

    int toret = 0;

    for (auto val : pos_val){
        vector<int> can;
        for (auto r : index){
            if (can_place(r, C, val)){
                can.push_back(r);
            }
        }
        if ((int)can.size() == 1){
            grid[can[0]][C] = val;
            toret++;
        }
    }

    return toret;
}

int ulr_grid(int sr, int sc){
    set<int> pos_val = {1,2,3,4,5,6,7,8,9};
    vector<pair<int, int>> index;

    for (int r = sr; r < sr + 3; r++) for (int c = sc; c < sc + 3; c++){
        if (pos_val.find(grid[r][c]) != pos_val.end()){
            pos_val.erase(grid[r][c]);
        }
        if (grid[r][c] == 0){
            index.push_back({r, c});
        }
    }

    int toret = 0;

    for (auto val : pos_val){
        vector<pair<int, int>> can;
        for (auto [r, c] : index){
            if (can_place(r, c, val)){
                can.push_back({r, c});
            }
        }
        if ((int)can.size() == 1){
            grid[can[0].first][can[0].second] = val;
            toret++;
        }
    }

    return toret;
}

bool complete(){
    for (int r = 0; r < N; r++) for (int c = 0; c < N; c++){
        if (grid[r][c] == 0) return false;
    }

    for (int r = 0; r < N; r++){
        set<int> ns = {1,2,3,4,5,6,7,8,9};
        for (int c = 0; c < N; c++){
            ns.erase(grid[r][c]);
        }
        assert(ns.empty());
    }
    for (int c = 0; c < N; c++){
        set<int> ns = {1,2,3,4,5,6,7,8,9};
        for (int r = 0; r < N; r++){
            ns.erase(grid[r][c]);
        }
        assert(ns.empty());
    }
    for (int sr = 0; sr < N; sr+=3){
        for (int sc = 0; sc < N; sc+=3){
            set<int> ns = {1,2,3,4,5,6,7,8,9};
            for (int r = sr; r < sr+3; r++) for (int c = sc; c < sc+3; c++){
                ns.erase(grid[r][c]);
            }
            assert(ns.empty());
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    grid.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    int easy = 0;
    while (true){
        int trig = 0;
        
        // svr
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++){
            if (grid[i][j] != 0) continue;
            grid[i][j] = svr(i, j);
            trig += grid[i][j];
        }

        // ulr - row
        for (int i = 0; i < N; i++){
            trig += ulr_row(i);
        }

        // ulr - col
        for (int i = 0; i < N; i++){
            trig += ulr_col(i);
        }
        
        // ulr - subgrid
        for (int i = 0; i < N; i += 3) for (int j = 0; j < N; j += 3){
            trig += ulr_grid(i, j);
        }

        if (complete()) {easy = 1; break;}
        if (trig == 0) { break; }
    }

    cout << (easy ? "Easy" : "Not easy") << endl;
    for (auto row : grid){
        for (auto v : row){
            if (v==0){
                cout << ". ";
            }
            else{
                cout << v << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
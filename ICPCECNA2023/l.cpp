#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

// NESW == 0123
int N, M;
vector<int> X, Y;
vector<vector<pair<int, int>>> db;
map<int, char> mapdir;
int dir = 0;
int min_weight = 1e9;
vector<int> path;
set<pair<int, int>> path_set;

void remove_edge(int dec){
    for (int i = 0; i < path.size()-1; i++){
        int u = path[i], v = path[i+1];
        for (int j = 0; j < 4; j++){
            if (db[u][j].first == v){
                db[u][j].second -= dec;
                db[v][(j+2)%4].second -= dec;
                assert(db[v][(j+2)%4].first == u);
                assert(db[u][j].second == db[v][(j+2)%4].second);
                if (db[u][j].second == 0){
                    db[u][j] = {-1, -1};
                    db[v][(j+2)%4] = {-1, -1};
                }
            }
        }
    }
}

void run(int u){
    // cout << u << "  ";

    vector<pair<pair<int, int>, int>> branches;
    for (int i = -1; i <= 1; i++){
        int j = ((dir+i)+4)%4;
        if (db[u][j].first != -1){
            branches.push_back({db[u][j], i});
        }
    }

    // cout << "branches: ";
    // for (auto x : branches) cout << x.first.first << " "; cout << endl;
    int vi = (branches.size() == 3 ? 1 : 0);
    if (branches.size() == 0){
        cout << X[u] << " " << Y[u] << endl;  
        return;
    }

    int v = branches[vi].first.first;
    int weight = branches[vi].first.second;
    dir += branches[vi].second;
    dir = (dir+4)%4;
    // cout << v << endl << endl;

    min_weight = min(min_weight, weight);
    if (path_set.find({v, dir}) != path_set.end()){
        remove_edge(min_weight);
        path.clear();
        path_set.clear();
        // cout << "WEIGHT " << min_weight << endl; 
        min_weight = (int)1e9;
    }
    path.push_back(v);
    path_set.insert({v, dir});

    run(v);
}

int main(){
    mapdir[0] = 'N';
    mapdir[1] = 'E';
    mapdir[2] = 'S';
    mapdir[3] = 'W';
    cin >> N >> M;
    X.resize(N+1);
    Y.resize(N+1);
    db.assign(N+1, vector<pair<int, int>>(4, pair<int, int>(-1, -1)));
    for (int i = 1; i <= N; i++){
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        assert(X[u] == X[v] || Y[u] == Y[v]);
        if (X[u] != X[v]){
            // W <-> E
            if (X[u] < X[v]){
                db[u][1] = {v, w};
                db[v][3] = {u, w};
            }
            else{
                db[u][3] = {v, w};
                db[v][1] = {u, w};
            }
        }
        else if (Y[u] != Y[v]){
            // N <-> S
            if (Y[u] < Y[v]){
                db[u][0] = {v, w};
                db[v][2] = {u, w};
            }
            else{
                db[u][2] = {v, w};
                db[v][0] = {u, w};
            }
        }
    }

    // for (int i = 1; i <= N; i++){
    //     cout << "intersection: " << i << endl;
    //     for (int k = 0; k < 4; k++){
    //         if (db[i][k].first != -1) cout << k << ": " << db[i][k].first << " " << db[i][k].second << endl;
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            assert(!(X[i] == X[j] and Y[i] == Y[j]));
        }
    }

    int start;
    char D;
    cin >> start >> D;
    if (D == 'E') dir = 1;
    else if (D == 'S') dir = 2;
    else if (D == 'W') dir = 3;

    path.push_back(start);
    path_set.insert({start, dir});
    run(start);



    return 0;
}
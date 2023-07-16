#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> grid;
int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void pr(){
    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool valid(int x1, int y1){
    return (0 <= x1 && x1 < n && 0 <= y1 && y1 < m);
}

void BFS(int si, int sj, set<pair<int,int>> &salvations){
    queue<pair<int,int>> q;
    q.push({si,sj});
    salvations.insert({si,sj});
    grid[si][sj] = 'V';

    while (!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first, j = p.second;
        // cout << "in: " << i << " " << j << endl;
        int hasSalvation = 0;

        vector<pair<int,int>> topush;
        for (int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            // cout << ni << " " << nj << endl;
            if (valid(ni, nj) && grid[ni][nj] == 'X' && salvations.find({ni, nj}) == salvations.end()) topush.push_back({ni, nj});
            if (valid(ni, nj) && grid[ni][nj] == '-') hasSalvation = 1;
        }

        // for (auto &[f, s] : topush) cout << f << " " << s << endl;
        if (!hasSalvation && !topush.empty()){
            salvations.insert(topush[topush.size()-1]);
            topush.pop_back();
        }
        while (!topush.empty()){
            grid[topush[topush.size()-1].first][topush[topush.size()-1].second] = 'V';
            q.push(topush[topush.size()-1]);
            topush.pop_back();
        }

    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'X' && salvations.find({i, j}) == salvations.end()){
                // cout << "INNER" << i << " " << j << endl;
                BFS(i, j, salvations);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < m; j++) grid[i][j] = s[j];
    }

    // BFS to get regions. # of regions is ans
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'X'){
                cout << i << " " << j << endl;
                set<pair<int,int>> salvations;
                BFS(i, j, salvations);
                ans++;
                pr();
            }
        }
    }

    cout << ans << endl;

    return 0;
}
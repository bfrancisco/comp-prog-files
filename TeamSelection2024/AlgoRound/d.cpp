#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void move(char c, int &x, int &y){
    if (c == 'N') y++;
    else if (c == 'S') y--;
    else if (c == 'E') x++;
    else if (c == 'W') x--;
}

int MX = 150;
int cnt = 70;

void solve(){
    int n; cin >> n;
    
    vector<vector<int>> up(MX, vector<int>(MX, 1));
    vector<vector<int>> dw(MX, vector<int>(MX, 1));
    vector<vector<int>> le(MX, vector<int>(MX, 1));
    vector<vector<int>> ri(MX, vector<int>(MX, 1));

    int x, y;
    x = y = cnt;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        if (c == 'N'){
            up[x][y] = 0;
            y++;
            dw[x][y] = 0;
        }
        else if (c == 'S'){
            dw[x][y] = 0;
            y--;
            up[x][y] = 0;
        }
        else if (c == 'E'){
            ri[x][y] = 0;
            x++;
            le[x][y] = 0;
        }
        else if (c == 'W'){
            le[x][y] = 0;
            x--;
            ri[x][y] = 0;
        }
    }

    int ex = x;
    int ey = y;
    // cout << ex << ' ' << ey << endl;
    x = y = cnt;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});

    while (!q.empty()){
        auto [d, coor] = q.front();
        int cx = coor.first;
        int cy = coor.second;
        q.pop();
        // cout << d << " " <<  cx << " " << cy << endl;
        if (cx == ex && cy == ey){
            cout << d << endl;
            return;
        }

        int nx, ny;
        for (auto c : "NWSE"){
            if (c == 'N' && !up[cx][cy]){
                up[cx][cy] = 1;
                nx = cx;
                ny = cy+1;
                dw[nx][ny] = 1;
                q.push({d+1, {nx, ny}});
                // cout << "   N" << endl;
            }
            else if (c == 'S' && !dw[cx][cy]){
                dw[cx][cy] = 1;
                nx = cx;
                ny = cy-1;
                up[nx][ny] = 1;
                q.push({d+1, {nx, ny}});
                // cout << "   S" << endl;

            }
            else if (c == 'E' && !ri[cx][cy]){
                ri[cx][cy] = 1;
                nx = cx+1;
                ny = cy;
                le[nx][ny] = 1;
                q.push({d+1, {nx, ny}});
                // cout << "   E" << endl;

            }
            else if (c == 'W' && !le[cx][cy]){
                le[cx][cy] = 1;
                nx = cx-1;
                ny = cy;
                ri[nx][ny] = 1;
                q.push({d+1, {nx, ny}});
                // cout << "   W" << endl;
            }
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    while (n--){
        solve();
    }


    return 0;
}
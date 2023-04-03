#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h, w;
bool valid(int a, int b){
    if (0 <= a < h && 0 <= b < w)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    char grid[50][50];
    cin >> h >> w;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }
    vector<int> x = {0, 0, 1, -1};
    vector<int> y = {-1, 1, 0, 0};
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (grid[i][j] == '.') continue;
            int c = 0;
            for (int k = 0; k < 4; k++){
                int a = i+x[k];
                int b = j+y[k];
                if (!valid(a, b)) continue;
                if (grid[a][b] == '#') c++;
            }
            if (c == 0) {cout << "No"; return 0;}
        }
    }
    cout << "Yes";
    return 0;
}
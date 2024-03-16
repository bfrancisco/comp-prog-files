#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w, r, c, c1, c2, val, side; 
    char ch;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    const int MATCH = 1+10+100+1000;
    for (r = 0; r < h; r++){
        for (c = 0; c < w; c++){
            cin >> ch;
            if (ch == 'b') grid[r][c] = 1;
            else if (ch == 'w') grid[r][c] = 10;
            else if (ch == 'r') grid[r][c] = 100;
            else if (ch == 'g') grid[r][c] = 1000;
        }
    }

    int good = 0;

    int BND = 750;
    for (r = 0; r < BND; r++){
        for (c1 = 0; c1 < BND; c1++){
            for (c2 = c1+1; c2 < BND; c2++){
                side = c2-c1;
                val = grid[r%h][c1%w] + grid[r%h][c2%w];
                val += grid[(r+side)%h][c1%w];
                val += grid[(r+side)%h][c2%w];
                if (val == MATCH) {cout << "possible"; return 0;}
            }
        }
    }

    cout << "impossible" << endl;

    return 0;
}
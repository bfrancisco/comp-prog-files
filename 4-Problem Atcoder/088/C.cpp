#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int grid[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> grid[i][j];

    int def[3] = {grid[0][0], grid[0][1], grid[0][2]};

    for (int i = 1; i < 3; i++){
        int v = grid[i][0] - def[0];
        for (int j = 1; j < 3; j++){
            if (grid[i][j] - v != def[j]){
                cout << "No"; return 0;
            }
        }
    }

    cout << "Yes";
    return 0;
}
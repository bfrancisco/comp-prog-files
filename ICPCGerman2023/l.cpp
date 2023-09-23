#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

char grid[100][100];
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int l, w, n; cin >> l >> w >> n;
    if ((l*w)%n != 0 || n > (l*w)){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int g = __gcd(l, w);
    
    int k = 0;
    for (int i = 0; i < l; i += g){
        for (int j = 0; j < w; j += g){
            // paint gxg
            for (int r = 0; r < g; r++){
                for (int c = 0; c < g; c++){
                    grid[i+r][j+c] = s[k];
                }
            }
            k++;
        }
    }

    for (int i = 0; i < l; i++){
        for (int j = 0; j < w; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
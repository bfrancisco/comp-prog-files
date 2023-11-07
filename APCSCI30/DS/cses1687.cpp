#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int l = 19;
int lift[200005][l];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    memset(lift, -1, sizeof(lift));
 
    for (int u = 2; u <= n; u++){
        cin >> lift[u][0];
    }
    
    for (int j = 1; j < l; j++){
        for (int u = 1; u <= n; u++){
            if (lift[u][j-1] == -1)
                continue;
            lift[u][j] = lift[lift[u][j-1]][j-1];
        }
    }
    
    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j < l; j++){
    //         cout << lift[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while (q--){
        int x, k; cin >> x >> k;
        int y = 0;
        while(k){
            if (k & 1){
                x = lift[x][y];
            }
            y++;
            k >>= 1;
            if (x == -1) break;
        }
        cout << x << "\n";
    }
    return 0;
}

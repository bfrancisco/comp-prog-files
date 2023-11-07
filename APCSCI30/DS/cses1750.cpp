#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int lift[200005][31];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, l;
    int q;
    cin >> n >> q;
    l = 30; // log2(1e9)
 
    for (int u = 1; u <= n; u++){
        cin >> lift[u][0];
    }
    
    for (int j = 1; j < l; j++){
        for (int u = 1; u <= n; u++){
            lift[u][j] = lift[lift[u][j-1]][j-1];
        }
    }
 
    while (q--){
        int u, steps;
        cin >> u >> steps;
        int y = 0;
        while(steps){
            if (steps & 1){
                u = lift[u][y];
            }
            y++;
            steps >>= 1;
        }
        cout << u << "\n";
    }
    return 0;
}
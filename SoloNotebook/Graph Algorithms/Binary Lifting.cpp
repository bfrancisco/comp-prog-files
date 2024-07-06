#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void binary_lift(vector<vector<int>>& lift, int n, int l){
    // generates binary lift DS.
    // lift[u][steps] - resulting node after jumping 2^steps from node u
    // lift[u][0] for any u should be pre-computed already
    // n - no. of nodes. 1-indexed
    // l - 2^(l-1) is the max no. of steps

    for (int j = 1; j < l; j++){
        for (int u = 1; u <= n; u++){
            lift[u][j] = lift[lift[u][j-1]][j-1];
        }
    }
}

int jump(int u, int steps, vector<vector<int>>& lift){
    // jumps 'steps' steps from u. returns resulting node.
    int bit = 0;
    while (steps){
        if (steps & 1){
            u = lift[u][bit];
        }
        bit++;
        steps >>= 1;
    }
    return u;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, l;
    int q;
    cin >> n >> q;
    l = 30; // log2(1e9) exclusive
    vector<vector<int>> lift(n+1, vector<int>(l));
 
    for (int u = 1; u <= n; u++){
        cin >> lift[u][0];
    }
    
    binary_lift(lift, n, l);
 
    while (q--){
        int u, steps;
        cin >> u >> steps;
        cout << jump(u, steps, lift) << "\n";
    }
    return 0;
}
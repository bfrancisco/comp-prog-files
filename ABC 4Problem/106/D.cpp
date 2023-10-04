#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, q; cin >> n >> m >> q;

    vector<int> da(n+2, 0);
    for (int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        da[l]++;
        da[r+1]--;
    }

    for (int i = 1; i <= n; i++)
        da[i] += da[i-1];
        
    

    return 0;
}
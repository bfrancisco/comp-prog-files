#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int c[31];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int f; cin >> f;
            c[f]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
        if (c[i] == n) ans++;
    
    cout << ans;

    return 0;
}
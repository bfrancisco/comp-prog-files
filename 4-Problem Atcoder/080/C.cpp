#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    ll scores[101];

    for (int i = 0; i < n; i++){
        scores[i] = 0;
        for (int j = 0; j < 10; j++){
            ll x; cin >> x;
            if (x == 1) scores[i]++;
        }
    }

    ll exclude0 = -1e9;
    ll exind = -1;
    ll all = -1e9;
    ll c = 0;
    int grid[101][11];
    for (int i = 0; i < n; i++){
        ll mx = -1e9;
        ll first; cin >> first;
        grid[i][0] = first;
        for (int j = 1; j <= 10; j++){
            ll x; cin >> x;
            if (scores[i] < j) continue;
            grid[i][j] = x;
            mx = max(mx, x);
            if ()
            exclude0 = max(exclude0, x);
        }
        
        all += max(mx, first);
        if (mx >= first) c++;
    }




    return 0;
}
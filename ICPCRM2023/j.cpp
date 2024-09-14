#include<bits/stdc++.h>
using namespace std;

const int MX = 86400;
int a[MX];

int main(){
    int n, i, m, L, R, j;
    cin >> n;
    
    for (i = 0; i < n; i++){
        cin >> m;
        while (m--){
            cin >> L >> R;
            for (j = L; j <= R; j++){
                a[j]++;
            }
        }
    }

    int mx = 0;
    for (i = 0; i <= MX; i++){
        mx = max(mx, a[i]);
    }
    int ans = 0;
    for (i = 0; i <= MX; i++){
        ans += mx==a[i];
    }


    cout << mx << endl;
    cout << ans << endl;



    return 0;
}
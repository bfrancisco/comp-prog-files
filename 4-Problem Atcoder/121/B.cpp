#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, c;
    cin >> n >> m >> c;
    int b[21];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int ans = 0;
    for (int i = 0; i < n; i++){
        int val = c;
        for (int j = 0; j < m; j++){
            int x; cin >> x;
            val += x*b[j];
        }
        if (val > 0)
            ans++;
    }
    cout << ans;
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> v(n), c(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    int ans = -100000;
    for (int mask = 0; mask < pow(2, n); mask++){
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                x += v[i];
                y += c[i];            
            }
        }
        ans = max(ans, x-y);
    }
    cout << ans;
    return 0;
    
}
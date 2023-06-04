#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;

int main() {
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++){
        int s = 0;
        for (int i = 0; i < n; i++){
            if (bit & (1 << i)){
                s += a[i];
            }
            else{
                s -= a[i];
            }
        }
        ans += s;
    }
    cout << ans << endl;
    return 0;
}
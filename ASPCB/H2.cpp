#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;

void solve(){
    int a, b; cin >> a >> b;
    int bridges = a * (a-1) / 2;
    if (b > bridges) {cout << 255 << endl; return;}

    int ans = 1;
    int nukec = a-1;
    while(b - nukec >= 0 && nukec){
        b -= nukec;
        nukec--;
        ans++;
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
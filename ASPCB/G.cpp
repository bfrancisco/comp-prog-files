#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;

void solve(){
    int a, b; cin >> a >> b;
    int bridges = a * (a-1) / 2;
    
    cout << max(a - b, 1) << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
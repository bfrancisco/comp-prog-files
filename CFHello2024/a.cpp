#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int a, b; cin >> a >> b;
    if (abs(a-b) % 2 == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
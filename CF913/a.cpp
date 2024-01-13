#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    char a, b;
    cin >> a >> b;
    string ns = "0123456789";
    string cs = "0abcdefgh";
    for (int i = 1; i <= 8; i++){
        if (ns[i] != b) cout << a << i << endl;
    }
    for (int i = 1; i <= 8; i++){
        if (cs[i] != a) cout << cs[i] << b << endl;
    }

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
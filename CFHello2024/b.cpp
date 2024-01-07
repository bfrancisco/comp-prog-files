#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int v = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '+'){
            v++;
        }
        else{
            v--;
        }
    }
    cout << abs(v) << endl;
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
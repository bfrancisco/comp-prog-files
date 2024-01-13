#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    string s;
    cin >> s;
    int cnt = 0;
    for (auto c : s){
        if (cnt == 0){
            cout << c;
            if (c - '0' != 0) cnt=1;
        }
        else if (cnt == 1){
            if (c - '0' != 0) {cout << " "; cnt++;}
            cout << c; 
        }
        else
            cout << c;
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}
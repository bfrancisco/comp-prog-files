#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    s += " ";
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n-1; i++){
        if (s[i] != 'c'){ ans += s[i]; continue; }

        if (s[i+1] == 'e' || s[i+1] == 'i' || s[i+1] == 'y'){
            ans += 's';
        }
        else if (s[i+1] == 'h'){
            ans += 'c';
            i++;
        }
        else{
            ans += 'k';
        }
    }
    cout << ans << endl;
}

int main(){

    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}
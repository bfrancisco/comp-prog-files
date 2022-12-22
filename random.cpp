#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; string s;
    cin >> n;
    cin >> s;

    int i = 0, c = 0;
    bool pas = true;
    while (i < s.size()){
        if (c % 2){
            if (i+1 >= n || s[i+1] != s[i])
                pas = false;
            else
                i++;
        }
        i++; c++;
    }
    if (pas)
        cout << "YES";
    else
        cout << "NO";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
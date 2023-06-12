#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power[5];
// DDDDAAADDABECD
ll ranom(vector<int>& ar, vector<int>& mx){
    ll ret = 0;
    for (int i = 0; i < ar.size(); i++){
        if (ar[i] < mx[i]) ret -= power[ar[i]];
        else ret += power[ar[i]];
    }
    return ret;
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        if (s[i] == 'A') a.push_back(0);
        else if (s[i] == 'B') a.push_back(1);
        else if (s[i] == 'C') a.push_back(2);
        else if (s[i] == 'D') a.push_back(3);
        else if (s[i] == 'E') a.push_back(4);
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    power[0] = 1ll;
    for (int i = 1; i < 5; i++){
        power[i] = 10ll*power[i-1];
    }
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}
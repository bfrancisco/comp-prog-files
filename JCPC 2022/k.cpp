#include<bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long int ll;

ifstream fin("hobz.in");

void solve(){
    string s; fin >> s;
    int z = 0, odd = 0, even = 0;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0') { z++; continue; }
        
        if (i%2) odd++;
        else even++;
    }

    if (z) cout << "YES" << endl;
    else cout << (odd==even ? "YES" : "NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    fin.tie(NULL); cout.tie(NULL);
    
    int t; fin >> t;
    while (t--){
        solve();
    }

    return 0;
}
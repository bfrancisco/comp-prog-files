#include<bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long int ll;

ifstream fin("sieve.in");

void solve(){
    string a, b; fin >> a >> b;
    cout << __gcd((int)a.size(), (int)b.size()) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    fin.tie(NULL); cout.tie(NULL);
    
    int t; fin >> t;
    while (t--) solve();

    return 0;
}
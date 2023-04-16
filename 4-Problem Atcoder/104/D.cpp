#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// store As, ABs, ABCs

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    int n = s.size();

    ll multi = 1;
    ll a = 0, ab = 0, abc = 0;
    ll mod = 1000000007;
    for (int i = 0; i < n; i++){
        if (s[i] == 'A')
            a = (a + multi) % mod;
        else if (s[i] == 'B')
            ab = (ab + a) % mod;
        else if (s[i] == 'C')
            abc = (abc + ab) % mod;
        else if (s[i] == '?'){
            abc = (abc*3 + ab) % mod;
            ab = (ab*3 + a) % mod;
            a = (a*3 + multi) % mod;
            multi = (multi*3) % mod;
        }
    }

    cout << abc << endl;
    return 0;
}
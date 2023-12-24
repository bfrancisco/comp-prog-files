#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;

    if (n == 1) { cout << 2; return 0; }
    if (n == 2 && s[0] != s[1]) { cout << 1; return 0; }
    if (n == 2 && s[0] == s[1]) { cout << 2; return 0; }

    int gud = 0;
    for (int i = 2; i < n; i++){
        if (s[i] != s[i-2] && s[i] != s[i-1] && s[i-1] != s[i-2]){
            gud = 1; break;
        }
    }
    if (gud) { cout << 0; return 0; }

    if (s[n-1] == s[n-2]) cout << 2;
    else cout << 1;

    return 0;
}
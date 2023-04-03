#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    if (m!=n){cout << "No"; return 0;}

    for (int r = 0; r < n; r++){
        bool pas = true;
        for (int i = 0; i < n; i++){
            if (s[i] != t[i])
                pas = false;
        }
        if (pas){cout << "Yes"; return 0;}

        string cpy = t;
        t[0] = cpy[n-1];
        for (int i = 1; i < n; i++){
            t[i] = cpy[i-1];
        }
        // cout << t << endl;
    }
    cout << "No";
    return 0;
}
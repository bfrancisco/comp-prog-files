#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> compute_z(string s){
    int n = s.length();
    vector<int> z(n);
    z[0] = 0;
    for (int i = 1, L = 0, R = 0; i < n; i++){
        if (i <= R) 
            z[i] = min(R-i+1, z[i-L]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) 
            z[i]++;
        if (i+z[i]-1 > R)
            L = i, R = i+z[i]-1;
    }
    z[0] = n;
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, p;
    cin >> s >> p;
    string ss = p + '$' + s;
    vector<int> z = compute_z(ss);
    int ans = 0;
    for (int i = 0; i < z.size(); i++){
        if (z[i] == p.size()) ans++;
    }
    cout << ans << endl;
    return 0;
}
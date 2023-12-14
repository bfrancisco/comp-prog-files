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
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = compute_z(s);
    // for (auto zz : z) cout << zz << " "; cout << endl;
    for (int i = 0; i < n; i++){
        int good = 1;
        for (int j = i+1; j < n; j += i+1){
            if (j + i < n){
                if (z[j] < i+1) {good = 0; break;}
            }
            else{
                if (z[j] < n-j) {good = 0; break;}
            }
        }
        if (good) cout << i+1 << " ";
    } 
    cout << endl;
    
    return 0;
}
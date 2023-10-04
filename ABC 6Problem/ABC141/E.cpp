#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int z[10000];
void compute_z(string s){
    int n = s.length(); z[0] = 0;
    for (int i = 1, L = 0, R = 0; i < n; i++){
        if (i <= R) z[i] = min(R-i+1, z[i-L]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i]-1 > R) L = i, R = i+z[i]-1;
    }
    z[0] = n;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;
    
    compute_z("na#" + s);
    for (int i = 0; i < n+3; i++){
        cout << z[i] << " ";
    }
    cout << endl;

    return 0;
}
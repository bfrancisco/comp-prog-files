#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    cout << ((s[2] == s[3] && s[4] == s[5]) ? "Yes" : "No") << endl;
    return 0;
}
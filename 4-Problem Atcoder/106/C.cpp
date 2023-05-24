#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; ll k;
    cin >> s >> k;

    char ans = '1';
    for (int i = 0; i < min(100ll, k); i++)
        if (s[i] != '1'){ans = s[i]; break;}
    
    cout << ans << endl;
    
    return 0;
}
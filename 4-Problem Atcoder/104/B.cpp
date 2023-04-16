#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    int n = s.size();
    string ans = "AC";
    if (s[0] != 'A') ans = "WA";

    int c = 0;
    for (int i = 2; i < n-1; i++)
        if (s[i] == 'C') c++;
    if (c != 1) ans = "WA";

    for (int i = 0; i < n; i++){
        if (s[i] - 'a' < 0 && s[i] != 'A' && s[i] != 'C')
            ans = "WA";
    }

    cout << ans << endl;
    return 0;
}
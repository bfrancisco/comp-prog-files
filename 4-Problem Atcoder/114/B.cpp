#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;
    int ans = 1e9;
    for (int i = 0; i <= s.size()-3; i++){
        int val = 0, multi = 100;
        for (int j = 0; j < 3; j++){
            int a;
            a = s[i+j] - '0';
            val += a*multi;
            multi /= 10;
        }
        // cout << val << endl;
        ans = min(ans, abs(753-val));
    }
    cout << ans;
    return 0;
}
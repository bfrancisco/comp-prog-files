#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;

    int r = 0; 
    for (auto c : s){
        if (c == 'R') r++;
    }
    // cout << r << endl;
    int ans = r;
    for (int i = 0; i < r; i++){
        if (s[i] == 'R') ans--;
    }

    cout << ans;
    return 0;
    
}
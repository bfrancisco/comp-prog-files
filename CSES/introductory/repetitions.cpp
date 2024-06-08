#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    char prev = ' ';
    int cnt = 0;
    int ans = 1;
    for (auto c : s){
        if (c == prev) {cnt++; ans = max(ans, cnt);}
        else {cnt = 1;}
        prev = c;
    }
    cout << ans << endl;
    

    return 0;
}
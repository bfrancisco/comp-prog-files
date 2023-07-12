#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    char nope = 'L';

    string ans = "Yes";
    for (auto c : s){
        if (c == nope) ans = "No";
        if (nope == 'L') nope = 'R';
        else nope = 'L';
    }

    cout << ans << endl;


    return 0;
}
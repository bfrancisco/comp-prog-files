#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string s;

int f(char cur){
    int r = 0;
    for (int c : s){
        if (c != cur)
            r++;
        cur = (cur == '1' ? '0' : '1');
        // cout << cur << " ";
    }
    // cout << endl;
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s;
    cout << min(f('0'), f('1')) << endl;

    return 0;
}
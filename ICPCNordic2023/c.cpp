#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int x = 0;
    int ans = 0;
    for (int i = 0 ; i < n; i++){
        char c; cin >> c;
        if (c == '1') { x = 3; ans++; }
        else if (x > 0) { ans ++; }
        x--;
    }
    cout << ans << endl;
    return 0;
}
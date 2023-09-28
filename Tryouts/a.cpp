#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int v = 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        v += x;
        ans = min(ans, v);
    }
    cout << -ans << endl;
    
    return 0;
}
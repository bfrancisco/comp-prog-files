#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, t; cin >> a >> b >> t;
    int ans = 0;
    for (int i = a; i <= t; i += a){
        ans += b;
    }
    cout << ans;
    return 0;
    
}
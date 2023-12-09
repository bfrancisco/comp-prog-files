#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    int x;
    cin >> x;
    int ans = x;
    int prev = x;
    int curval = x;
    for (int i = 1; i < n; i++){
        cin >> x;
        if ((prev+x) % 2 == 0){
            curval = x;
        }
        else{
            curval = max(x, curval+x);
        }
        ans = max(ans, curval);
        prev = x;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
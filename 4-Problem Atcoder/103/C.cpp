#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ans += x-1;
    }
    cout << ans;

    return 0;
}
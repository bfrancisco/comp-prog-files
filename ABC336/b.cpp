#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i <= 30; i++){
        if (n & (1 << i)) break;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}
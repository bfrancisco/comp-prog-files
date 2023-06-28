#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    float n; cin >> n;
    float ans = 0;
    for (float i = 1; i <= n; i++){
        ans += i/2 * n/i * (1 + n/i);
    }

    cout << ans << endl;
    
    return 0;
}
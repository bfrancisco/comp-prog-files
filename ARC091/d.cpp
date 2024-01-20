#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = k+1; i <= n; i++){
        for (int j = k; j <= n; j+=i){
            ans += i-(min(n, j) % i);
            cout << '\t' << ans << endl;
        }
        cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long double n; cin >> n;
    int ans = 0;

    while (n-1 > 0.000000000000001){
        n /= (long double)2;
        ans++;
    }
    if (n-0 > 0.000000000000001){
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}
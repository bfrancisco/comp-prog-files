#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b; cin >> a >> b;
    int c = pow(100, a);
    int ans = c*b;
    if (b == 100) ans+= c;

    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll a, b, k; cin >> a >> b >> k;

    a -= k;
    if (a < 0){
        b += a;
        a = 0;
    }
    if (b < 0) b = 0;
    cout << a << " " << b << endl;
    
    return 0;
}
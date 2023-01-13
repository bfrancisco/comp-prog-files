#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    ll num = -1;
    for (ll div = 1; div*div <= n; div++){
        if (n % div == 0){
            num = n/div;
        }
    }

    cout << (to_string(num)).size() << endl;
    return 0;
}
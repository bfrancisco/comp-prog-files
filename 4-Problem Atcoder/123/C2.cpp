#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll c[6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    ll a[5];
    for (int i = 0; i < 5; i++) 
        cin >> a[i];

    c[0] = n;
    ll ans = 0;
    
    while (c[5] != n){
        int f;
        for (f = 0; f < 6; f++){
            if (c[f] > 0){
                break;
            }
        }

        ll t = c[f]/a[f];
        for (f; f < 6; f++){
            
        } 
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll c[6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    ll a[5];
    for (int i = 0; i < 5; i++) cin >> a[i];

    
    c[0] = n;
    ll t = 0;
    // int asd = 0;
    while (c[5] != n){
        for (int i = 5; i >= 1; i--){
            if (a[i-1] > c[i-1]){
                c[i] += c[i-1];
                c[i-1] = 0;

            }
            else{
                ll val = a[i-1] * (c[i-1] / a[i-1]);
                c[i] += val;
                c[i-1] -= val;
            }
        }

        for (int i = 0; i < 6; i++){
            cout << c[i] << " ";
        }
        cout << endl;

        // asd++;
        // if (asd==7){break;}
    }
    
    return 0;
}
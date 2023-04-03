#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll ans = 0;
        ll bit = 29;
        while (n > 0){
            cout << "- " << pow(2LL, bit) << endl;
            cout.flush();

            ll temp; cin >> temp;
            // if (temp == -1) return 0;
            if (temp < n){
                ans += pow(2, bit);
                n = temp;
            }
            bit--;
        }

        cout << "! " << ans << endl;
        cout.flush();
    }
    return 0;
}
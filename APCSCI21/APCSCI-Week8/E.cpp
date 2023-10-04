#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n;
ll a[2000000];
ll ans = 1e18;
void rec(string s){
    //cout << s << endl;
    if (s.size() == n){
        ll i = 0; ll OR = 0;
        vector<ll> toXOR;
        char prev = s[0];
        while (i < n){
            if (s[i] == prev){
                OR |= a[i];
            }
            else{
                prev = s[i];
                toXOR.push_back(OR);
                OR = a[i];
            }
            i++;
        }
        toXOR.push_back(OR);

        // for (auto x : toXOR) cout << x << " ";
        // cout << endl;
        ll xorval = toXOR[0];
        for (ll i = 1; i < toXOR.size(); i++){
            xorval ^= toXOR[i];
        }
        ans = min(ans, xorval);
        // cout << s << " " << xorval << endl;
        return;
    }
    rec(s + '0');
    rec(s + '1');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i<n; i++) cin >> a[i];

    rec("");
    cout << ans;
    return 0;
}
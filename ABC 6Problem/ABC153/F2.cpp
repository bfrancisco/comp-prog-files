#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; ll d, a;
    cin >> n >> d >> a;

    vector<pair<ll, ll>> v;

    for (int i = 0; i < n; i++){
        ll x, h; cin >> x >> h;
        ll val = (h+a-1) / a;
        v.push_back({x, val});
    }
    
    sort(v.begin(), v.end());
    
    
    return 0;
}   
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    unordered_map<ll, ll> c;
    c[0] = 1;

    ll sm = 0, ans = 0;
    for (int i = 0; i < n; i++){
        sm = (sm + a[i]) % m;
        if (c.find(sm) != c.end()){
            ans += c[sm];
            c[sm]++;
        }
        else{
            c[sm] = 1;
        }
    }
    cout << ans << endl;
    
    return 0;
}
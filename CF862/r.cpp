#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool hasnoroot(ll a, ll b, ll c){
    if (b*b - (4ll*a*c) < 0) return true;
    return false;
}

int bisearch(vector<ll>& lns, ll val, ll n){
    int l = 0;
    int r = n;

    while(r-l < 4){
        int mid = (l+r)/2;
        if (lns[mid] == val){
            break;
        }
        else if (lns[mid] < val){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
        

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;

        vector<ll> lns(n);
        for (int i = 0; i < n; i++){
            cin >> lns[i];
        }

        sort(lns.begin(), lns.end());

        for (int j = 0; j < m; j++){
            ll a, b, c;
            cin >> a >> b >> c;
            
            ll k = bisearch(lns, b, n);
            bool pas = false;
            for (ll i = k; i < k+4; i++){
                if (i >= n) break;
                if (hasnoroot(a, b-lns[i], c)){
                    cout << "YES\n" << lns[i] << endl;
                    pas = true;
                }
            }
            if (!pas) cout << "NO" << endl;
        }
    }

    return 0;
}
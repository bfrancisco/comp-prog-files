#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for (auto x : a) cout << x << " "; cout << endl;

    int l = 0, r = 0;
    map<int, ll> freq;
    set<int> st;
    ll ans = 0;
    int torem = -1;
    while (r < n && l < n){
        cout << l << " " << r << endl;
        for (auto x : st) cout << x << " "; cout << endl;
        // for (auto [k, v] : freq){
        //     cout << '\t' << k << " : " << v << endl;  
        // } cout << endl;

        if (torem != -1){
            cout << "rem: " << torem << endl;
            freq[a[l]]--;
            if (freq[a[l]] == 0) {
                st.erase(a[l]);
                freq.erase(a[l]);
                torem = -1;
            }
            l++;
        }
        else if (st.size() < m){
            cout << "r++" << endl;
            freq[a[r]]++;
            st.insert(a[r]);
            r++;
        }
        else if (*st.rbegin() - *st.begin() >= m){
            cout << "LONG: " << *st.rbegin() << " - " << *st.begin() << endl;
            freq[a[l]]--;
            if (freq[a[l]] == 0) {st.erase(a[l]); freq.erase(a[l]);}
            l++;
        }
        else{
            ll ad = 1;
            for (auto [x, f] : freq){
                ad *= f;
            }
            ans += ad;
            torem = *st.begin();

            cout << "ADD: " << ad << endl;
        }
        cout << endl;
    }
    cout << ans % 1000000007 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}
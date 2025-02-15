#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int DEBUG = 0;

void solve(){

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if (DEBUG){for (auto x : a) cout << x << " "; cout << endl;}

    int l = 0, r = 0;
    map<int, ll> freq;
    set<int> st;
    ll ans = 0;
    int torem = -1;
    
    // r is NOT included in the ds's
    int prevl = -1, prevr = -1;
    while (r < n && l < n){
        if (DEBUG){
            cout << l << " " << r << endl;
            cout << "st: "; for (auto e : st) cout << e << " "; cout << endl;
            for (auto [k, f] : freq) cout << '\t' << k << ": " << f << endl; 
        }
        if (torem != -1){
            if (DEBUG) cout << "rem: " << torem << endl;
            freq[a[l]]--;
            if (freq[a[l]] == 0){
                freq.erase(a[l]);
                st.erase(a[l]);
                torem = -1;
            }
            l++;
        }
        else if (st.size() < m){
            if (DEBUG) cout << "r++" << endl;
            freq[a[r]]++;
            st.insert(a[r]);
            r++;
        }
        else if (st.size() == m){
            if (*st.rbegin() - *st.begin() < m){
                
                int lst = *st.rbegin();
                while (r < n && a[r] == lst){
                    freq[a[r]]++;
                    r++;
                }
                prevl = *st.begin();
                prevr = *st.rbegin();
                ll ad = 1;
                for (auto [x, f] : freq) ad *= f;
                ans += ad;

                if (DEBUG) cout << "add: " << ad << endl; 
            }
            torem = *st.begin();
        }
        if (DEBUG) cout << endl;
    }

    if (prevl != *st.begin() && prevr != *st.rbegin() && st.size() == m && *st.rbegin() - *st.begin() < m){
        int lst = *st.rbegin();
        while (r < n && a[r] == lst){
            freq[a[r]]++;
            r++;
        }
        ll ad = 1;
        for (auto [x, f] : freq) ad *= f;
        ans += ad;
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
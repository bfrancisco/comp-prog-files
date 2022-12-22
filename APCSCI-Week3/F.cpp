#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    //int N = 500001;
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    int cho;
    int ans;
    
    set<int> a[26];
    for (int i = 0; i < n; i++){
        a[s[i] - 97].insert(i+1);
    }

    while (q--){
        cin >> cho;
        if (cho == 1){
            int ind; char ch;
            cin >> ind >> ch;
            a[s[ind-1] - 97].erase(ind);
            a[ch - 97].insert(ind);
            s[ind-1] = ch;
        }
        else if (cho == 2){
            int l, r; cin >> l >> r;
            ans = 0;
            for (int i = 0; i < 26; i++){
                auto point = a[i].lower_bound(l);
                if (point != a[i].end() && *point <= r){
                    ans += 1;
                }
            }
            cout << ans << endl;
        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    //cin >> t;
    while (t--){
        solve();
    }

    
    return 0;
}
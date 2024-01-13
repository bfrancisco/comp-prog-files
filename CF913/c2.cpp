#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> a;
    // 2 1 2 1 1 3
    int rpt = 0;
    char lst = '?';
    for (auto c : s){
        if (c == lst) {rpt++;}
        else{
            if (rpt) a.push_back(rpt);
            rpt = 1;
        }
        lst = c;
    }
    if (rpt) a.push_back(rpt);

    // for (auto x : a) cout << x << " "; cout << endl;

    int as = a.size();
    set<pair<int, int>> db;
    vector<int> left(as), right(as);
    for (int i = 0; i < as; i++){
        db.insert({a[i], i});
        left[i] = i-1;
        right[i] = i+1;
    }
    right[as-1] = -1;

    while(db.size() > 2){
        auto [v, ind] = *db.end();
        int vl, vr;
        vl = (left[ind] == -1 ? -1 : a[left[ind]]);
        vr = (right[ind] == -1 ? -1 : a[right[ind]]);
        if (vl == -1 && vr == -1) break;
        if (vl >= vr){
            a[ind]--;
            a[left[ind]]--;
            db.erase({v, ind});
            db.erase({vl, left[ind]});
            if (v > 1) db.insert({v-1, ind});
            if (vl > 1) db.insert({vl-1, left[ind]});
            else{
                left[ind]--;
            }
        }
        else{
            a[ind]--;
            a[right[ind]]--;
            db.erase({v, ind});
            db.erase({vr, right[ind]});
            if (v > 1) db.insert({v-1, ind});
            if (vr > 1) db.insert({vr-1, right[ind]});
            else{
                right[ind]++;
                if (right[ind] == as) right[ind] = -1;
            }
        }
        for (auto x : a) cout << x << " "; cout << endl;
    }

    int ans = 0;
    for (auto x : a) if (x != -1) ans += x;
    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
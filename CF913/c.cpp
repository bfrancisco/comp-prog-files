#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 10000000;

    int rpt = 0;
    vector<char> a;
    for (auto c : s){
        if (!a.empty() && c == a.back()) {rpt++; a.push_back(c);}
        else{
            if (rpt >= 2) {rpt--; a.pop_back();}
            else {rpt = 1; a.push_back(c);}
        }
    }

    // for (auto c : a) cout << c; cout << endl;

    reverse(a.begin(), a.end());
    rpt = 0;
    vector<char> b;
    for (auto c : a){
        if (!b.empty() && c == b.back()) {rpt++; b.push_back(c);}
        else{
            if (rpt >= 2) {rpt--; b.pop_back();}
            else {rpt = 1; b.push_back(c);}
        }
    }
    // for (auto c : b) cout << c; cout << endl;
    
    vector<char> d;
    for (auto c : b){
        if ((!d.empty() && c == d.back()) || d.empty()) {d.push_back(c);}
        else d.pop_back();
    }

    // for (auto c : d) cout << c; cout << endl;

    ans = min(ans, (int)d.size());

    reverse(s.begin(), s.end());
    rpt = 0;
    vector<char> aa;
    for (auto c : s){
        if (!aa.empty() && c == aa.back()) {rpt++; aa.push_back(c);}
        else{
            if (rpt >= 2) {rpt--; aa.pop_back();}
            else {rpt = 1; aa.push_back(c);}
        }
    }

    // for (auto c : aa) cout << c; cout << endl;

    reverse(aa.begin(), aa.end());
    rpt = 0;
    vector<char> bb;
    for (auto c : aa){
        if (!bb.empty() && c == bb.back()) {rpt++; bb.push_back(c);}
        else{
            if (rpt >= 2) {rpt--; bb.pop_back();}
            else {rpt = 1; bb.push_back(c);}
        }
    }
    // for (auto c : bb) cout << c; cout << endl;
    
    vector<char> dd;
    for (auto c : bb){
        if ((!dd.empty() && c == dd.back()) || dd.empty()) {dd.push_back(c);}
        else dd.pop_back();
    }

    // for (auto c : d) cout << c; cout << endl;
    ans = min(ans, (int)dd.size());
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
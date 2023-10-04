#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int counth = 0;
    vector<string> s, h, onlys, onlyh;
    for (int i = 0; i < n; i++){
        string x; cin >> x;
        int flags = 0, flagh = 0;

        for (char c : x){
            if (c == 's') flags = 1;
            else {flagh = 1; counth++;}
        }

        if (x.front() == 's'){
            if (!flagh) onlys.push_back(x);
            else s.push_back(x);
        }
        else {
            if (!flags) onlyh.push_back(x);
            else h.push_back(x);
        }
    }

    sort(onlys.begin(), onlys.end());
    sort(onlyh.begin(), onlyh.end());
    sort(s.begin(), s.end(), greater());
    sort(h.begin(), h.end(), greater());

    /*
    cout << endl;
    for (auto x : onlys) cout << x << endl;
    cout << endl;
    for (auto x : onlyh) cout << x << endl;
    cout << endl;
    for (auto x : s) cout << x << endl;
    cout << endl;
    for (auto x : h) cout << x << endl;
    */

    vector<char> conc;
    for (auto x : onlys){
        for (char c : x) conc.push_back(c);
    }
    for (auto x : s){
        for (char c : x) conc.push_back(c);
    }
    for (auto x : h){
        for (char c : x) conc.push_back(c);
    }
    for (auto x : onlyh){
        for (char c : x) conc.push_back(c);
    }

    int ans = 0;
    for (auto c : conc){
        if (c == 's') ans += counth;
        else counth--;
    }
    cout << ans;

    return 0;
}
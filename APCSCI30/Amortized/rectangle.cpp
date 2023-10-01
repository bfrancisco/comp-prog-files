#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n+1);
    unordered_map<int, int> xtoi;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        xtoi[a[i]] = i;
    }
    map<int, vector<int>> xtov;
    for (int i = 1; i <= n; i++){
        if (xtov.find(a[i]) == xtov.end()){
            xtov[a[i]] = {i};
        }
        else{
            xtov[a[i]].push_back(i);
        }
    }

    set<int> cur;
    cur.insert(0);
    cur.insert(n+1);

    ll ans = 0;
    for (auto &[x, v] : xtov){
        // int pl = -1, pr = -1;
        for (auto& i : xtov[x]){
            // if (pl < i && i < pr) continue;
            auto it = lower_bound(cur.begin(), cur.end(), xtoi[x]);
            ll l, r;
            r = *it;
            it--;
            l = *it;
            // pl = l; pr = r;
            cur.insert(i);
            ans = max(ans, (r-l-1) * x);
        }
    }

    cout << ans << endl;


    return 0;
}

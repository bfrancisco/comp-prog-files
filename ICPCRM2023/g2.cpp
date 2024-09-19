#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
    int n;
    ll d;
    cin >> n >> d;

    map<ll, int> freq;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    int un = freq.size();
    vector<ll> val(un+1);
    int i = 1;
    for (auto [k, v] : freq){
        val[i++] = k;
    }

    vector<pair<int, int>> pnt(un+1);
    pnt[0] = {un, 1}; // sentinel
    for (i = 1; i <= un; i++){
        pnt[i].first = i-1;
        pnt[i].second = (i+1);
        if (i == un) pnt[i].second = 0;
    }

    // for (auto v : val) cout << v << " "; cout << endl;

    vector<ll> ans;
    while (true){
        // make initial window
        int l, r;
        l = r = pnt[0].second;
        int cur_freq = 0;
        
        // go through all windows
        int mx = -1;
        int trgt_l = -1, trgt_r = -1;
        int target = -1;
        while (r != 0){
            cur_freq += freq[val[r]];
            while (val[l] + 2ll*d < val[r]){
                cur_freq -= freq[val[l]];
                l = pnt[l].second;
            }
            if (mx < cur_freq){
                mx = cur_freq;
                trgt_l = l;
                trgt_r = r;
                target = val[r] - d;
            }
            r = pnt[r].second;

        }

        if (mx == -1) break;

        // cout << trgt_l << " " << trgt_r << " " << mx << endl;
        // remove max window
        trgt_l = pnt[trgt_l].first;
        trgt_r = pnt[trgt_r].second;

        pnt[trgt_l].second = trgt_r;
        pnt[trgt_r].first = trgt_l;

        ans.push_back(target);

    }

    cout << ans.size() << endl;
    for (auto e : ans) cout << e << " "; cout << endl;

    return 0;
}
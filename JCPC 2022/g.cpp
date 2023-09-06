#include<bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long int ll;

ifstream fin("milk.in");

void printvii(vector<pair<int, int>>& Q, int q){
    for (int i = 0; i < q; i++){
        cout << Q[i].first << " " << Q[i].second << endl;
    }
}

int bisearch(int val, vector<int>& firsts){
    // val will always be greater than firsts[0]
    // cout << "Searching: " << val << endl;
    int l = 0, r = firsts.size() - 1;
    if (val > firsts[r]) return r;
    while (r-l > 1){
        int mid = (l+r) / 2;
        if (firsts[mid] == val){
            return mid;
        }
        else if (firsts[mid] < val){
            l = mid;
        }
        else if (firsts[mid] > val){
            r = mid;
        }
    }

    return l;
}

void solve(){
    int n, q; fin >> n >> q;
    vector<int> a(n);
    fin >> a[0];
    int mx = a[0];

    vector<pair<int, int>> dec;
    // sort the decreasing pic to increasing
    for (int i = 1; i < n; i++){
        fin >> a[i];
        mx = max(mx, a[i]);
        if (a[i] < a[i-1]){
            dec.push_back({a[i], -a[i-1]});
        }
    }

    sort(dec.begin(), dec.end());
    vector<pair<int, int>> flat_dec;
    flat_dec.push_back({dec[0].first, -dec[0].second});
    for (int i = 1; i < dec.size(); i++){
        int l = dec[i].first, r = -dec[i].second;
        if (r > flat_dec.back().second){
            flat_dec.push_back({l, r});
        }
    }

    // printvii(flat_dec, flat_dec.size()); cout << endl;
    // first max second //// SURE that can go from second to first

    vector<int> firsts;
    unordered_map<int, int> first_to_second;
    for (auto& [l, r] : flat_dec){
        firsts.push_back(l);
        first_to_second[l] = r;
    }

    // for (auto x : firsts) cout << x << " "; cout << endl << endl;

    for (int i = 0 ; i < q; i++){
        int l, r; fin >> l >> r;
        // cout << l << " " << r << endl;
        if (l==r) cout << "Yes" << endl;
        else if (l < r){
            cout << (r <= mx ? "Yes" : "No") << endl;
        }
        else if (l > r){
            // binary search r. if r < first of firsts, then impossible
            if (r < firsts[0]) { cout << "No" << endl; continue; }
            cout << l << " " << r << endl;
            int ind = bisearch(r, firsts);
            cout << ind << endl;
            cout << (first_to_second[firsts[ind]] >= l ? "Yes" : "No") << endl;
        }
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    fin.tie(NULL); cout.tie(NULL);
    
    int t; fin >> t;
    while (t--){
        solve();
    }

    return 0;
}
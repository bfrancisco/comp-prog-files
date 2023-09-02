#include<bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long int ll;

ifstream fin("milk.in");

int bisearch(int val, vector<int>& a){
    int l = 0, r = a.size() - 1;
    while(r - l > 1){
        int mid = (l+r) / 2;
        if (a[mid] == val) return mid;
        else if (a[mid] < val) l = mid;
        else r = mid;
    }
    if (a[l] == val) return l;
    else return r;
}

void solve(){
    int n, q; fin >> n >> q;
    vector<int> a(n);
    int mx = 0;

    for (int i = 0; i < n; i++){
        fin >> a[i];
        mx = max(mx, a[i]);
    }

    // for (auto x : a) cout << x << " "; cout << endl;
    map<int, int> lowestval;
    lowestval[a[n-1]] = 2e9;
    for (int i = n-2; i >= 0; i--){
        lowestval[a[i]] = min(a[i+1], lowestval[a[i+1]]);
    }
    
    sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++){
    //     cout << "Value: " << a[i] << "  Lowest: " << lowestval[a[i]] << endl;
    // }
    // for (auto x : a) cout << x << " "; cout << endl;
    for (int i = 0; i < q; i++){
        int l, r; fin >> l >> r;
        // cout << l << " " << r << endl;
        if (l > mx || r > mx) cout << "No" << endl;

        else if (l <= r) cout << "Yes" << endl;
        else if (l > r){
            int ind = bisearch(l, a);
            // cout << "ind: " << ind << " val: " << a[ind] << " lowest: " << lowestval[a[ind]] << endl;
            cout << (lowestval[a[ind]] <= r ? "Yes" : "No") << endl;
        }
    }
    
}

int main(){
    // ios_base::sync_with_stdio(false);
    // fin.tie(NULL); cout.tie(NULL);
    
    int t; fin >> t;
    while (t--){
        solve();
    }

    return 0;
}
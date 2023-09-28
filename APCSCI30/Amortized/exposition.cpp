#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    if (n == 1){
        cout << "1 1\n1 1" << endl;
        return 0;
    }
    
    int l = 0, r = 0;
    set<pair<int, int>> data;
    data.insert({a[l], l});
    int mxrange = 0;
    vector<pair<int, int>> ans;
    while (r < n){
        // cout << l << " " << r << endl;
        if ((*data.rbegin()).first - (*data.begin()).first > d){
            data.erase({a[l], l});
            l++;
        }
        else{
            mxrange = max(mxrange, r-l+1);
            ans.push_back({l+1, r+1});
            r++;
            if (r==n) break;
            data.insert({a[r], r});
        }
    }

    vector<pair<int, int>> trueans;
    for (auto [a, b] : ans){
        if (b-a+1 == mxrange)
            trueans.push_back({a, b});
    }
    
    // cout << "ans" << endl;
    cout << mxrange << " " << trueans.size() << endl;

    for (auto [a, b] : trueans)
        cout << a << " " << b << endl;

    
    return 0;
}

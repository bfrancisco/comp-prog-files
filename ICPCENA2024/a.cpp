#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

    int n; cin >> n;
    vector<int> a(n), mn(n, 1e9), mx(n, -1e9);
    int mx_sofar = -1e9;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mx_sofar = max(mx_sofar, a[i]);
        mx[i] = mx_sofar;
    }

    int mn_sofar = 1e9;
    for (int i = n-1; i >= 0; i--){
        mn_sofar = min(mn_sofar, a[i]);
        mn[i] = mn_sofar;
    }


    // for (auto x : mn) cout << x << " "; cout << endl;

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (a[i] == mx[i] && a[i] == mn[i]){
            ans.push_back(a[i]);
        }
    }

    cout << ans.size() << " ";
    // for (auto x : ans) cout << x << " ";
    for (int i = 0; i < min(100, (int)ans.size()); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
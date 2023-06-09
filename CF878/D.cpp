#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n; 
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for (auto e : a) cout << e << " "; cout << endl;

    vector<int> difs;
    for (int i = 1; i < n; i++){
        difs.push_back(a[i] - a[i-1]);
    }
    for (auto e : difs) cout << e << " "; cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) solve();

    return 0;
}
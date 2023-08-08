#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    string s; cin >> s;
    int n = s.size() + 1;
    vector<int> a = {0};
    for (auto c: s) a.push_back(c - '0');
    int left = n;
    for (int i = n-1; i > 0; i--){
        if (a[i] >= 5){
            left = i;
            a[i] = 0;
            for (int k = i-1; k >= 0; k--){
                if (a[k] < 9) {a[k]++; break;}
                else a[k] = 0;
            }
        }
    }

    // for (auto v : a) cout << v << " "; cout << endl;

    int i = 0;
    while (a[i] == 0) i++;
    for (; i < n; i++){
        cout << (i >= left ? 0 : a[i]);
    }
    cout << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
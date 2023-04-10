#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    int l = 0;
    while (l < n){
        if (a[l] == 0) {l++; continue;}
        
        int mn = 1e9;
        for (int r = l; r < n; r++){
            if (a[r] == 0) break;
            mn = min(mn, a[r]);
        }
        ans += mn;
        // cout << l << " " << mn << endl;
        for (int i = l; i < n; i++){
            if (a[i] == 0) break;
            a[i] -= mn;
        }
    }

    cout << ans << endl;
    
    return 0;
}
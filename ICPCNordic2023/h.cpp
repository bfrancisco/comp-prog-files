#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// 29 85 88 12 52 37 19 86 7 44
// 85 88 12 = 3
// 12 52 37 = 15
// 19 86 7 = 67
// inc
// 29 85 88 (cap 2, ind 3)
// 12 52 
// 19 86
// 7 44
// complete
// 29 85 88 12
// 12 52 37
// 19 86 7
// 7 44 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<vector<ll>, int>> peaks;
    // seq, ind of last
    peaks.push_back({{a[0]}, -1});
    for (int i = 1; i < n; i++){
        if (a[i-1] < a[i]){
            peaks.back().first.push_back(a[i]);
        }
        else{
            peaks.back().second = i-1;
            peaks.push_back({{a[i]}, 1e8});
        }
    }

    // for (auto& [v, i] : peaks){
    //     for (auto x : v) cout << x << " ";
    //     cout << endl;
    // }

    ll ans = 0;
    for (int p = 0; p < peaks.size(); p++){
        auto& [peakv, peaki] = peaks[p];
        int cap = peakv.size() - 1;
        if (cap == 0) continue;
        ll boundOfPeak = -1;
        if (peaki+1 < n && a[peaki] >= a[peaki + 1]){
            boundOfPeak = peakv[peakv.size()-1] - peakv[0];
        }
        else{
            continue;
        }
        // cout << "bound: " << boundOfPeak << endl;
        for (int i = peaki+1; i < n; i++){
            if (cap == 0) break;
            if (a[peaki] >= a[i]){
                // cout << boundOfPeak << " " << a[peaki] << " " << a[i] << endl;
                ans = max(ans, min(boundOfPeak, a[peaki] - a[i]));   
                cap--;
            }
            else{
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
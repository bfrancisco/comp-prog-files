#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int n;
ll x;
vector<pair<int, int>> arr;
int bsearch(ll target, int ind){
    int l = 0, r = n-1;
    int m;
    int want = -1;
    while(l < r){
        m = l + (r-l)/2;
        if (arr[m].first <= target){
            l = m + 1;
            want = l;
        }
        else if (target < arr[m].first){
            r = m;
        }
    }

    for (int z = -1; z <= 1; z++){
        int i = want+z;
        if (!(0 <= i && i < n)) continue;
        if (arr[i].first == target && arr[i].second != ind){
            return arr[i].second;
        } 
    }
    return -1;

}

void solve(){
    cin >> n >> x;

    arr.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++){
        int j = bsearch(x - arr[i].first, arr[i].second);
        // cout << arr[i].first << " " << arr[i].second << endl;
        if (j != -1){
            cout << arr[i].second+1 << " " << j+1;
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    // int t; cin >> t;
    int t = 1;
    while (t--){
        solve();
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w; cin >> h >> w;
    vector<int> a(h*w);
    int mn = 1e9;
    for (int i = 0; i < h*w; i++){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    int ans = 0;
    for (auto x : a){
        ans += x-mn;
    }
    cout << ans << endl;

    return 0;
}
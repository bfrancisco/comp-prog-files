#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int get_score(vector<int>& v){
    int s = 0;
    for (int i = 0; i < v.size(); i++){
        if (i+1 == v[i]) s++;
    }
    return s;
}

void solve(){
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    vector<int> b(k);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < k; i++){
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 0; i <= 2*n; i++){
        if (i >= d) break;
        int score = get_score(a);
        score += (d-i-1)/2;
        ans = max(ans, score);
        for (int j = 0; j < b[i%k]; j++) a[j]++;
    }
    cout << ans << endl;

    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
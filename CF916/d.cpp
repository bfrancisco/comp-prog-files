#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int MX = 1000000000;

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> A,B,C;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        A.push_back({x, i});
    }
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        B.push_back({x, i});
    }
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        C.push_back({x, i});
    }

    sort(A.begin(), A.end(), greater<pair<int, int>>());
    sort(B.begin(), B.end(), greater<pair<int, int>>());
    sort(C.begin(), C.end(), greater<pair<int, int>>());

    int mx = -1;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                if (A[i].second == B[j].second || A[i].second == C[k].second || B[j].second == C[k].second) continue;
                mx = max(mx, A[i].first + B[j].first + C[k].first);
            }
        }
    }
    cout << mx << endl;
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
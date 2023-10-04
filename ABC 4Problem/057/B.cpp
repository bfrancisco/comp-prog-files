#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    pair<ll, ll> A[51], B[51];
    for (int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }
    for (int i = 0; i < m; i++){
        cin >> B[i].first >> B[i].second;
    }
    
    int C[51];
    ll MAX = 1e13;
    for (int i = 0; i < n; i++){
        int mn = MAX;
        for (int j = 0; j < m; j++){
            if (abs(A[i].first - B[j].first) + abs(A[i].second - B[j].second) < mn){
                mn = abs(A[i].first - B[j].first) + abs(A[i].second - B[j].second);
                C[i] = j+1;
            }
            // cout << i << " " << j << endl;
        }
    }

    for (int i = 0; i < n; i++)
        cout << C[i] << endl;

    return 0;
}
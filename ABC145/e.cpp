#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, t; cin >> n >> t;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        A[i] = {a, b};
    }

    A.sort(A.begin(), A.end());
    // max happiness min time

    vector<vector<int>> dp(n, vector<int>(t, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < t; j++){

        }
    }
    
    return 0;
}
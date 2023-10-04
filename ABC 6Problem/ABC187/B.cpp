#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (x[j] == x[i] || i == j) continue;
            double val = (double)(y[j] - y[i]) / (double)(x[j] - x[i]);
            if (-1 <= val && val <= 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
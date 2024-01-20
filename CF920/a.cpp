#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    
    vector<int> x(4), y(4);
    for (int i = 0; i < 4; i++){
        cin >> x[i] >> y[i];
    }
    int l, w;
    for (int i = 0; i < 4; i++){
        for (int j = i+1; j < 4; j++){
            if (x[i] == x[j]) l = abs(y[i]-y[j]);
            if (y[i] == y[j]) w = abs(x[i]-x[j]);
        }
    }
    cout << l * w << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
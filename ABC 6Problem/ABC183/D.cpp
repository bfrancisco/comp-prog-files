#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll dif[200005];
    for (int i = 0; i < 200005; i++) dif[i] = 0;
    int n; ll w;
    cin >> n >> w;
    int mxt = 0;
    for (int i = 0; i < n; i++){
        int s, t; ll p;
        cin >> s >> t >> p;
        dif[s] += p;
        dif[t] -= p;
        mxt = max(mxt, t);
    }

    for (int i = 0; i <= mxt; i++){
        // cout << dif[i] << endl;
        if (dif[i] > w){
            cout << "No" << endl;
            // cout << i << endl;
            // cout << dif[i] << endl;
            return 0;
        }
        dif[i+1] += dif[i];
        
    }

    cout << "Yes" << endl;
    return 0;
}
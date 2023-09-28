#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, l, p; cin >> n >> l >> p;
    int mxd = 0;
    vector<int> trains(n, 0);
    for (int i = 0; i < p; i++){
        int x; cin >> x;
        int q = x / l;
        int m = x % l;
        if (q >= n){
            trains[n-1]++;
            mxd = max(mxd, x - ((n*l) - (l/2)));
        }
        if (m == 0){
            trains[q]++;
            mxd = max(mxd, (l/2));
        }
        else if (m >= l/2){
            trains[q]++;
            mxd = max(mxd, m - (l/2));
        }
        else if (m < l/2){
            trains[q]++;
            mxd = max(mxd, (l/2) - m);
        }
    }
    
    cout << mxd << endl;
    int mxx = 0;
    for (int i = 0; i < n; i++)
        mxx = max(trains[i], mxx);
    cout << mxx << endl;
    return 0;
}
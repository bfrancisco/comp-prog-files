#include<bits/stdc++.h>
using namespace std;

using ll = long long int;

int main(){

    int n; cin >> n;

    if (n == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    vector<ll> b(n+1);
    b[0] = 0;
    for (int i = 1; i <= n; i++){
        b[i] = a[i-1] + b[i-1];
    }

    for (auto x : a) cout << x << " "; cout << endl;
    for (auto x : b) cout << x << " "; cout << endl;

    for (int i = n-1; i > 0; i--){
        ll right = b[n] - b[i];
        int l = 0;
        int r = i-1;
        while (true){
            int m = (r+l) / 2;
            if (a[i] + b[r] - b[l] > right){
                l = m;
            }
            else{
                while(a[i] + b[r] - b[l] <= right){
                    l--;
                }
            }
        }

        if ()
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0, r = n-1;
    int ans = 0;
    while (l < r){
        while (l < r && a[r] > 1){
            int toSub = min(a[l], (int)(a[r]/2));
            a[l] -= toSub;
            ans += toSub;
            a[r] -= toSub*2;
            if (a[l] == 0) l++;
        }
        r--;
    }

    // for (auto e : a) cout << e << " "; cout << endl; cout << endl;

    sort(a.begin(), a.end());
    int ones = 0;
    // int z = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 1) ones++;
        // if (a[i] == 0) z++;
    }

    // if (a[n-1] > 1) assert(ones+z == n-1);
    // else assert(ones+z == n);

    if (a[n-1] > 1){
        int toSub = min((int)a[n-1]/2, ones);
        a[n-1] -= toSub*2;
        ones -= toSub;
        ans += toSub;
        if (a[n-1] == 1) ones++;
    }

    ans += (int)(ones/3);

    // for (auto e : a) cout << e << " "; cout << endl;


    cout << ans << endl;



    return 0;
}
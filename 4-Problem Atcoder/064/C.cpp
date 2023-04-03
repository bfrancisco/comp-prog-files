#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int a[9];
    for (int i = 0; i < 9; i++) a[i] = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x < 400) a[0]++;
        else if (x < 800) a[1]++;
        else if (x < 1200) a[2]++;
        else if (x < 1600) a[3]++;
        else if (x < 2000) a[4]++;
        else if (x < 2400) a[5]++;
        else if (x < 2800) a[6]++;
        else if (x < 3200) a[7]++;
        else a[8]++;
    }
    
    int sm = 0;
    for (int i = 0; i < 8; i++){
        // cout << a[i] << " ";
        if (a[i] > 0)
            sm++;
    }
    // cout << endl;
    int mn, mx;
    // cout << sm << endl;
    mx = sm+a[8];

    if (sm == 0 && a[8]) mn = 1;
    else mn = sm;
    
    cout << mn << " " << mx;


    
    return 0;
}   
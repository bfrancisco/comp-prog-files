#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());


    int dif = 1e9+10;
    int ans = -1;

    for (int i = 0; i < n-1; i++){
        if (abs(a[i]*2 - a[n-1]) < dif){
            dif = abs(a[i]*2 - a[n-1]);
            ans = a[i];
        }
    }
    cout << a[n-1] << " " << ans << endl;
    

    return 0;
}
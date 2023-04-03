#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int a[101];

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);
    
    int q = 0, w = 0;
    int c = 1;
    for (int i = n-1; i >= 0; i--){
        if (c) q += a[i];
        else w += a[i];
        c = 1 - c; 
    }

    cout << q-w;

    return 0;
}
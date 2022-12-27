#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a[3], k;
    cin >> a[0] >> a[1] >> a[2] >> k;
    sort(a, a+3);
    int ans = a[0] + a[1];
    while (k--)
        a[2] *= 2;
    ans += a[2];
    cout << ans;
}